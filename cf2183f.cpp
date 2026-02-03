#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+5,mod=998244353;
int T,n,tot;
int in[N],out[N],d[N];
char a[N];
vector<int> to[N];
ll f[N][N],sum[N][N];
void dfs(int u,int fa)
{
    in[u]=++tot;
    d[tot]=u;
    for (int v:to[u])
    {
        if (v==fa) continue;
        dfs(v,u);
    }
    out[u]=tot;
}
inline void clear()
{
    tot=0;
    for (int i=1;i<=n;++i) 
    {
        to[i].clear();
        for (int j=1;j<=n;++j)
        {
            f[i][j]=0;
            sum[i][j]=0;
        }
    }
}
int main()
{
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--)
    {
        cin>>n;
        clear();
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<n;++i)
        {
            int u,v;
            cin>>u>>v;
            to[u].push_back(v);
            to[v].push_back(u);
        }
        dfs(1,0);
        for (int i=n;i>=1;--i)
        {
            for (int j=n;j>=1;--j)
            {
                if (a[d[i]]==a[d[j]])
                {
                    f[i][j]=(f[i][j]+sum[i+1][j+1])%mod;
                    f[i][j]=(f[i][j]-sum[i+1][out[d[j]]+1]+mod)%mod;
                    f[i][j]=(f[i][j]-sum[out[d[i]]+1][j+1]+mod)%mod;
                    f[i][j]=(f[i][j]+sum[out[d[i]]+1][out[d[j]]+1])%mod;
                    f[i][j]=(f[i][j]+1)%mod;
                }
                sum[i][j]=(sum[i+1][j]+sum[i][j+1]-sum[i+1][j+1]+f[i][j]+mod)%mod;
            }
        }
        for (int i=1;i<=n;++i) 
        {
            ll ans=sum[in[i]][in[i]];
            ans=(ans-sum[in[i]][out[i]+1]+mod)%mod;
            ans=(ans-sum[out[i]+1][in[i]]+mod)%mod;
            ans=(ans+sum[out[i]+1][out[i]+1])%mod;
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}