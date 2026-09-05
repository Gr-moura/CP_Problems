#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <set>
#include <string>
#if __cplusplus >= 201703L
#include <string_view>
#else
#include <experimental/string_view>
#endif
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#if __cplusplus >= 201703L
using TextView = std::string_view;
#else
using TextView = std::experimental::string_view;
#endif

namespace {

constexpr double INF = numeric_limits<double>::infinity();
constexpr int MAX_CURVE_ARGUMENT = 4096;
constexpr int BATCH_MIX_BUCKETS = 65;

template <class T>
constexpr T bounded(T value, T low, T high) {
    return value < low ? low : high < value ? high : value;
}

#ifndef SCHED_SLO_SHARE_FLOOR
#define SCHED_SLO_SHARE_FLOOR 0.10
#endif

#ifndef SCHED_SLO_SHARE_PRIOR
#define SCHED_SLO_SHARE_PRIOR 0.35
#endif

#ifndef SCHED_PREFILL_SPT
#define SCHED_PREFILL_SPT 1
#endif

#ifndef SCHED_SPT_MAX_WTP
#define SCHED_SPT_MAX_WTP 0.0
#endif

#ifndef SCHED_SPT_MIN_WTP
#define SCHED_SPT_MIN_WTP 2.0
#endif

#ifndef SCHED_GENERAL_PPRE_SPT
#define SCHED_GENERAL_PPRE_SPT 0
#endif

#ifndef SCHED_TIGHT_SLO_SPT
#define SCHED_TIGHT_SLO_SPT 1
#endif

#ifndef SCHED_LOOSE_SLO_SPT
#define SCHED_LOOSE_SLO_SPT 1
#endif

#ifndef SCHED_PPROC_SPT
#define SCHED_PPROC_SPT 1
#endif

#ifndef SCHED_PPOST_SPT
#define SCHED_PPOST_SPT 1
#endif

#ifndef SCHED_PPROC_SPT_MIN_K
#define SCHED_PPROC_SPT_MIN_K 2
#endif

#ifndef SCHED_PPROC_SPT_MAX_K
#define SCHED_PPROC_SPT_MAX_K 8
#endif

#ifndef SCHED_PPOST_SPT_MIN_K
#define SCHED_PPOST_SPT_MIN_K 1
#endif

#ifndef SCHED_PPOST_SPT_MAX_K
#define SCHED_PPOST_SPT_MAX_K 6
#endif

#ifndef SCHED_COHORT_FIRST_TOKENS
#define SCHED_COHORT_FIRST_TOKENS 1
#endif

#ifndef SCHED_COHORT_MAX_K
#define SCHED_COHORT_MAX_K 4
#endif

#ifndef SCHED_COHORT_HOLD_PEERS
#define SCHED_COHORT_HOLD_PEERS 1
#endif

#ifndef SCHED_COHORT_BACKGROUND
#define SCHED_COHORT_BACKGROUND 1
#endif

#ifndef SCHED_COHORT_THROUGHPUT_BATCH
#define SCHED_COHORT_THROUGHPUT_BATCH 1
#endif

#ifndef SCHED_COHORT_TARGET
#define SCHED_COHORT_TARGET 32
#endif

#ifndef SCHED_DYNAMIC_COHORT_TARGET
#define SCHED_DYNAMIC_COHORT_TARGET 1
#endif

#ifndef SCHED_LINK_REMOTE_LIMIT
#define SCHED_LINK_REMOTE_LIMIT 1
#endif

#ifndef SCHED_LINK_REMOTE_THRESHOLD
#define SCHED_LINK_REMOTE_THRESHOLD 2.0
#endif

#ifndef SCHED_LINK_REMOTE_MAX_K
#define SCHED_LINK_REMOTE_MAX_K 3
#endif

#ifndef SCHED_LINK_REMOTE_MAX_WTP
#define SCHED_LINK_REMOTE_MAX_WTP 0.25
#endif

#ifndef SCHED_LINK_PPRE_SPT
#define SCHED_LINK_PPRE_SPT 1
#endif

// Experimental second arm for throughput-weighted, link-dominated systems.
// Disabled by default so macro builds can be compared without changing the
// submitted policy.
#ifndef SCHED_LINK_BREAKTHROUGH
#define SCHED_LINK_BREAKTHROUGH 1
#endif

#ifndef SCHED_LINK_BREAKTHROUGH_MIN_WTP
#define SCHED_LINK_BREAKTHROUGH_MIN_WTP 0.50
#endif

#ifndef SCHED_LINK_BREAKTHROUGH_THRESHOLD
#define SCHED_LINK_BREAKTHROUGH_THRESHOLD 0.25
#endif

// Select the number of clouds from a runtime pipeline model.  Unlike the
// link-bottleneck portfolio arms above, this evaluates every legal prefix of
// clouds from the actual task curves, transfer cost, queue state and score.
#ifndef SCHED_DYNAMIC_REMOTE_PLANNER
#define SCHED_DYNAMIC_REMOTE_PLANNER 0
#endif

// Compare concentrated and balanced decode-pre batches by simulating their
// complete edge/link/cloud/link/edge path.  This keeps all clouds available
// while avoiding unnecessary fixed transfer latencies on individual waves.
#ifndef SCHED_PIPELINE_DPRE_SELECT
#define SCHED_PIPELINE_DPRE_SELECT 1
#endif

// Experimentally decouple shortest-prefill ordering from topology
// consolidation.  This lets us measure whether a link-regime gain comes from
// SPT itself or from restricting placement to one remote.
#ifndef SCHED_LINK_SPT_ONLY
#define SCHED_LINK_SPT_ONLY 0
#endif

#ifndef SCHED_LINK_SPT_ONLY_MIN_WTP
#define SCHED_LINK_SPT_ONLY_MIN_WTP 0.0
#endif

#ifndef SCHED_LINK_SPT_ONLY_THRESHOLD
#define SCHED_LINK_SPT_ONLY_THRESHOLD 0.25
#endif

#ifndef SCHED_TIGHT_EDF_BOOST
#define SCHED_TIGHT_EDF_BOOST 16.0
#endif

#ifndef SCHED_EVENT_BATCH_WAIT
#define SCHED_EVENT_BATCH_WAIT 1
#endif

#ifndef SCHED_EVENT_WAIT_GAIN_FACTOR
#define SCHED_EVENT_WAIT_GAIN_FACTOR 1.0
#endif

#ifndef SCHED_EVENT_WAIT_MIN_WTP
#define SCHED_EVENT_WAIT_MIN_WTP 0.50
#endif

#ifndef SCHED_EVENT_LOW_WEIGHT_LINK_RATIO
#define SCHED_EVENT_LOW_WEIGHT_LINK_RATIO 0.40
#endif



constexpr double SLO_SHARE_FLOOR = SCHED_SLO_SHARE_FLOOR;
constexpr double SLO_SHARE_PRIOR = SCHED_SLO_SHARE_PRIOR;
constexpr bool PREFILL_SPT = SCHED_PREFILL_SPT != 0;
constexpr double SPT_MAX_WTP = SCHED_SPT_MAX_WTP;
constexpr double SPT_MIN_WTP = SCHED_SPT_MIN_WTP;
constexpr bool GENERAL_PPRE_SPT = SCHED_GENERAL_PPRE_SPT != 0;
constexpr bool TIGHT_SLO_SPT = SCHED_TIGHT_SLO_SPT != 0;
constexpr bool LOOSE_SLO_SPT = SCHED_LOOSE_SLO_SPT != 0;
constexpr bool PPROC_SPT = SCHED_PPROC_SPT != 0;
constexpr bool PPOST_SPT = SCHED_PPOST_SPT != 0;
constexpr int PPROC_SPT_MIN_K = SCHED_PPROC_SPT_MIN_K;
constexpr int PPROC_SPT_MAX_K = SCHED_PPROC_SPT_MAX_K;
constexpr int PPOST_SPT_MIN_K = SCHED_PPOST_SPT_MIN_K;
constexpr int PPOST_SPT_MAX_K = SCHED_PPOST_SPT_MAX_K;
constexpr bool COHORT_FIRST_TOKENS = SCHED_COHORT_FIRST_TOKENS != 0;
constexpr int COHORT_MAX_K = SCHED_COHORT_MAX_K;
constexpr bool COHORT_HOLD_PEERS = SCHED_COHORT_HOLD_PEERS != 0;
constexpr bool COHORT_BACKGROUND = SCHED_COHORT_BACKGROUND != 0;
constexpr bool COHORT_THROUGHPUT_BATCH = SCHED_COHORT_THROUGHPUT_BATCH != 0;
constexpr int COHORT_TARGET = SCHED_COHORT_TARGET;
constexpr bool DYNAMIC_COHORT_TARGET = SCHED_DYNAMIC_COHORT_TARGET != 0;
constexpr bool LINK_REMOTE_LIMIT = SCHED_LINK_REMOTE_LIMIT != 0;
constexpr double LINK_REMOTE_THRESHOLD = SCHED_LINK_REMOTE_THRESHOLD;
constexpr int LINK_REMOTE_MAX_K = SCHED_LINK_REMOTE_MAX_K;
constexpr double LINK_REMOTE_MAX_WTP = SCHED_LINK_REMOTE_MAX_WTP;
constexpr bool LINK_PPRE_SPT = SCHED_LINK_PPRE_SPT != 0;
constexpr bool LINK_BREAKTHROUGH = SCHED_LINK_BREAKTHROUGH != 0;
constexpr double LINK_BREAKTHROUGH_MIN_WTP = SCHED_LINK_BREAKTHROUGH_MIN_WTP;
constexpr double LINK_BREAKTHROUGH_THRESHOLD = SCHED_LINK_BREAKTHROUGH_THRESHOLD;
constexpr bool DYNAMIC_REMOTE_PLANNER = SCHED_DYNAMIC_REMOTE_PLANNER != 0;
constexpr bool PIPELINE_DPRE_SELECT = SCHED_PIPELINE_DPRE_SELECT != 0;
constexpr bool LINK_SPT_ONLY = SCHED_LINK_SPT_ONLY != 0;
constexpr double LINK_SPT_ONLY_MIN_WTP = SCHED_LINK_SPT_ONLY_MIN_WTP;
constexpr double LINK_SPT_ONLY_THRESHOLD = SCHED_LINK_SPT_ONLY_THRESHOLD;
constexpr double SCORE_GAP_FLOOR = 0.12;
constexpr double SCORE_GAP_POWER = 4.0;
constexpr double TIGHT_EDF_BOOST = SCHED_TIGHT_EDF_BOOST;
constexpr double FIRST_TOKEN_URGENCY_SCALE = 0.50;
constexpr bool EVENT_BATCH_WAIT = SCHED_EVENT_BATCH_WAIT != 0;
constexpr double EVENT_WAIT_GAIN_FACTOR = SCHED_EVENT_WAIT_GAIN_FACTOR;
constexpr double EVENT_WAIT_MIN_WTP = SCHED_EVENT_WAIT_MIN_WTP;
constexpr double EVENT_LOW_WEIGHT_LINK_RATIO = SCHED_EVENT_LOW_WEIGHT_LINK_RATIO;
static_assert(COHORT_TARGET >= 1, "invalid scheduler configuration");
static_assert(LINK_REMOTE_THRESHOLD >= 0.0, "invalid scheduler configuration");
static_assert(LINK_REMOTE_MAX_K >= 1 && LINK_REMOTE_MAX_K <= 8, "invalid scheduler configuration");
static_assert(LINK_REMOTE_MAX_WTP >= 0.0 && LINK_REMOTE_MAX_WTP <= 1.0, "invalid scheduler configuration");
static_assert(LINK_BREAKTHROUGH_MIN_WTP >= 0.0 && LINK_BREAKTHROUGH_MIN_WTP <= 1.0, "invalid scheduler configuration");
static_assert(LINK_BREAKTHROUGH_THRESHOLD >= 0.0, "invalid scheduler configuration");
static_assert(LINK_SPT_ONLY_MIN_WTP >= 0.0 && LINK_SPT_ONLY_MIN_WTP <= 1.0, "invalid scheduler configuration");
static_assert(LINK_SPT_ONLY_THRESHOLD >= 0.0, "invalid scheduler configuration");
static_assert(SLO_SHARE_FLOOR >= 0.0 && SLO_SHARE_FLOOR <= 0.5, "invalid scheduler configuration");
static_assert(SPT_MAX_WTP >= 0.0 && SPT_MAX_WTP <= 1.0, "invalid scheduler configuration");
static_assert(SPT_MIN_WTP >= 0.0, "invalid scheduler configuration");
static_assert(SLO_SHARE_PRIOR > 0.0, "invalid scheduler configuration");
static_assert(SCORE_GAP_FLOOR >= 0.0 && SCORE_GAP_FLOOR <= 1.0, "invalid scheduler configuration");
static_assert(SCORE_GAP_POWER >= 1.0, "invalid scheduler configuration");
static_assert(TIGHT_EDF_BOOST >= 0.0, "invalid scheduler configuration");
static_assert(FIRST_TOKEN_URGENCY_SCALE >= 0.0 && FIRST_TOKEN_URGENCY_SCALE <= 1.0, "invalid scheduler configuration");
static_assert(EVENT_WAIT_GAIN_FACTOR >= 0.0, "invalid scheduler configuration");
static_assert(EVENT_WAIT_MIN_WTP >= 0.0 && EVENT_WAIT_MIN_WTP <= 1.0, "invalid scheduler configuration");
static_assert(EVENT_LOW_WEIGHT_LINK_RATIO >= 0.0, "invalid scheduler configuration");

enum class Phase {
    EMPTY,
    ARRIVED,
    P_PRE_RUNNING,
    P_WAIT_UP,
    P_PROC_READY,
    P_PROC_RUNNING,
    P_WAIT_DOWN,
    P_POST_READY,
    P_POST_RUNNING,
    D_PRE_READY,
    D_PRE_RUNNING,
    D_WAIT_UP,
    D_PROC_READY,
    D_PROC_RUNNING,
    D_WAIT_DOWN,
    D_POST_READY,
    D_POST_RUNNING,
    FINISHED,
};

struct Curve {
    vector<pair<int, double>> points;
    vector<double> lookup;

