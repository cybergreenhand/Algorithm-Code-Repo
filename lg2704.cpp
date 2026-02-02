#include <bits/stdc++.h>
using namespace std;
const int N=105,M=1030;
int n,m,ans;
int f[2][M][M];
vector<int> val[N];
inline bool check(int x)
{
    if ((x&(x>>1))||(x&(x>>2))) return false;
    return true;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
    {
        string land;
        cin>>land;
        int sum=0;
        for (int j=0;j<m;++j) if (land[j]=='H') sum+=(1<<j);
        for (int j=0;j<(1<<m);++j) if ((j&sum)==0&&check(j)) val[i].push_back(j);
    }
    val[0].push_back(0);
    for (int i:val[1]) f[1][i][0]=__builtin_popcount(i);
    for (int i=2;i<=n;++i)
    {
        memset(f[i&1],0,sizeof (f[i&1]));
        for (int cur:val[i])
        {
            for (int j:val[i-1])
            {
                if (cur&j) continue;
                int maxf=0;
                for (int k:val[i-2])
                {
                    if ((cur&k)||(j&k)) continue;
                    maxf=max(maxf,f[i-1&1][j][k]);
                }
                f[i&1][cur][j]=maxf+__builtin_popcount(cur);
            }
        }
    }
    for (int i:val[n])
    {
        for (int j:val[n-1])
        {
            if (i&j) continue;
            ans=max(ans,f[n&1][i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}