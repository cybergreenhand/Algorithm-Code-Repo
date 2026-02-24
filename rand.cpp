#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randint(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

// 随机生成操作类型，可根据需要调整概率
char rand_op() {
    int op = randint(0, 4);
    if (op == 0) return 'T';
    if (op == 1) return 'F';
    if (op == 2) return 'U';
    if (op == 3) return '+';
    return '-';
}

int main() {
    freopen("a.in","w",stdout);
    // 测试点编号（可设为0），数据组数t
    int c = 0, t = 6;
    cout << c << " " << t << "\n";
    
    for (int T = 1; T <= t; ++T) {
        int n = 10;
        int m = 10;
        cout << n << " " << m << "\n";
        
        for (int k = 1; k <= m; ++k) {
            char op = rand_op();
            if (op == 'T' || op == 'F' || op == 'U') {
                int i = randint(1, n);
                cout << op << " " << i << "\n";
            } else {
                int i = randint(1, n);
                int j = randint(1, n);
                cout << op << " " << i << " " << j << "\n";
            }
        }
    }
    return 0;
}