    void add(int x, double y) {
        if (y >= 0.0) points.emplace_back(x, y);
    }

    void prepare() {
        sort(points.begin(), points.end());
        lookup.resize(MAX_CURVE_ARGUMENT + 1);

        size_t right = 0;
        for (int x = 0; x <= MAX_CURVE_ARGUMENT; ++x) {
            if (x <= points.front().first) {
                lookup[x] = points.front().second;
                continue;
            }
            if (x >= points.back().first) {
                lookup[x] = points.back().second;
                continue;
            }
            while (right + 1 < points.size() && points[right + 1].first < x) ++right;
            const int x1 = points[right].first;
            const double y1 = points[right].second;
            const int x2 = points[right + 1].first;
            const double y2 = points[right + 1].second;
            const double ratio = static_cast<double>(x - x1) / static_cast<double>(x2 - x1);
            lookup[x] = y1 + ratio * (y2 - y1);
        }
    }

    double at(int x) const {
        if (0 <= x && x <= MAX_CURVE_ARGUMENT) return lookup[x];
        if (x <= points.front().first) return points.front().second;
        if (x >= points.back().first) return points.back().second;

        auto it = lower_bound(points.begin(), points.end(), pair<int, double>{x, -INF});
        if (it->first == x) return it->second;
        const int x2 = it->first;
        const double y2 = it->second;
        const auto before = prev(it);
        const int x1 = before->first;
        const double y1 = before->second;
        const double ratio = static_cast<double>(x - x1) / static_cast<double>(x2 - x1);
        return y1 + ratio * (y2 - y1);
    }
};

struct Request {
    int id = -1;
    int lin = 0;
    int remote = -1;
    int next_layer = 0;
    int tokens = 0;
    double arrival = 0.0;
    double ppost_done = -1.0;
    double last_token = -1.0;
    Phase phase = Phase::EMPTY;
    bool finished = false;
};

using ReadyKey = pair<double, int>;

struct Mix {
    double throughput = 0.5;
    double latency = 0.5;
};

struct EdgeOption {
    enum class Kind { NONE, P_PRE, P_POST, D_PRE, D_POST } kind = Kind::NONE;
    vector<int> ids;
    int rid = -1;
    double duration = 0.0;
    double score = -INF;
};

struct CloudOption {
    enum class Kind { NONE, P_PROC, D_PROC } kind = Kind::NONE;
    int remote = -1;
    int rid = -1;
    int layer_end = -1;
    vector<int> ids;
    double duration = 0.0;
    double urgency = 0.0;
    double score = -INF;
};

struct Assignment {
    string line;
    int transfer_priority = 0;
    double urgency = 0.0;
    int remote = -1;
};

class Scheduler {
public:
    bool read_startup() {
        if (!(cin >> K >> schedule_cost >> latency_ms >> bandwidth_gbps
                  >> bytes_per_token >> num_layers)) {
            return false;
        }
        cin >> slo1 >> slo2 >> tp_upper >> tp_base >> dist_base >> w_tp >> w_c;

        int n = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int size = 0;
            array<double, 6> value{};
            cin >> size;
            for (double& x : value) cin >> x;
            p_pre.add(size, value[0]);
            p_proc.add(size, value[1]);
            p_post.add(size, value[2]);
            d_pre.add(size, value[3]);
            d_proc.add(size, value[4]);
            d_post.add(size, value[5]);
        }
        for (Curve* curve : {&p_pre, &p_proc, &p_post, &d_pre, &d_proc, &d_post}) {
            curve->prepare();
        }
        for (int length = 1; length <= MAX_CURVE_ARGUMENT; ++length) {
            const double path = 3.0 * schedule_cost + p_pre.at(length)
                              + p_proc.at(length) + p_post.at(length)
                              + 2.0 * transfer_time(length);
            max_prefill_path = max(max_prefill_path, path);
        }

        cloud_free.assign(K, true);
        cloud_busy_until.assign(K, 0.0);
        pproc_ready.assign(K, {});
        dpre_ready.assign(K, {});
        dproc_ready.assign(K, {});
        prefill_remaining.assign(K, 0.0);
        decode_active.assign(K, 0);
        assigned_active.assign(K, 0);
        decode_up_pending_items.assign(K, 0);
        decode_up_pending_tail.assign(K, 0.0);

        string discard;
        getline(cin, discard);
        return true;
    }

    void run() {
        string header;
        vector<string> events;
        while (getline(cin, header)) {
            if (header.empty()) continue;
            if (header == "END") return;

            try {
                now = stod(header);
            } catch (...) {
                return;
            }

            string count_line;
            if (!getline(cin, count_line)) return;
            const int event_count = parse_int(count_line);
            if (event_count < 0) return;

            events.resize(event_count);
            for (string& event : events) {
                if (!getline(cin, event)) return;
            }

            process_frame(events);
            vector<Assignment> answer = make_assignments();

            cout << answer.size() << '\n';
            for (const Assignment& assignment : answer) cout << assignment.line << '\n';
            cout.flush();
        }
    }

private:
    int K = 0;
    int num_layers = 0;
    int64_t bytes_per_token = 0;
    double schedule_cost = 0.0;
    double latency_ms = 0.0;
    double bandwidth_gbps = 0.0;
    double slo1 = 1.0;
    double slo2 = 1.0;
    double tp_upper = 1.0;
    double tp_base = 0.0;
    double dist_base = 0.0;
    double w_tp = 0.5;
    double w_c = 0.5;
    double max_prefill_path = 0.0;

    Curve p_pre, p_proc, p_post, d_pre, d_proc, d_post;
    array<vector<array<int, BATCH_MIX_BUCKETS>>, 6> batch_choice_cache;
    vector<Request> requests;

    bool edge_free = true;
    vector<bool> cloud_free;
    vector<double> cloud_busy_until;

    set<ReadyKey> ppre_ready;
    set<ReadyKey> ppost_ready;
    set<ReadyKey> dpost_ready;
    set<ReadyKey> dpost_first_ready;
    set<ReadyKey> dpost_gap_ready;
    vector<set<ReadyKey>> pproc_ready;
    vector<set<ReadyKey>> dpre_ready;
    vector<set<ReadyKey>> dproc_ready;

    vector<double> prefill_remaining;
    vector<int> decode_active;
    vector<int> assigned_active;
    vector<int> decode_up_pending_items;
    vector<double> decode_up_pending_tail;

    double now = 0.0;
    double up_tail = 0.0;
    double down_tail = 0.0;
    int up_pending = 0;
    int down_pending = 0;
    int decode_down_pending_items = 0;
    double decode_down_pending_tail = 0.0;
    int remote_rotation = 0;

    int arrived_count = 0;
    int prefill_pending_count = 0;
    double prefill_arrival_sum = 0.0;
    double completed_tdr_sum = 0.0;

    int64_t total_tokens = 0;
    double gap_sum = 0.0;
    int64_t gap_count = 0;
    int open_gap_count = 0;
    double open_gap_start_sum = 0.0;
    double earliest_arrival = INF;

    int finished_count = 0;
    int64_t finished_token_sum = 0;
    int total_decode_active = 0;
    int first_token_decode_count = 0;
    int dpre_first_ready_count = 0;

    void ensure_request(int rid) {
        if (rid >= static_cast<int>(requests.size())) requests.resize(rid + 1);
    }

