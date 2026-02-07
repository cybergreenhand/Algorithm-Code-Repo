#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e3+5,mod=998244353;
int T,n,m;
int a[N];
ll f[N][N];
vector<int> d[N];
inline void prework()
{
    for (int i=1;i<=3000;++i)
    {
        for (int j=i;j<=3000;j+=i)
        {
            d[j].push_back(i);
        }
    }
}
inline void solve()
{
    cin>>n>>m;
    for (int i=1;i<=n;++i) cin>>a[i];
    if (a[1]!=0&&a[1]!=1)
    {
        cout<<"0"<<endl;
        return;
    }
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            f[i][j]=0;
        }
    }
    f[1][1]=1;
    for (int i=1;i<n;++i)
    {
        if (a[i]!=0) 
        {
            if (!f[i][a[i]])
            {
                cout<<"0"<<endl;
                return;
            }
            for (int j:d[a[i]])
            {
                if (a[i]+j>m-n+i+1) break;
                f[i+1][a[i]+j]=(f[i+1][a[i]+j]+f[i][a[i]])%mod;
            }
        }
        else
        {
            for (int j=i;j<=m-n+i;++j)
            {
                if (f[i][j])
                {
                    for (int k:d[j])
                    {
                        if (j+k>m-n+i+1) break;
                        f[i+1][j+k]=(f[i+1][j+k]+f[i][j])%mod;
                    }
                }
            }
        }       
    }
    if (a[n]!=0) cout<<f[n][a[n]]<<endl;
    else
    {
        ll ans=0;
        for (int i=n;i<=m;++i) ans=(ans+f[n][i])%mod;
        cout<<ans<<endl;
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    prework();
    cin>>T;
    while (T--) solve();
    return 0;
}