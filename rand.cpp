#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <cstdlib>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randint(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

long long randll(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

int main(int argc, char* argv[]) {
    freopen("a.in","w",stdout);
    int t = 5; // 默认测试用例数量，可通过命令行参数修改
    if (argc > 1) t = atoi(argv[1]);

    const int MAX_TOTAL_N = 20;
    const int MAX_TOTAL_M = 30;

    // 确保每个测试用例至少有 2 个节点
    int max_possible_t = MAX_TOTAL_N / 2;
    if (t > max_possible_t) {
        t = max_possible_t;
        cerr << "Warning: t reduced to " << t << " due to total n limit." << endl;
    }
    if (t <= 0) t = 1;

    // 生成每个测试用例的节点数 n_i（每个至少 2，总和 = MAX_TOTAL_N）
    vector<int> n_vec(t, 2);
    int remaining_n = MAX_TOTAL_N - 2 * t;
    if (remaining_n > 0) {
        vector<int> splits(t - 1);
        for (int i = 0; i < t - 1; ++i)
            splits[i] = randint(0, remaining_n);
        sort(splits.begin(), splits.end());
        int prev = 0;
        for (int i = 0; i < t - 1; ++i) {
            int add = splits[i] - prev;
            n_vec[i] += add;
            prev = splits[i];
        }
        n_vec[t - 1] += remaining_n - prev;
    }

    // 生成每个测试用例的边数 m_i，确保总和不超过 MAX_TOTAL_M
    vector<int> m_vec(t, 0);
    int remaining_m = MAX_TOTAL_M;
    for (int i = 0; i < t; ++i) {
        long long max_edges = (long long)n_vec[i] * (n_vec[i] - 1) / 2;
        int upper = min<long long>(remaining_m, max_edges);
        if (upper < 0) upper = 0;
        int m_i = randint(0, upper);
        m_vec[i] = m_i;
        remaining_m -= m_i;
    }

    // 输出测试用例数量
    cout << t << "\n";

    for (int idx = 0; idx < t; ++idx) {
        int n = n_vec[idx];
        int m = m_vec[idx];

        cout << n << " " << m << "\n";

        // 输出每个节点的电池数 b_i (0 ~ 1e9)
        for (int i = 0; i < n; ++i) {
            cout << randll(0, 10);
            if (i + 1 < n) cout << " ";
        }
        cout << "\n";

        // 输出 m 条边，每条边满足 s < t，权值 w_i (1 ~ 1e9)
        for (int i = 0; i < m; ++i) {
            int s = randint(1, n - 1);
            int t_node = randint(s + 1, n);
            long long w = randll(1, 10);
            cout << s << " " << t_node << " " << w << "\n";
        }
    }

    return 0;
}