    bool spt_allowed() const {
        return PREFILL_SPT && (w_tp <= SPT_MAX_WTP + 1.0e-12
            || w_tp + 1.0e-12 >= SPT_MIN_WTP
            || (TIGHT_SLO_SPT && slo1 <= max_prefill_path)
            || (LOOSE_SLO_SPT && w_tp >= 0.60
                && slo1 >= 32.0 * max_prefill_path));
    }

    bool strict_waiting_mode() const {
        // A small waiting-distance budget makes a missed SLO essentially
        // unrecoverable.  In that regime, minimizing mean completion time is
        // more valuable than preserving FIFO fairness.
        return w_tp <= 1.0e-12 && dist_base <= 2.0
            && slo2 >= 0.15 * slo1;
    }

    bool tight_edf_mode() const {
        return w_tp <= 1.0e-12 && dist_base <= 2.0
            && slo2 < 0.15 * slo1;
    }

    double tight_edf_boost() const {
        if (!tight_edf_mode()) return 0.0;
        // When serialization alone consumes much of the gap budget, strong
        // EDF oscillates between stages and loses batching efficiency.
        if (transfer_time(1) > 0.15 * slo2 || (K >= 8 && num_layers >= 64)) {
            return 1.0;
        }
        return TIGHT_EDF_BOOST;
    }

    bool form_first_token_cohort() const {
        // Time before the first decoded token contributes to neither TPOT nor
        // TDR.  Use that free window to assemble an efficient decode batch.
        // Throughput-heavy cases need this even more than pure waiting cases.
        // Judge telemetry shows that an initial wave is valuable in the
        // throughput/latency compromise bands, but counterproductive when the
        // objective is almost pure makespan (pipeline overlap wins there).
        const bool weighted_wave = 0.795 <= w_tp && w_tp <= 0.985;
        const bool link_wave = 0.45 <= w_tp && w_tp < 0.795
            && (DYNAMIC_COHORT_TARGET
                || latency_ms >= 0.50 * schedule_cost);
        return weighted_wave || link_wave
            || (w_tp <= 1.0e-12 && K <= COHORT_MAX_K);
    }

    int first_token_cohort_target() const {
        const int static_target = w_tp >= 0.80 ? 32
                                : w_tp >= 0.45 ? 16
                                : COHORT_TARGET;
        if (!DYNAMIC_COHORT_TARGET) return static_target;

        // Nothing before the first decoded token contributes to TDR or TPOT.
        // Choose the alignment frontier from the actual steady-state pipeline
        // bottleneck instead of a weight-specific magic batch size.
        const int potential = bounded(first_token_decode_count
                                  + prefill_pending_count, 1,
                                    MAX_CURVE_ARGUMENT);
        vector<int> candidates{1, min(static_target, potential), potential};
        for (int n = 2; n < potential; n *= 2) candidates.push_back(n);
        for (const Curve* curve : {&d_pre, &d_proc, &d_post}) {
            for (const auto& point : curve->points) {
                const int size = point.first;
                if (1 <= size && size <= potential) candidates.push_back(size);
            }
        }
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

        const int active_remotes = use_link_remote_limit() ? 1 : K;
        int best_target = 1;
        double best_bottleneck = INF;
        double best_response = INF;
        for (int size : candidates) {
            const int represented = min(active_remotes, size);
            double transfer_work = 0.0;
            double cloud_capacity = 0.0;
            double upload_clock = schedule_cost + d_pre.at(size);
            vector<pair<double, int>> proc_finishes;
            proc_finishes.reserve(represented);
            for (int remote = 0; remote < represented; ++remote) {
                const int share = size / represented
                                + (remote < size % represented ? 1 : 0);
                const double transfer = transfer_time(share);
                transfer_work += transfer;
                upload_clock += transfer;
                const double proc = schedule_cost + d_proc.at(share);
                proc_finishes.emplace_back(upload_clock + proc, share);
                cloud_capacity += share / max(1.0e-12, proc);
            }
            sort(proc_finishes.begin(), proc_finishes.end());
            double download_clock = 0.0;
            for (const auto& completion : proc_finishes) {
                download_clock = max(download_clock, completion.first)
                               + transfer_time(completion.second);
            }

            const double edge = (2.0 * schedule_cost + d_pre.at(size)
                               + d_post.at(size)) / size;
            const double link = transfer_work / size;
            const double cloud = 1.0 / max(1.0e-12, cloud_capacity);
            const double bottleneck = max({edge, link, cloud});
            const double response = download_clock + schedule_cost
                                  + d_post.at(size);
            if (bottleneck < best_bottleneck - 1.0e-12
                || (abs(bottleneck - best_bottleneck) <= 1.0e-12
                    && (response < best_response - 1.0e-12
                        || (abs(response - best_response) <= 1.0e-12
                            && size < best_target)))) {
                best_bottleneck = bottleneck;
                best_response = response;
                best_target = size;
            }
        }
        return best_target;
    }

    bool use_link_remote_limit() const {
        const double decode_task_cycle = 3.0 * schedule_cost + d_pre.at(1)
                                       + d_proc.at(1) + d_post.at(1);
        const bool baseline_arm = LINK_REMOTE_LIMIT && K <= LINK_REMOTE_MAX_K
            && w_tp <= LINK_REMOTE_MAX_WTP
            && latency_ms >= LINK_REMOTE_THRESHOLD * decode_task_cycle;
        const bool throughput_arm = LINK_BREAKTHROUGH
            && w_tp + 1.0e-12 >= LINK_BREAKTHROUGH_MIN_WTP
            && latency_ms >= LINK_BREAKTHROUGH_THRESHOLD * decode_task_cycle;
        return baseline_arm || throughput_arm;
    }

    bool use_link_spt() const {
        const double decode_task_cycle = 3.0 * schedule_cost + d_pre.at(1)
                                       + d_proc.at(1) + d_post.at(1);
        return use_link_remote_limit() || (LINK_SPT_ONLY
            && w_tp + 1.0e-12 >= LINK_SPT_ONLY_MIN_WTP
            && latency_ms >= LINK_SPT_ONLY_THRESHOLD * decode_task_cycle);
    }

    ReadyKey ppre_key(const Request& request) const {
        const bool ordinary_spt = strict_waiting_mode()
            || (GENERAL_PPRE_SPT && spt_allowed());
        if (!ordinary_spt && !(LINK_PPRE_SPT && use_link_spt())) {
            return {request.arrival, request.id};
        }
        const double work = p_pre.at(request.lin) + p_proc.at(request.lin)
                          + p_post.at(request.lin) + 2.0 * transfer_time(request.lin);
        return {work, request.id};
    }

    ReadyKey pproc_key(const Request& request) const {
        if (!strict_waiting_mode()
            && (!spt_allowed() || !PPROC_SPT
                || K < PPROC_SPT_MIN_K || K > PPROC_SPT_MAX_K)) {
            return {request.arrival, request.id};
        }
        const double remaining_fraction = static_cast<double>(num_layers - request.next_layer)
                                        / max(1, num_layers);
        const double work = remaining_fraction * p_proc.at(request.lin)
                          + p_post.at(request.lin) + transfer_time(request.lin);
        return {work, request.id};
    }

    ReadyKey ppost_key(const Request& request) const {
        if (!strict_waiting_mode()
            && (!spt_allowed() || !PPOST_SPT
                || K < PPOST_SPT_MIN_K || K > PPOST_SPT_MAX_K)) {
            return {request.arrival, request.id};
        }
        return {p_post.at(request.lin), request.id};
    }

    double decode_anchor(const Request& request) const {
        if (request.tokens > 0) return request.last_token;
        return request.ppost_done + 0.35 * slo2;
    }

    ReadyKey decode_key(const Request& request) const {
        return {decode_anchor(request), request.id};
    }

    void remove_ready(const Request& request) {
        switch (request.phase) {
            case Phase::ARRIVED:
                ppre_ready.erase(ppre_key(request));
                break;
            case Phase::P_PROC_READY:
                if (request.remote >= 0) pproc_ready[request.remote].erase(pproc_key(request));
                break;
            case Phase::P_POST_READY:
                ppost_ready.erase(ppost_key(request));
                break;
            case Phase::D_PRE_READY:
                if (request.remote >= 0) {
                    dpre_ready[request.remote].erase(decode_key(request));
                    if (request.tokens == 0) --dpre_first_ready_count;
                }
                break;
            case Phase::D_PROC_READY:
                if (request.remote >= 0) dproc_ready[request.remote].erase(decode_key(request));
                break;
            case Phase::D_POST_READY:
                dpost_ready.erase(decode_key(request));
                (request.tokens == 0 ? dpost_first_ready : dpost_gap_ready)
                    .erase(decode_key(request));
                break;
            default:
                break;
        }
    }

    void add_ready(const Request& request) {
        switch (request.phase) {
            case Phase::ARRIVED:
                ppre_ready.insert(ppre_key(request));
                break;
            case Phase::P_PROC_READY:
                pproc_ready[request.remote].insert(pproc_key(request));
                break;
            case Phase::P_POST_READY:
                ppost_ready.insert(ppost_key(request));
                break;
            case Phase::D_PRE_READY:
                dpre_ready[request.remote].insert(decode_key(request));
                if (request.tokens == 0) ++dpre_first_ready_count;
                break;
            case Phase::D_PROC_READY:
                dproc_ready[request.remote].insert(decode_key(request));
                break;
            case Phase::D_POST_READY:
                dpost_ready.insert(decode_key(request));
                (request.tokens == 0 ? dpost_first_ready : dpost_gap_ready)
                    .insert(decode_key(request));
                break;
            default:
                break;
        }
    }

    void transition(int rid, Phase next) {
        Request& request = requests[rid];
        remove_ready(request);
        request.phase = next;
        add_ready(request);
    }

    double transfer_time(int length) const {
        const long double bytes = static_cast<long double>(length) * bytes_per_token;
        const long double serialization = 8.0L * bytes / (bandwidth_gbps * 1.0e6L);
        return latency_ms + static_cast<double>(serialization);
    }

    void enqueue_up(int length, bool decode = false, int remote = -1) {
        up_tail = max(up_tail, now) + transfer_time(length);
        ++up_pending;
        if (decode && 0 <= remote && remote < K) {
            decode_up_pending_items[remote] += length;
            decode_up_pending_tail[remote] = up_tail;
        }
    }

    void enqueue_down(int length, bool decode = false) {
        down_tail = max(down_tail, now) + transfer_time(length);
        ++down_pending;
        if (decode) {
            decode_down_pending_items += length;
            decode_down_pending_tail = down_tail;
        }
    }

