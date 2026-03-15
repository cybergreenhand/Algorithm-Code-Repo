#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long randll(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

int main() {
    freopen("a.in","w",stdout);
    const int MAX_TOTAL_N = 20;
    const int MAX_T = 5;
    int remaining = MAX_TOTAL_N;
    vector<int> ns;
    vector<vector<pair<long long, long long>>> all_points;

    while (remaining > 0 && ns.size() < MAX_T) {
        // 本测试用例的 n 取 1 到 min(剩余点数, 2000) 之间的随机数
        int max_n = min(remaining, 10);
        int n = randll(1, max_n);

        // 随机选择生成模式 (0~3)
        int mode = randll(0, 3);
        set<pair<long long, long long>> used;
        vector<pair<long long, long long>> points;

        if (mode == 0) {          // 完全随机
            while (points.size() < n) {
                long long v = randll(1, 10);
                long long p = randll(1, 10);
                if (used.insert({v, p}).second) {
                    points.emplace_back(v, p);
                }
            }
        } else if (mode == 1) {   // 固定音量，随机音高
            long long fixed_v = randll(1, 10);
            while (points.size() < n) {
                long long p = randll(1, 10);
                if (used.insert({fixed_v, p}).second) {
                    points.emplace_back(fixed_v, p);
                }
            }
        } else if (mode == 2) {   // 固定音高，随机音量
            long long fixed_p = randll(1, 10);
            while (points.size() < n) {
                long long v = randll(1, 10);
                if (used.insert({v, fixed_p}).second) {
                    points.emplace_back(v, fixed_p);
                }
            }
        } else {                  // 网格点：音量取 √n 个值，音高取 √n 个值，组合
            int side = ceil(sqrt(n));
            vector<long long> vs, ps;
            set<long long> used_v, used_p;
            while (vs.size() < side) {
                long long v = randll(1, 10);
                if (used_v.insert(v).second) vs.push_back(v);
            }
            while (ps.size() < side) {
                long long p = randll(1, 10);
                if (used_p.insert(p).second) ps.push_back(p);
            }
            for (int i = 0; i < side && points.size() < n; ++i) {
                for (int j = 0; j < side && points.size() < n; ++j) {
                    points.emplace_back(vs[i], ps[j]);
                }
            }
            // 打乱顺序，避免不必要的规律性
            shuffle(points.begin(), points.end(), rng);
        }

        ns.push_back(n);
        all_points.push_back(points);
        remaining -= n;
    }

    // 输出
    cout << ns.size() << "\n";
    for (size_t i = 0; i < ns.size(); ++i) {
        cout << ns[i] << "\n";
        for (auto &[v, p] : all_points[i]) {
            cout << v << " " << p << "\n";
        }
    }
    return 0;
}