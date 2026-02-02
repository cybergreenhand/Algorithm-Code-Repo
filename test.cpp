#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int B = 31; 
vector<int> get_bits(ll x) {
    vector<int> bits(B);
    for (int i = 0; i < B; i++) {
        bits[i] = (x >> (B - 1 - i)) & 1;
    }
    return bits;
}
tuple<ll, ll, ll> max_sum_le(ll x, ll y) {
    vector<int> bx = get_bits(x);
    vector<int> by = get_bits(y);
    vector<vector<vector<tuple<ll, ll, ll>>>> dp(
        B + 1, vector<vector<tuple<ll, ll, ll>>>(
            2, vector<tuple<ll, ll, ll>>(2, make_tuple(-1, -1, -1))));
    function<tuple<ll, ll, ll>(int, int, int)> dfs = [&](int pos, int tight_p, int tight_q) -> tuple<ll, ll, ll> {
        if (pos == B) return make_tuple(0, 0, 0);
        if (get<0>(dp[pos][tight_p][tight_q]) != -1) return dp[pos][tight_p][tight_q];
        int xb = bx[pos];
        int yb = by[pos];
        ll best_val = -1, best_p = -1, best_q = -1;
        for (int mask = 0; mask < 3; mask++) {
            int p_bit = 0, q_bit = 0;
            if (mask == 1) p_bit = 1;
            else if (mask == 2) q_bit = 1;
            if (tight_p == 0 && p_bit > xb) continue;
            if (tight_q == 0 && q_bit > yb) continue;
            int new_tight_p = tight_p;
            int new_tight_q = tight_q;
            if (tight_p == 0 && p_bit < xb) new_tight_p = 1;
            if (tight_q == 0 && q_bit < yb) new_tight_q = 1;
            auto [next_val, next_p, next_q] = dfs(pos + 1, new_tight_p, new_tight_q);
            if (next_val >= 0) {
                ll cur_val = ((ll)(p_bit + q_bit)) << (B - 1 - pos);
                ll total_val = cur_val + next_val;
                if (total_val > best_val) {
                    best_val = total_val;
                    best_p = ((ll)p_bit << (B - 1 - pos)) + next_p;
                    best_q = ((ll)q_bit << (B - 1 - pos)) + next_q;
                }
            }
        }
        return dp[pos][tight_p][tight_q] = make_tuple(best_val, best_p, best_q);
    };
    return dfs(0, 0, 0);
}
tuple<ll, ll, ll> min_sum_ge(ll x, ll y) {
    vector<int> bx = get_bits(x);
    vector<int> by = get_bits(y);
    vector<vector<vector<tuple<ll, ll, ll>>>> dp(
        B + 1, vector<vector<tuple<ll, ll, ll>>>(
            2, vector<tuple<ll, ll, ll>>(2, make_tuple(LLONG_MAX, -1, -1))));
    function<tuple<ll, ll, ll>(int, int, int)> dfs = [&](int pos, int tight_p, int tight_q) -> tuple<ll, ll, ll> {
        if (pos == B) return make_tuple(0, 0, 0);
        if (get<0>(dp[pos][tight_p][tight_q]) != LLONG_MAX) return dp[pos][tight_p][tight_q];
        int xb = bx[pos];
        int yb = by[pos];
        ll best_val = LLONG_MAX, best_p = -1, best_q = -1;
        for (int mask = 0; mask < 3; mask++) {
            int p_bit = 0, q_bit = 0;
            if (mask == 1) p_bit = 1;
            else if (mask == 2) q_bit = 1;
            if (tight_p == 0 && p_bit < xb) continue;
            if (tight_q == 0 && q_bit < yb) continue;
            int new_tight_p = tight_p;
            int new_tight_q = tight_q;
            if (tight_p == 0 && p_bit > xb) new_tight_p = 1;
            if (tight_q == 0 && q_bit > yb) new_tight_q = 1;
            auto [next_val, next_p, next_q] = dfs(pos + 1, new_tight_p, new_tight_q);
            if (next_val != LLONG_MAX) {
                ll cur_val = ((ll)(p_bit + q_bit)) << (B - 1 - pos);
                ll total_val = cur_val + next_val;
                if (total_val < best_val) {
                    best_val = total_val;
                    best_p = ((ll)p_bit << (B - 1 - pos)) + next_p;
                    best_q = ((ll)q_bit << (B - 1 - pos)) + next_q;
                }
            }
        }
        return dp[pos][tight_p][tight_q] = make_tuple(best_val, best_p, best_q);
    };
    return dfs(0, 0, 0);
}
tuple<ll, ll, ll> min_diff_le_ge(ll x, ll y) {
    vector<int> bx = get_bits(x);
    vector<int> by = get_bits(y);
    vector<vector<vector<tuple<ll, ll, ll>>>> dp(
        B + 1, vector<vector<tuple<ll, ll, ll>>>(
            2, vector<tuple<ll, ll, ll>>(2, make_tuple(LLONG_MAX, -1, -1))));
    function<tuple<ll, ll, ll>(int, int, int)> dfs = [&](int pos, int tight_p, int tight_q) -> tuple<ll, ll, ll> {
        if (pos == B) return make_tuple(0, 0, 0);
        if (get<0>(dp[pos][tight_p][tight_q]) != LLONG_MAX) return dp[pos][tight_p][tight_q];
        int xb = bx[pos];
        int yb = by[pos];
        ll best_val = LLONG_MAX, best_p = -1, best_q = -1;
        for (int mask = 0; mask < 3; mask++) {
            int p_bit = 0, q_bit = 0;
            if (mask == 1) p_bit = 1;
            else if (mask == 2) q_bit = 1;
            if (tight_p == 0 && p_bit > xb) continue;
            if (tight_q == 0 && q_bit < yb) continue;
            int new_tight_p = tight_p;
            int new_tight_q = tight_q;
            if (tight_p == 0 && p_bit < xb) new_tight_p = 1;
            if (tight_q == 0 && q_bit > yb) new_tight_q = 1;
            auto [next_val, next_p, next_q] = dfs(pos + 1, new_tight_p, new_tight_q);
            if (next_val != LLONG_MAX) {
                ll cur_val = ((ll)(q_bit - p_bit)) << (B - 1 - pos);
                ll total_val = cur_val + next_val;
                if (total_val < best_val) {
                    best_val = total_val;
                    best_p = ((ll)p_bit << (B - 1 - pos)) + next_p;
                    best_q = ((ll)q_bit << (B - 1 - pos)) + next_q;
                }
            }
        }
        return dp[pos][tight_p][tight_q] = make_tuple(best_val, best_p, best_q);
    };
    return dfs(0, 0, 0);
}
int main() {
    freopen("a.in","r",stdin);
    freopen("b.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        ll x, y;
        cin >> x >> y;
        auto [max_sum_val1, p1, q1] = max_sum_le(x, y);
        ll costA = (x + y) - max_sum_val1;
        auto [min_sum_val4, p4, q4] = min_sum_ge(x, y);
        ll costD = min_sum_val4 - (x + y);
        auto [min_diff_val2, p2, q2] = min_diff_le_ge(x, y);
        ll costB = (x - y) + min_diff_val2;
        auto [min_diff_val3, p3, q3] = min_diff_le_ge(y, x);
        ll costC = (y - x) + min_diff_val3;
        ll min_cost = min({costA, costB, costC, costD});
        ll best_p, best_q;
        if (min_cost == costA) {
            best_p = p1;
            best_q = q1;
        } else if (min_cost == costB) {
            best_p = p2;
            best_q = q2;
        } else if (min_cost == costC) {
            best_p = q3;  
            best_q = p3;
        } else { 
            best_p = p4;
            best_q = q4;
        }
        // cout << best_p << " " << best_q << endl;
        cout<<min_cost<<endl;
    }
    return 0;
}