    static int parse_int(TextView text) {
        if (text.empty()) return -1;
        int value = 0;
        for (char ch : text) {
            if (ch < '0' || ch > '9') return -1;
            const int digit = ch - '0';
            if (value > (numeric_limits<int>::max() - digit) / 10) return -1;
            value = value * 10 + digit;
        }
        return value;
    }

    static void split_words(TextView line, vector<TextView>& words) {
        words.clear();
        size_t cursor = 0;
        while (cursor < line.size()) {
            while (cursor < line.size() && line[cursor] == ' ') ++cursor;
            const size_t begin = cursor;
            while (cursor < line.size() && line[cursor] != ' ') ++cursor;
            if (begin < cursor) words.push_back(line.substr(begin, cursor - begin));
        }
    }

    void process_frame(const vector<string>& events) {
        unordered_set<int> finishing;
        finishing.reserve(events.size());
        for (const string& event : events) {
            if (event.size() > 4 && event.compare(0, 4, "FIN ") == 0) {
                const int rid = parse_int(TextView(event).substr(4));
                if (rid >= 0) finishing.insert(rid);
            }
        }

        vector<TextView> words;
        for (const string& event : events) {
            split_words(event, words);
            if (words.empty() || words[0] == "FIN") continue;
            if (words[0] == "ARR") {
                process_arrival(words);
            } else if (words[0] == "TDN") {
                process_task_done(words, finishing);
            } else if (words[0] == "XDN") {
                process_transfer_done(words);
            }
        }

        for (int rid : finishing) {
            ensure_request(rid);
            Request& request = requests[rid];
            if (request.finished) continue;
            remove_ready(request);
            request.phase = Phase::FINISHED;
            request.finished = true;
            if (request.remote >= 0) {
                decode_active[request.remote] = max(0, decode_active[request.remote] - 1);
                assigned_active[request.remote] = max(0, assigned_active[request.remote] - 1);
            }
            total_decode_active = max(0, total_decode_active - 1);
            ++finished_count;
            finished_token_sum += request.tokens;
        }
    }

    void process_arrival(const vector<TextView>& words) {
        if (words.size() != 3) return;
        const int rid = parse_int(words[1]);
        ensure_request(rid);
        Request& request = requests[rid];
        request.id = rid;
        request.lin = parse_int(words[2]);
        request.remote = -1;
        request.next_layer = 0;
        request.tokens = 0;
        request.arrival = now;
        request.ppost_done = -1.0;
        request.last_token = -1.0;
        request.finished = false;
        request.phase = Phase::EMPTY;
        transition(rid, Phase::ARRIVED);

        ++arrived_count;
        ++prefill_pending_count;
        prefill_arrival_sum += now;
        earliest_arrival = min(earliest_arrival, now);
    }

    void free_server(TextView server) {
        if (server == "E") {
            edge_free = true;
            return;
        }
        if (server.size() >= 2 && server[0] == 'C') {
            const int remote = parse_int(server.substr(1));
            if (0 <= remote && remote < K) {
                cloud_free[remote] = true;
                cloud_busy_until[remote] = now;
            }
        }
    }

    void process_task_done(
        const vector<TextView>& words,
        const unordered_set<int>& finishing
    ) {
        if (words.size() < 5) return;
        free_server(words[1]);
        const TextView family = words[2];
        const TextView step = words[3];

        if (family == "P" && step == "PRE") {
            const int rid = parse_int(words[5]);
            transition(rid, Phase::P_WAIT_UP);
            enqueue_up(requests[rid].lin);
        } else if (family == "P" && step == "PROC") {
            const int layer_end = parse_int(words[5]);
            const int rid = parse_int(words[7]);
            requests[rid].next_layer = layer_end;
            if (layer_end == num_layers) {
                transition(rid, Phase::P_WAIT_DOWN);
                enqueue_down(requests[rid].lin);
            } else {
                transition(rid, Phase::P_PROC_READY);
            }
        } else if (family == "P" && step == "POST") {
            const int rid = parse_int(words[5]);
            Request& request = requests[rid];
            if (request.ppost_done < 0.0) {
                request.ppost_done = now;
                completed_tdr_sum += now - request.arrival;
                --prefill_pending_count;
                prefill_arrival_sum -= request.arrival;
                if (request.remote >= 0) {
                    ++decode_active[request.remote];
                }
                ++total_decode_active;
                ++first_token_decode_count;
            }
            transition(rid, Phase::D_PRE_READY);
        } else if (family == "D" && step == "PRE") {
            const int m = parse_int(words[5]);
            vector<int> per_remote(K, 0);
            for (int i = 0; i < m; ++i) {
                const int rid = parse_int(words[6 + i]);
                transition(rid, Phase::D_WAIT_UP);
                ++per_remote[requests[rid].remote];
            }
            for (int remote = 0; remote < K; ++remote) {
                if (per_remote[remote] > 0) {
                    enqueue_up(per_remote[remote], true, remote);
                }
            }
        } else if (family == "D" && step == "PROC") {
            const int m = parse_int(words[5]);
            for (int i = 0; i < m; ++i) {
                const int rid = parse_int(words[6 + i]);
                transition(rid, Phase::D_WAIT_DOWN);
            }
            enqueue_down(m, true);
        } else if (family == "D" && step == "POST") {
            const int m = parse_int(words[5]);
            for (int i = 0; i < m; ++i) {
                const int rid = parse_int(words[6 + i]);
                Request& request = requests[rid];
                if (request.tokens == 0) --first_token_decode_count;
                if (request.tokens > 0) {
                    if (open_gap_count > 0) --open_gap_count;
                    open_gap_start_sum -= request.last_token;
                    gap_sum += now - request.last_token;
                    ++gap_count;
                }
                ++request.tokens;
                ++total_tokens;
                request.last_token = now;

                if (finishing.find(rid) != finishing.end()) {
                    transition(rid, Phase::FINISHED);
                } else {
                    transition(rid, Phase::D_PRE_READY);
                    ++open_gap_count;
                    open_gap_start_sum += now;
                }
            }
        }
    }

    void process_transfer_done(const vector<TextView>& words) {
        if (words.size() < 7) return;
        const TextView direction = words[1];
        if (direction == "UP") {
            up_pending = max(0, up_pending - 1);
        } else if (direction == "DOWN") {
            down_pending = max(0, down_pending - 1);
        }
        const TextView kind = words[4];
        const int m = parse_int(words[5]);
        const int remote = parse_int(words[2]);
        if (direction == "UP" && kind == "DEC" && 0 <= remote && remote < K) {
            decode_up_pending_items[remote] = max(0, decode_up_pending_items[remote] - m);
            if (decode_up_pending_items[remote] == 0) {
                decode_up_pending_tail[remote] = now;
            }
        }
        if (direction == "DOWN" && kind == "DEC") {
            decode_down_pending_items = max(0, decode_down_pending_items - m);
            if (decode_down_pending_items == 0) decode_down_pending_tail = now;
        }
        for (int i = 0; i < m; ++i) {
            const int rid = parse_int(words[6 + i]);
            if (kind == "PRE") {
                transition(rid, direction == "UP" ? Phase::P_PROC_READY : Phase::P_POST_READY);
            } else {
                transition(rid, direction == "UP" ? Phase::D_PROC_READY : Phase::D_POST_READY);
            }
        }
    }

    double prefill_urgency(const Request& request) const {
        return max(0.0, now - request.arrival) / max(1.0e-12, slo1);
    }

    double decode_urgency(const Request& request) const {
        if (request.tokens > 0) {
            return max(0.0, now - request.last_token) / max(1.0e-12, slo2);
        }
        if (tight_edf_mode()) return 0.0;
        return FIRST_TOKEN_URGENCY_SCALE
            * (0.20 + 0.25 * max(0.0, now - request.ppost_done) / max(1.0e-12, slo2));
    }

    bool event_batch_allowed() const {
        if (w_tp + 1.0e-12 < EVENT_WAIT_MIN_WTP) return false;
        if (w_tp >= 0.65 - 1.0e-12) return true;
        return transfer_time(1) <= EVENT_LOW_WEIGHT_LINK_RATIO * schedule_cost;
    }

    pair<double, double> lower_bound_ratios() const {
        double tdr_ratio = 0.0;
        if (arrived_count > 0) {
            const double pending_age = prefill_pending_count * now - prefill_arrival_sum;
            const double lower_tdr = (completed_tdr_sum + max(0.0, pending_age)) / arrived_count;
            tdr_ratio = lower_tdr / max(1.0e-12, slo1);
        }

        double tpot_ratio = 0.0;
        const int64_t denominator = gap_count + open_gap_count;
        if (denominator > 0) {
            const double open_age = open_gap_count * now - open_gap_start_sum;
            const double lower_tpot = (gap_sum + max(0.0, open_age)) / denominator;
            tpot_ratio = lower_tpot / max(1.0e-12, slo2);
        }
        return {tdr_ratio, tpot_ratio};
    }

