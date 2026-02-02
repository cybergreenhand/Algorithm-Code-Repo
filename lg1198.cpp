#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int T,D,last,n;
int f[N][20];
signed main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%lld%lld\n",&T,&D);
    while (T--)
    {
        char op;
        int a;
        scanf ("%c %lld\n",&op,&a);
        if (op=='Q')
        {
            int k=log2(a);
            last=max(f[n-a+1][k],f[n-(1<<k)+1][k]);
            printf ("%lld\n",last);
        }
        else
        {
            a=(a+last)%D;
            ++n;
            f[n][0]=a;
            for (int j=1;(1<<j)<=n;++j) f[n-(1<<j)+1][j]=max(f[n-(1<<j)+1][j-1],f[n-(1<<j-1)+1][j-1]);
        }
    }
    return 0;
}