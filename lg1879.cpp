#include <bits/stdc++.h>
using namespace std;
const int N=15,M=(1<<12)+5,mod=1e8;
int n,m,ans;
int f[N][M];
vector<int> val[N];
inline bool check(int x)
{
    if (x&(x>>1)) return false;
    return true;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
    {
        int sum=0;
        for (int j=0;j<m;++j)
        {
            int st;
            scanf ("%d",&st);
            sum+=((st^1)<<j);
        }
        for (int j=0;j<(1<<m);++j) if ((j&sum)==0&&check(j)) val[i].push_back(j);
    }
    for (int i:val[1]) f[1][i]=1;
    for (int i=2;i<=n;++i)
    {
        for (int j:val[i])
        {
            for (int k:val[i-1])
            {
                if (j&k) continue;
                f[i][j]=(f[i][j]+f[i-1][k])%mod;
            }
        }
    }
    for (int i:val[n]) ans=(ans+f[n][i])%mod;
    printf ("%d\n",ans);
    return 0;
}