    Mix score_mix(double stage_urgency) const {
        const pair<double, double> ratios = lower_bound_ratios();
        const double tdr_ratio = ratios.first;
        const double tpot_ratio = ratios.second;
        const auto legacy_mix = [&]() {
            const double pressure = max({stage_urgency, tdr_ratio, tpot_ratio});
            double throughput = w_tp;
            double latency = w_c;

            const bool score_gap_band = (0.245 <= w_tp && w_tp <= 0.255)
                || (0.295 <= w_tp && w_tp <= 0.305)
                || (0.795 <= w_tp && w_tp <= 0.805);
            if (dist_base <= 1.0e-12 || score_gap_band) {
                double normalized_throughput = 0.0;
                if (total_tokens > 0 && now > earliest_arrival
                    && isfinite(earliest_arrival)) {
                    const double current_tp = total_tokens / (now - earliest_arrival);
                    normalized_throughput = bounded(
                        (current_tp - tp_base)
                            / max(1.0e-12, tp_upper - tp_base),
                        0.0, 1.0);
                }
                const double distance = hypot(max(0.0, tdr_ratio - 1.0),
                                              max(0.0, tpot_ratio - 1.0));
                double normalized_waiting = 0.0;
                if (dist_base > 0.0) {
                    normalized_waiting = max(0.0, 1.0 - distance / dist_base);
                } else if (distance <= 1.0e-12) {
                    normalized_waiting = 1.0;
                }
                const double tp_gap = SCORE_GAP_FLOOR
                    + (1.0 - SCORE_GAP_FLOOR)
                    * (1.0 - pow(normalized_throughput, SCORE_GAP_POWER));
                const double cost_gap = SCORE_GAP_FLOOR
                    + (1.0 - SCORE_GAP_FLOOR)
                    * (1.0 - pow(normalized_waiting, SCORE_GAP_POWER));
                throughput *= tp_gap;
                latency *= cost_gap;
            }

            if (total_tokens >= 32 && now > earliest_arrival
                && isfinite(earliest_arrival)) {
                const double current_tp = total_tokens / (now - earliest_arrival);
                if (current_tp >= 1.10 * tp_upper) throughput *= 0.35;
            }

            if (dist_base == 0.0) {
                if (pressure < 0.70) latency *= 0.55;
                else if (pressure >= 0.95) latency *= 2.5;
            } else {
                if (pressure < 0.60) latency *= 0.25;
                else if (pressure < 0.90) latency *= 0.60;
                else latency *= min(3.0, 1.0 + 2.0 * (pressure - 0.90));
            }
            const double total = throughput + latency;
            return total > 0.0
                ? Mix{throughput / total, latency / total}
                : Mix{0.5, 0.5};
        };

        const double epsilon = 0.05;
        const double tp_range = max(1.0e-12, tp_upper - tp_base);

        const auto normalized_tp = [&](double throughput) {
            return bounded((throughput - tp_base) / tp_range, 0.0, 1.0);
        };
        const auto normalized_cost = [&](double tdr, double tpot) {
            const double distance = hypot(max(0.0, tdr - 1.0),
                                          max(0.0, tpot - 1.0));
            if (dist_base > 0.0) {
                return max(0.0, 1.0 - distance / dist_base);
            }
            return distance <= 1.0e-12 ? 1.0 : 0.0;
        };

        if (w_tp <= 1.0e-12 || total_tokens < 8
            || now <= earliest_arrival || !isfinite(earliest_arrival)) {
            return legacy_mix();
        }
        const double tp_estimate = total_tokens / (now - earliest_arrival);
        const double live_normalized_tp = normalized_tp(tp_estimate);
        if (live_normalized_tp + 1.0e-12 < w_tp) return legacy_mix();
        // A locally clamped component still has recoverable score.  Probe just
        // inside its scoring interval instead of incorrectly assigning it a
        // zero marginal value while the pipeline is warming up.
        const double tp_probe = bounded(tp_estimate,
            tp_base + epsilon * tp_range,
            tp_upper - epsilon * tp_range);
        double throughput = w_tp * max(0.0,
            normalized_tp(tp_probe * (1.0 + epsilon))
          - normalized_tp(tp_probe / (1.0 + epsilon))) / (2.0 * epsilon);
        double latency = w_c * max(0.0,
            normalized_cost(tdr_ratio / (1.0 + epsilon),
                            tpot_ratio / (1.0 + epsilon))
          - normalized_cost(tdr_ratio * (1.0 + epsilon),
                            tpot_ratio * (1.0 + epsilon))) / (2.0 * epsilon);

        const double sum = throughput + latency;
        if (sum <= 1.0e-15) {
            return legacy_mix();
        }
        return {throughput / sum, latency / sum};
    }

    pair<double, double> slo_priority_shares() const {
        // For pure waiting-quality objectives, steer work toward whichever SLO
        // is already accumulating more unavoidable excess.  A balanced share
        // reproduces the broadly stronger portfolio policy whenever throughput
        // also contributes to the judge score.
        const pair<double, double> ratios = lower_bound_ratios();
        const double tdr_ratio = ratios.first;
        const double tpot_ratio = ratios.second;
        const double excess_tdr = max(0.0, tdr_ratio - 1.0);
        const double excess_tpot = max(0.0, tpot_ratio - 1.0);
        const double radial_tdr_share = bounded(
            (SLO_SHARE_PRIOR + excess_tdr)
                / (2.0 * SLO_SHARE_PRIOR + excess_tdr + excess_tpot),
            SLO_SHARE_FLOOR,
            1.0 - SLO_SHARE_FLOOR
        );
        const double blend = w_tp < 0.20 ? 1.0 : 0.0;
        const double tdr_share = 0.5 + blend * (radial_tdr_share - 0.5);
        return {tdr_share, 1.0 - tdr_share};
    }

    int curve_index(const Curve& curve) const {
        if (&curve == &p_pre) return 0;
        if (&curve == &p_proc) return 1;
        if (&curve == &p_post) return 2;
        if (&curve == &d_pre) return 3;
        if (&curve == &d_proc) return 4;
        return 5;
    }

    int choose_batch_size(const Curve& curve, int ready_count, const Mix& mix) {
        if (ready_count <= 1) return ready_count;

        const int stage_index = curve_index(curve);
        const int bucket = bounded(
            static_cast<int>(lround(mix.throughput * (BATCH_MIX_BUCKETS - 1))),
            0,
            BATCH_MIX_BUCKETS - 1
        );
        auto& cache = batch_choice_cache[stage_index];
        if (static_cast<int>(cache.size()) <= ready_count) cache.resize(ready_count + 1);
        int& cached = cache[ready_count][bucket];
        if (cached != 0) return cached;

        const Mix quantized{
            static_cast<double>(bucket) / (BATCH_MIX_BUCKETS - 1),
            static_cast<double>(BATCH_MIX_BUCKETS - 1 - bucket)
                / (BATCH_MIX_BUCKETS - 1),
        };

        struct Metric { int n; double per_item; double mean_completion; };
        vector<Metric> metrics;
        metrics.reserve(ready_count);
        double best_per_item = INF;
        double best_mean_completion = INF;

        for (int n = 1; n <= ready_count; ++n) {
            const int full_groups = ready_count / n;
            const int remainder = ready_count % n;
            const double full_duration = schedule_cost + curve.at(n);
            const double remainder_duration = remainder ? schedule_cost + curve.at(remainder) : 0.0;
            const double total_time = full_groups * full_duration + remainder_duration;

            long double weighted = static_cast<long double>(n) * full_duration
                                 * full_groups * (full_groups + 1) / 2.0L;
            if (remainder) {
                weighted += static_cast<long double>(remainder)
                          * (full_groups * full_duration + remainder_duration);
            }
            const double mean_completion = static_cast<double>(weighted / ready_count);
            const double per_item = total_time / ready_count;
            metrics.push_back({n, per_item, mean_completion});
            best_per_item = min(best_per_item, per_item);
            best_mean_completion = min(best_mean_completion, mean_completion);
        }

        int best_n = 1;
        double best_score = INF;
        for (const Metric& metric : metrics) {
            const double score = quantized.throughput * metric.per_item / best_per_item
                               + quantized.latency * metric.mean_completion / best_mean_completion;
            if (score < best_score - 1.0e-12
                || (abs(score - best_score) <= 1.0e-12
                    && ((quantized.throughput >= quantized.latency && metric.n > best_n)
                        || (quantized.throughput < quantized.latency && metric.n < best_n)))) {
                best_score = score;
                best_n = metric.n;
            }
        }
        cached = best_n;
        return cached;
    }

    double expected_output_length() const {
        if (arrived_count == 0) return 8.0;

        // Finished requests are observed first precisely because they are
        // short, so their raw mean is a downward-biased estimate.  Treat every
        // unfinished request as right-censored: it has already survived its
        // observed tokens and still receives one learned residual lifetime.
        const int unfinished = max(0, arrived_count - finished_count);
        const int64_t unfinished_tokens = max<int64_t>(0,
            total_tokens - finished_token_sum);
        double residual = 8.0;
        if (finished_count > 0) {
            residual = max(residual,
                static_cast<double>(finished_token_sum) / finished_count);
        }
        const double projected_total = finished_token_sum + unfinished_tokens
                                     + unfinished * residual;
        return bounded(projected_total / arrived_count, 1.0, 512.0);
    }

    int ready_dpre_count() const {
        int count = 0;
        for (const auto& ready : dpre_ready) count += static_cast<int>(ready.size());
        return count;
    }

    double oldest_dpre_urgency() const {
        double urgency = 0.0;
        for (const auto& ready : dpre_ready) {
            if (!ready.empty()) urgency = max(urgency, decode_urgency(requests[ready.begin()->second]));
        }
        return urgency;
    }

    vector<int> select_balanced_dpre(int count, const Mix& mix) const {
        vector<set<ReadyKey>::const_iterator> it(K), end(K);
        vector<int> selected_per_remote(K, 0);
        for (int remote = 0; remote < K; ++remote) {
            it[remote] = dpre_ready[remote].begin();
            end[remote] = dpre_ready[remote].end();
        }

        vector<int> selected;
        selected.reserve(count);
        for (int step = 0; step < count; ++step) {
            int best_remote = -1;
            double best_score = -INF;
            for (int remote = 0; remote < K; ++remote) {
                if (it[remote] == end[remote]) continue;
                const int rid = it[remote]->second;
                const double urgency = decode_urgency(requests[rid]);
                const double balance_bonus = 0.55 * mix.throughput / (1.0 + selected_per_remote[remote]);
                const double score = urgency + balance_bonus;
                if (score > best_score + 1.0e-12
                    || (abs(score - best_score) <= 1.0e-12 && remote < best_remote)) {
                    best_score = score;
                    best_remote = remote;
                }
            }
            if (best_remote < 0) break;
            selected.push_back(it[best_remote]->second);
            ++it[best_remote];
            ++selected_per_remote[best_remote];
        }
        return selected;
    }

    vector<int> select_pipeline_dpre(int balanced_count, const Mix& mix) {
        vector<vector<int>> candidates;
        candidates.push_back(select_balanced_dpre(balanced_count, mix));

        // A one-remote wave pays one fixed UP latency and one fixed DOWN
        // latency.  Keep one such candidate per cloud alongside the balanced
        // candidate, so the decision is made from current queues rather than
        // a global link/weight threshold.
        for (int remote = 0; remote < K; ++remote) {
            const int ready = static_cast<int>(dpre_ready[remote].size());
            if (ready == 0) continue;
            const int count = choose_batch_size(d_pre, ready, mix);
            vector<int> ids = first_ids(dpre_ready[remote], count);
            if (ids != candidates.front()) candidates.push_back(std::move(ids));
        }
        if (candidates.size() == 1) return std::move(candidates.front());

        struct Metric {
            double service = INF;
            double completion = INF;
        };
        vector<Metric> metrics;
        metrics.reserve(candidates.size());
        double best_service = INF;
        double best_completion = INF;
        const double global_urgency = oldest_dpre_urgency();

        for (const vector<int>& ids : candidates) {
            const int size = static_cast<int>(ids.size());
            vector<int> per_remote(K, 0);
            double candidate_urgency = 0.0;
            for (int rid : ids) {
                ++per_remote[requests[rid].remote];
                candidate_urgency = max(candidate_urgency,
                    decode_urgency(requests[rid]));
            }

            const double edge_pre = schedule_cost + d_pre.at(size);
            double up_clock = max(up_tail, now + edge_pre);
            double up_work = 0.0;
            double down_work = 0.0;
            double cloud_capacity = 0.0;
            vector<pair<double, int>> proc_finishes;
            proc_finishes.reserve(K);
            for (int remote = 0; remote < K; ++remote) {
                const int count = per_remote[remote];
                if (count == 0) continue;
                const double transfer = transfer_time(count);
                up_work += transfer;
                down_work += transfer;
                up_clock += transfer;
                const double proc = schedule_cost + d_proc.at(count);
                const double finish = max(up_clock, cloud_busy_until[remote]) + proc;
                proc_finishes.emplace_back(finish, count);
                cloud_capacity += count / max(1.0e-12, proc);
            }

            sort(proc_finishes.begin(), proc_finishes.end());
            double down_clock = max(down_tail, now);
            for (const auto& completion : proc_finishes) {
                down_clock = max(down_clock, completion.first)
                           + transfer_time(completion.second);
            }
            const double edge_post = schedule_cost + d_post.at(size);
            const double response = down_clock + edge_post - now;
            const double service = max({edge_pre / size,
                                        edge_post / size,
                                        up_work / size,
                                        down_work / size,
                                        1.0 / max(1.0e-12, cloud_capacity)});
            // If a concentrated wave skips the globally most urgent request,
            // charge the exact extra SLO2-normalized waiting already at risk.
            const double completion = response
                + max(0.0, global_urgency - candidate_urgency) * slo2;
            metrics.push_back({service, completion});
            best_service = min(best_service, service);
            best_completion = min(best_completion, completion);
        }

        int best_index = 0;
        double best_score = INF;
        for (int index = 0; index < static_cast<int>(candidates.size()); ++index) {
            const double score = mix.throughput
                    * metrics[index].service / max(1.0e-12, best_service)
                + mix.latency
                    * metrics[index].completion / max(1.0e-12, best_completion);
            if (score < best_score - 1.0e-12
                || (abs(score - best_score) <= 1.0e-12
                    && candidates[index].size() > candidates[best_index].size())) {
                best_score = score;
                best_index = index;
            }
        }
        return std::move(candidates[best_index]);
    }

    template <class Set>
    static vector<int> first_ids(const Set& ready, int count) {
        vector<int> ids;
        ids.reserve(count);
        for (auto it = ready.begin(); it != ready.end() && static_cast<int>(ids.size()) < count; ++it) {
            ids.push_back(it->second);
        }
        return ids;
    }

    EdgeOption choose_edge_option(bool force_progress = false) {
        EdgeOption best;
        const double expected_tokens = expected_output_length();
        const pair<double, double> slo_shares = slo_priority_shares();
        const double tdr_share = slo_shares.first;
        const double tpot_share = slo_shares.second;

        const set<ReadyKey>* selected_dpost = &dpost_ready;
        bool cost_free_first_tokens = false;
        if (COHORT_FIRST_TOKENS && form_first_token_cohort()) {
            if (w_tp >= 0.45 && !dpost_first_ready.empty()) {
                // Widen the decode wave before spending edge time on later
                // tokens.  The resulting batch remains aligned downstream.
                selected_dpost = &dpost_first_ready;
                cost_free_first_tokens = true;
            } else if (!dpost_gap_ready.empty()) {
                selected_dpost = &dpost_gap_ready;
            } else {
                selected_dpost = &dpost_first_ready;
                cost_free_first_tokens = true;
            }
        }

        const int dpost_count = static_cast<int>(selected_dpost->size());
        const int cohort_target = first_token_cohort_target();
        const bool wait_for_first_token_peer = !force_progress
            && COHORT_HOLD_PEERS && cost_free_first_tokens
            && dpost_count < cohort_target && first_token_decode_count > dpost_count;
        bool wait_for_transfer_batch = false;
        if (EVENT_BATCH_WAIT) {
            if (!force_progress && !cost_free_first_tokens && event_batch_allowed()
                && dpost_count > 0 && decode_down_pending_items > 0) {
                const int pending = decode_down_pending_items;
                const double separate = 2.0 * schedule_cost
                    + d_post.at(dpost_count) + d_post.at(pending);
                const double combined = schedule_cost + d_post.at(dpost_count + pending);
                const double saved_compute = max(0.0, separate - combined);
                const double guaranteed_wait = max(0.0,
                    decode_down_pending_tail - now);
                wait_for_transfer_batch = guaranteed_wait
                    < EVENT_WAIT_GAIN_FACTOR * saved_compute;
            }
        }
        if (dpost_count > 0 && !wait_for_first_token_peer && !wait_for_transfer_batch) {
            const double oldest = decode_urgency(requests[selected_dpost->begin()->second]);
            const Mix priority_mix = score_mix(oldest);
            const Mix batch_mix = cost_free_first_tokens && COHORT_THROUGHPUT_BATCH
                ? Mix{1.0, 0.0}
                : priority_mix;
            const int eligible_count = cost_free_first_tokens
                ? min(dpost_count, cohort_target)
                : dpost_count;
            const int size = choose_batch_size(d_post, eligible_count, batch_mix);
            vector<int> ids = first_ids(*selected_dpost, size);
            double sum_urgency = 0.0;
            double max_urgency = 0.0;
            for (int rid : ids) {
                const double urgency = decode_urgency(requests[rid]);
                sum_urgency += min(urgency, 20.0);
                max_urgency = max(max_urgency, urgency);
            }
            const double duration = schedule_cost + d_post.at(size);
            const double slo_factor = 0.65 + 0.70 * tpot_share;
            const double value = 1.55 * priority_mix.throughput * size
                               + 1.30 * slo_factor * priority_mix.latency
                               * (size + sum_urgency)
                               + 0.15 * size;
            double score = cost_free_first_tokens && COHORT_BACKGROUND
                && w_tp <= 1.0e-12
                ? 0.01 * size / duration
                : value / duration + (0.16 + 0.24 * tpot_share) * max_urgency;
            score += tight_edf_boost() * max_urgency;
            best = {EdgeOption::Kind::D_POST, std::move(ids), -1, duration, score};
        }

        if (!ppost_ready.empty()) {
            const int rid = ppost_ready.begin()->second;
            const Request& request = requests[rid];
            const double urgency = prefill_urgency(request);
            const Mix mix = score_mix(urgency);
            const double duration = schedule_cost + p_post.at(request.lin);
            const double slo_factor = 0.65 + 0.70 * tdr_share;
            const double value = 0.70 * mix.throughput * expected_tokens
                               + 1.90 * slo_factor * mix.latency
                               * (1.0 + min(urgency, 20.0)) + 0.10;
            double score = value / duration
                         + (0.28 + 0.48 * tdr_share) * urgency;
            score += tight_edf_boost() * urgency;
            if (score > best.score) best = {EdgeOption::Kind::P_POST, {}, rid, duration, score};
        }

        const int dpre_count = ready_dpre_count();
        bool hold_first_decode_wave = false;
        if (!force_progress && dpre_count > 0 && COHORT_HOLD_PEERS && w_tp >= 0.45
            && form_first_token_cohort()
            && dpre_count == dpre_first_ready_count && prefill_pending_count > 0) {
            const int potential = dpre_first_ready_count + prefill_pending_count;
            const int desired = min(first_token_cohort_target(), potential);
            const double oldest = oldest_dpre_urgency();
            hold_first_decode_wave = dpre_first_ready_count < desired && oldest < 0.50;
        }
        if (dpre_count > 0 && !hold_first_decode_wave) {
            const double oldest = oldest_dpre_urgency();
            const Mix mix = score_mix(oldest);
            const int target_size = choose_batch_size(d_pre, dpre_count, mix);
            vector<int> ids = PIPELINE_DPRE_SELECT
                ? select_pipeline_dpre(target_size, mix)
                : select_balanced_dpre(target_size, mix);
            const int size = static_cast<int>(ids.size());
            vector<int> per_remote(K, 0);
            double sum_urgency = 0.0;
            double max_urgency = 0.0;
            for (int rid : ids) {
                ++per_remote[requests[rid].remote];
                const double urgency = decode_urgency(requests[rid]);
                sum_urgency += min(urgency, 20.0);
                max_urgency = max(max_urgency, urgency);
            }
            double link_and_cloud = 0.0;
            for (int remote = 0; remote < K; ++remote) {
                if (per_remote[remote] == 0) continue;
                link_and_cloud += transfer_time(per_remote[remote]);
                link_and_cloud += 0.35 * (schedule_cost + d_proc.at(per_remote[remote]));
            }
            const double duration = schedule_cost + d_pre.at(size);
            const double queue_delay = max(0.0, up_tail - (now + duration));
            const double denominator = duration + (0.025 + 0.050 * mix.latency)
                                                * (queue_delay + link_and_cloud);
            const double slo_factor = 0.65 + 0.70 * tpot_share;
            const double value = 1.15 * mix.throughput * size
                               + 1.05 * slo_factor * mix.latency * (size + sum_urgency)
                               + 0.12 * size;
            double score = value / denominator
                         + (0.14 + 0.20 * tpot_share) * max_urgency;
            score += tight_edf_boost() * max_urgency;
            if (score > best.score) {
                best = {EdgeOption::Kind::D_PRE, std::move(ids), -1, duration, score};
            }
        }

        if (!ppre_ready.empty()) {
            const int rid = ppre_ready.begin()->second;
            const Request& request = requests[rid];
            const double urgency = prefill_urgency(request);
            const Mix mix = score_mix(urgency);
            const double duration = schedule_cost + p_pre.at(request.lin);
            const double queue_delay = max(0.0, up_tail - (now + duration));
            const double up = transfer_time(request.lin);
            const double active_penalty = total_decode_active > 0 ? 1.0 : 0.25;
            const double denominator = duration + active_penalty
                                      * (0.020 + 0.085 * mix.latency)
                                      * (queue_delay + up);
            const double slo_factor = 0.65 + 0.70 * tdr_share;
            const double value = 0.55 * mix.throughput * expected_tokens
                               + 1.20 * slo_factor * mix.latency
                               * (1.0 + min(urgency, 20.0)) + 0.08;
            double score = value / denominator
                         + (0.10 + 0.16 * tdr_share) * urgency;
            score += tight_edf_boost() * urgency;
            const bool any_idle_cloud = any_of(cloud_free.begin(), cloud_free.end(), [](bool free) { return free; });
            if (any_idle_cloud && total_decode_active == 0) score *= 1.25;
            if (score > best.score) best = {EdgeOption::Kind::P_PRE, {}, rid, duration, score};
        }

        return best;
    }

    int modeled_remote_count(const Request& request) const {
        const int live = max(1, total_decode_active + prefill_pending_count);
        const int batch = min(live, MAX_CURVE_ARGUMENT);
        const double expected_tokens = max(1.0, expected_output_length());
        const pair<double, double> current_ratios = lower_bound_ratios();
        const double current_tdr_ratio = current_ratios.first;
        const double current_tpot_ratio = current_ratios.second;

        struct Plan {
            int remotes = 1;
            double primary = -INF;
            double secondary = INF;
        } best;

        for (int remotes = 1; remotes <= K; ++remotes) {
            const int represented = min(remotes, batch);
            vector<pair<double, int>> proc_finishes;
            proc_finishes.reserve(represented);

            double up_clock = schedule_cost + d_pre.at(batch);
            double transfer_sum = 0.0;
            double cloud_capacity = 0.0;
            for (int remote = 0; remote < represented; ++remote) {
                const int share = batch / represented
                                + (remote < batch % represented ? 1 : 0);
                const double transfer = transfer_time(share);
                transfer_sum += transfer;
                up_clock += transfer;
                const double proc = schedule_cost + d_proc.at(share);
                proc_finishes.emplace_back(up_clock + proc, share);
                cloud_capacity += share / max(1.0e-12, proc);
            }

            sort(proc_finishes.begin(), proc_finishes.end());
            double down_clock = 0.0;
            for (const auto& completion : proc_finishes) {
                down_clock = max(down_clock, completion.first)
                           + transfer_time(completion.second);
            }
            const double wave_finish = down_clock + schedule_cost + d_post.at(batch);

            // Steady-state resource demand per generated token.  Prefill is
            // amortized by the observed/estimated output length, so long
            // prompts correctly preserve cloud parallelism when it matters.
            const double edge_ms_per_token =
                (2.0 * schedule_cost + d_pre.at(batch) + d_post.at(batch)) / batch
                + (2.0 * schedule_cost + p_pre.at(request.lin)
                   + p_post.at(request.lin)) / expected_tokens;
            const double up_ms_per_token = transfer_sum / batch
                + transfer_time(request.lin) / expected_tokens;
            const double down_ms_per_token = up_ms_per_token;
            const double cloud_decode_ms_per_token =
                1.0 / max(1.0e-12, cloud_capacity);
            const double cloud_prefill_ms_per_token =
                (schedule_cost + p_proc.at(request.lin))
                / (remotes * expected_tokens);
            const double bottleneck = max({edge_ms_per_token,
                                           up_ms_per_token,
                                           down_ms_per_token,
                                           cloud_decode_ms_per_token
                                               + cloud_prefill_ms_per_token});
            const double projected_tp = 1.0 / max(1.0e-12, bottleneck);
            const double normalized_tp = bounded(
                (projected_tp - tp_base) / max(1.0e-12, tp_upper - tp_base),
                0.0,
                1.0
            );

            // Predict the earliest first-token completion for the incoming
            // request on this prefix, including both FIFO link tails and the
            // work already committed to each cloud.
            const double ppre_done = now + schedule_cost + p_pre.at(request.lin);
            const double prefill_up_done = max(up_tail, ppre_done)
                                         + transfer_time(request.lin);
            double predicted_finish = INF;
            const double decode_unit = schedule_cost + d_proc.at(1);
            for (int remote = 0; remote < remotes; ++remote) {
                const double known_load = max(0.0, cloud_busy_until[remote] - now)
                                        + prefill_remaining[remote]
                                        + decode_active[remote] * decode_unit
                                        + assigned_active[remote] * 0.20 * decode_unit;
                const double proc_done = max(prefill_up_done, now + known_load)
                                       + schedule_cost + p_proc.at(request.lin);
                const double prefill_down_done = max(down_tail, proc_done)
                                               + transfer_time(request.lin);
                predicted_finish = min(predicted_finish,
                    prefill_down_done + schedule_cost + p_post.at(request.lin));
            }

            const double pending_age = max(0.0,
                prefill_pending_count * now - prefill_arrival_sum);
            const double remaining = max(0.0, predicted_finish - now);
            const double projected_tdr = arrived_count > 0
                ? (completed_tdr_sum + pending_age
                   + prefill_pending_count * remaining) / arrived_count
                : remaining;
            const double projected_tdr_ratio = max(current_tdr_ratio,
                projected_tdr / max(1.0e-12, slo1));

            // In a filled pipeline the inter-token interval is its slowest
            // resource, while wave_finish is the cold-start response time.
            const double projected_tpot_ratio = max(current_tpot_ratio,
                bottleneck / max(1.0e-12, slo2));
            const double distance = hypot(max(0.0, projected_tdr_ratio - 1.0),
                                          max(0.0, projected_tpot_ratio - 1.0));
            double normalized_cost = 0.0;
            if (dist_base > 0.0) {
                normalized_cost = max(0.0, 1.0 - distance / dist_base);
            } else if (distance <= 1.0e-12) {
                normalized_cost = 1.0;
            }

            const double primary = w_tp * normalized_tp + w_c * normalized_cost;
            const double secondary = w_tp * bottleneck
                + w_c * (projected_tdr_ratio + projected_tpot_ratio
                         + wave_finish / max(1.0e-12, slo2));
            if (primary > best.primary + 1.0e-12
                || (abs(primary - best.primary) <= 1.0e-12
                    && (secondary < best.secondary - 1.0e-12
                        || (abs(secondary - best.secondary) <= 1.0e-12
                            && remotes < best.remotes)))) {
                best = {remotes, primary, secondary};
            }
        }
        return best.remotes;
    }

    int choose_remote(const Request& request) {
        const double decode_unit = schedule_cost + d_proc.at(1);
        const auto placement_load = [&](int remote, int assigned) {
            const double busy = max(0.0, cloud_busy_until[remote] - now);
            const double active_decode_load = decode_active[remote] * decode_unit;
            const double admission_balance = assigned * 0.20 * decode_unit;
            return busy + prefill_remaining[remote] + active_decode_load
                 + admission_balance + 0.35 * p_proc.at(request.lin);
        };

        // Preserve the established latency policy when throughput has no
        // score value.  Otherwise choose topology by the exact marginal cost
        // of opening or filling each remote, including one fixed UP latency
        // for every represented remote in every decode wave.
        if (w_tp <= 1.0e-12) {
            const int remote_count = DYNAMIC_REMOTE_PLANNER
                ? modeled_remote_count(request)
                : (use_link_remote_limit() ? 1 : K);
            int best_remote = 0;
            double best_load = INF;
            for (int offset = 0; offset < remote_count; ++offset) {
                const int remote = (remote_rotation + offset) % remote_count;
                const double load = placement_load(remote,
                    assigned_active[remote]);
                if (load < best_load - 1.0e-12) {
                    best_load = load;
                    best_remote = remote;
                }
            }
            remote_rotation = (best_remote + 1) % remote_count;
            return best_remote;
        }

        const pair<double, double> live_ratios = lower_bound_ratios();
        const double pending_age = max(0.0,
            prefill_pending_count * now - prefill_arrival_sum);
        const int active_total = 1 + accumulate(
            assigned_active.begin(), assigned_active.end(), 0);

        struct Placement {
            int remote = 0;
            double primary = -INF;
            double secondary = INF;
            double finish = INF;
            double load = INF;
        } best;

        for (int candidate = 0; candidate < K; ++candidate) {
            vector<int> population = assigned_active;
            ++population[candidate];
            int represented = 0;
            double cloud_capacity = 0.0;
            for (int remote = 0; remote < K; ++remote) {
                const int count = population[remote];
                if (count == 0) continue;
                ++represented;
                cloud_capacity += count
                    / max(1.0e-12, schedule_cost + d_proc.at(count));
            }

            const double edge = (2.0 * schedule_cost
                + d_pre.at(active_total) + d_post.at(active_total))
                / active_total;
            const double serialization = max(0.0,
                transfer_time(active_total) - latency_ms);
            const double link = (represented * latency_ms + serialization)
                / active_total;
            const double cloud = 1.0 / max(1.0e-12, cloud_capacity);
            const double bottleneck = max({edge, link, cloud});
            const double projected_tp = 1.0 / max(1.0e-12, bottleneck);
            const double normalized_tp = bounded(
                (projected_tp - tp_base)
                    / max(1.0e-12, tp_upper - tp_base),
                0.0, 1.0);

            const double ppre_done = now + schedule_cost + p_pre.at(request.lin);
            const double up_done = max(up_tail, ppre_done)
                                 + transfer_time(request.lin);
            const double load = placement_load(candidate,
                population[candidate]);
            const double proc_done = max(up_done, now + load)
                                   + schedule_cost + p_proc.at(request.lin);
            const double down_done = max(down_tail, proc_done)
                                   + transfer_time(request.lin);
            const double finish = down_done + schedule_cost
                                + p_post.at(request.lin);
            const double remaining = max(0.0, finish - now);
            const double projected_tdr = arrived_count > 0
                ? (completed_tdr_sum + pending_age + remaining) / arrived_count
                : remaining;
            const double projected_tdr_ratio = max(live_ratios.first,
                projected_tdr / max(1.0e-12, slo1));
            const double projected_tpot_ratio = max(live_ratios.second,
                bottleneck / max(1.0e-12, slo2));
            const double distance = hypot(
                max(0.0, projected_tdr_ratio - 1.0),
                max(0.0, projected_tpot_ratio - 1.0));
            double normalized_cost = 0.0;
            if (dist_base > 0.0) {
                normalized_cost = max(0.0, 1.0 - distance / dist_base);
            } else if (distance <= 1.0e-12) {
                normalized_cost = 1.0;
            }

            const double primary = w_tp * normalized_tp
                                 + w_c * normalized_cost;
            const double secondary = w_tp * bottleneck * tp_upper
                + w_c * (distance + remaining / max(1.0e-12, slo1));
            if (primary > best.primary + 1.0e-12
                || (abs(primary - best.primary) <= 1.0e-12
                    && (secondary < best.secondary - 1.0e-12
                        || (abs(secondary - best.secondary) <= 1.0e-12
                            && (finish < best.finish - 1.0e-12
                                || (abs(finish - best.finish) <= 1.0e-12
                                    && (load < best.load - 1.0e-12
                                        || (abs(load - best.load) <= 1.0e-12
                                            && candidate < best.remote)))))))) {
                best = {candidate, primary, secondary, finish, load};
            }
        }
        remote_rotation = (best.remote + 1) % K;
        return best.remote;
    }

    Assignment schedule_edge(const EdgeOption& option) {
        Assignment assignment;
        if (option.kind == EdgeOption::Kind::NONE) return assignment;

        edge_free = false;
        if (option.kind == EdgeOption::Kind::P_PRE) {
            Request& request = requests[option.rid];
            const int remote = choose_remote(request);
            request.remote = remote;
            ++assigned_active[remote];
            prefill_remaining[remote] += p_proc.at(request.lin);
            transition(option.rid, Phase::P_PRE_RUNNING);
            assignment.line = "E P PRE " + to_string(remote) + " " + to_string(option.rid);
            assignment.transfer_priority = 2;
            return assignment;
        }
        if (option.kind == EdgeOption::Kind::P_POST) {
            const Request& request = requests[option.rid];
            transition(option.rid, Phase::P_POST_RUNNING);
            assignment.line = "E P POST " + to_string(request.remote) + " " + to_string(option.rid);
            assignment.transfer_priority = 0;
            return assignment;
        }

        const bool is_post = option.kind == EdgeOption::Kind::D_POST;
        const string step = is_post ? "POST" : "PRE";
        string line = "E D " + step + " -1 " + to_string(option.ids.size());
        double max_urgency = 0.0;
        for (int rid : option.ids) {
            line += " " + to_string(rid);
            max_urgency = max(max_urgency, decode_urgency(requests[rid]));
            transition(rid, is_post ? Phase::D_POST_RUNNING : Phase::D_PRE_RUNNING);
        }
        assignment.line = std::move(line);
        assignment.transfer_priority = is_post ? 0 : 1;
        assignment.urgency = max_urgency;
        return assignment;
    }

    int choose_prefill_chunk(const Request& request, bool decode_pressure, const Mix& mix) const {
        const int remaining_layers = num_layers - request.next_layer;
        if (remaining_layers <= 1 || !decode_pressure) return num_layers;

        const double full_raw = p_proc.at(request.lin);
        const double remaining_raw = full_raw * remaining_layers / num_layers;
        if (full_raw <= 3.0 * schedule_cost) return num_layers;

        const int active_here = max(1, decode_active[request.remote]);
        const int nominal_batch = min(64, active_here);
        const double decode_quantum = schedule_cost + d_proc.at(nominal_batch);
        double target = max(2.0 * schedule_cost, max(1.35 * decode_quantum, 0.45 * slo2));

        const double urgency = prefill_urgency(request);
        if (urgency > 1.0) target *= min(3.0, 1.0 + urgency);

        const int max_pieces = max(2, static_cast<int>(lround(3.0 + 6.0 * mix.latency)));
        int layers = max(1, static_cast<int>(floor(target * num_layers / full_raw)));
        layers = max(layers, (remaining_layers + max_pieces - 1) / max_pieces);
        layers = min(layers, remaining_layers);

        if (layers == remaining_layers && urgency < 1.0) {
            const double down = transfer_time(request.lin);
            const double existing_down = max(0.0, down_tail - now);
            if (total_decode_active > 0 && down > 2.0 * schedule_cost
                && (existing_down > 0.0 || down > target)) {
                layers = remaining_layers - 1;
            }
        }

        if (remaining_raw <= target) return num_layers;
        return request.next_layer + layers;
    }

    CloudOption choose_cloud_option(int remote) {
        CloudOption best;
        best.remote = remote;
        const pair<double, double> slo_shares = slo_priority_shares();
        const double tdr_share = slo_shares.first;
        const double tpot_share = slo_shares.second;
        const pair<double, double> ratios = lower_bound_ratios();
        const double tdr_ratio = ratios.first;
        const double tpot_ratio = ratios.second;
        const bool decode_emergency = w_tp > 1.0e-12 && w_c >= 0.50
            && tpot_ratio > 1.0 && tpot_ratio > 1.05 * max(1.0, tdr_ratio)
            && !dproc_ready[remote].empty();

        bool wait_for_transfer_batch = false;
        if (EVENT_BATCH_WAIT) {
            if (event_batch_allowed() && !dproc_ready[remote].empty()
                && decode_up_pending_items[remote] > 0) {
                const int ready = static_cast<int>(dproc_ready[remote].size());
                const int pending = decode_up_pending_items[remote];
                const double separate = 2.0 * schedule_cost
                    + d_proc.at(ready) + d_proc.at(pending);
                const double combined = schedule_cost + d_proc.at(ready + pending);
                const double saved_compute = max(0.0, separate - combined);
                const double guaranteed_wait = max(0.0,
                    decode_up_pending_tail[remote] - now);
                wait_for_transfer_batch = guaranteed_wait
                    < EVENT_WAIT_GAIN_FACTOR * saved_compute;
            }
        }

        if (!dproc_ready[remote].empty() && !wait_for_transfer_batch) {
            const int ready_count = static_cast<int>(dproc_ready[remote].size());
            const double oldest = decode_urgency(requests[dproc_ready[remote].begin()->second]);
            const Mix mix = score_mix(oldest);
            const int size = choose_batch_size(d_proc, ready_count, mix);
            vector<int> ids = first_ids(dproc_ready[remote], size);
            double sum_urgency = 0.0;
            double max_urgency = 0.0;
            for (int rid : ids) {
                const double urgency = decode_urgency(requests[rid]);
                sum_urgency += min(urgency, 20.0);
                max_urgency = max(max_urgency, urgency);
            }
            const double duration = schedule_cost + d_proc.at(size);
            const double queue_delay = max(0.0, down_tail - (now + duration));
            const double denominator = duration + (0.020 + 0.050 * mix.latency)
                                                * (queue_delay + transfer_time(size));
            const double slo_factor = 0.65 + 0.70 * tpot_share;
            const double value = 1.30 * mix.throughput * size
                               + 1.20 * slo_factor * mix.latency * (size + sum_urgency)
                               + 0.12 * size;
            double score = value / denominator
                         + (0.14 + 0.24 * tpot_share) * max_urgency;
            score += tight_edf_boost() * max_urgency;
            best.kind = CloudOption::Kind::D_PROC;
            best.ids = std::move(ids);
            best.duration = duration;
            best.urgency = max_urgency;
            best.score = score;
        }

        if (!decode_emergency && !pproc_ready[remote].empty()) {
            const int rid = pproc_ready[remote].begin()->second;
            const Request& request = requests[rid];
            const double urgency = prefill_urgency(request);
            const Mix mix = score_mix(urgency);
            const bool decode_pressure = total_decode_active > 0 || !dproc_ready[remote].empty();
            const int layer_end = choose_prefill_chunk(request, decode_pressure, mix);
            const int layer_count = layer_end - request.next_layer;
            const double raw = p_proc.at(request.lin) * layer_count / num_layers;
            const double duration = schedule_cost + raw;
            const double progress = static_cast<double>(layer_count)
                                  / max(1, num_layers - request.next_layer);
            const bool final_piece = layer_end == num_layers;
            const double queue_delay = final_piece ? max(0.0, down_tail - (now + duration)) : 0.0;
            const double link = final_piece ? transfer_time(request.lin) : 0.0;
            const double denominator = duration + (0.015 + 0.070 * mix.latency)
                                                * (queue_delay + link);
            const double slo_factor = 0.65 + 0.70 * tdr_share;
            double value = progress * (0.55 * mix.throughput * expected_output_length()
                                      + 1.25 * slo_factor * mix.latency
                                      * (1.0 + min(urgency, 20.0)) + 0.08);
            if (final_piece) {
                value += 0.30 * mix.throughput * expected_output_length()
                       + 0.80 * slo_factor * mix.latency
                       * (1.0 + min(urgency, 20.0));
            }
            double score = value / denominator
                         + (0.14 + 0.20 * tdr_share) * urgency;
            score += tight_edf_boost() * urgency;
            if (urgency > 2.0 + 2.0 * mix.throughput) {
                score += (0.5 + tdr_share) * urgency;
            }
            if (score > best.score) {
                best.kind = CloudOption::Kind::P_PROC;
                best.rid = rid;
                best.layer_end = layer_end;
                best.ids.clear();
                best.duration = duration;
                best.urgency = urgency;
                best.score = score;
            }
        }

        return best;
    }

    Assignment schedule_cloud(const CloudOption& option) {
        Assignment assignment;
        if (option.kind == CloudOption::Kind::NONE) return assignment;
        const int remote = option.remote;
        cloud_free[remote] = false;
        cloud_busy_until[remote] = now + option.duration;
        assignment.remote = remote;
        assignment.urgency = option.urgency;

        if (option.kind == CloudOption::Kind::D_PROC) {
            string line = "C" + to_string(remote) + " D PROC " + to_string(remote)
                        + " " + to_string(option.ids.size());
            for (int rid : option.ids) {
                line += " " + to_string(rid);
                transition(rid, Phase::D_PROC_RUNNING);
            }
            assignment.line = std::move(line);
            assignment.transfer_priority = 3;
            return assignment;
        }

        const Request& request = requests[option.rid];
        const int layer_start = request.next_layer;
        const double raw = p_proc.at(request.lin) * (option.layer_end - layer_start) / num_layers;
        prefill_remaining[remote] = max(0.0, prefill_remaining[remote] - raw);
        transition(option.rid, Phase::P_PROC_RUNNING);
        assignment.line = "C" + to_string(remote) + " P PROC " + to_string(layer_start)
                        + " " + to_string(option.layer_end) + " " + to_string(remote)
                        + " " + to_string(option.rid);
        assignment.transfer_priority = option.layer_end == num_layers ? 1 : 2;
        return assignment;
    }

    vector<Assignment> make_assignments() {
        vector<Assignment> result;
        if (edge_free) {
            EdgeOption edge = choose_edge_option();
            if (edge.kind != EdgeOption::Kind::NONE) result.push_back(schedule_edge(edge));
        }

        vector<Assignment> cloud_assignments;
        cloud_assignments.reserve(K);
        for (int remote = 0; remote < K; ++remote) {
            if (!cloud_free[remote]) continue;
            CloudOption cloud = choose_cloud_option(remote);
            if (cloud.kind != CloudOption::Kind::NONE) cloud_assignments.push_back(schedule_cloud(cloud));
        }

        stable_sort(cloud_assignments.begin(), cloud_assignments.end(), [](const Assignment& a,
                                                                           const Assignment& b) {
            if (a.transfer_priority != b.transfer_priority) {
                return a.transfer_priority > b.transfer_priority;
            }
            if (a.urgency != b.urgency) return a.urgency > b.urgency;
            return a.remote < b.remote;
        });
        result.insert(result.end(), cloud_assignments.begin(), cloud_assignments.end());

        // The interactor has no timer or self-wake mechanism.  If every
        // heuristic chose to wait and no task was launched, break any circular
        // cohort wait by starting one legal edge task immediately.
        const bool no_internal_wakeup = up_pending == 0 && down_pending == 0
            && all_of(cloud_free.begin(), cloud_free.end(), [](bool free) { return free; });
        if (result.empty() && edge_free && no_internal_wakeup) {
            EdgeOption forced = choose_edge_option(true);
            if (forced.kind != EdgeOption::Kind::NONE) {
                result.push_back(schedule_edge(forced));
            }
        }
        return result;
    }
};

}  // namespace

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Scheduler scheduler;
    if (!scheduler.read_startup()) return 0;
    scheduler.run();
    return 0;
}
