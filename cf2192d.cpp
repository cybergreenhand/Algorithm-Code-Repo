#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n;
int a[N],fd[N],sd[N];
ll sum[N],f[N],g[N];
vector<int> to[N];
inline void clear()
{
    for (int i=1;i<=n;++i)
    {
        to[i].clear();
        fd[i]=sd[i]=0;
        sum[i]=f[i]=g[i]=0;
    }
}
void dfs(int u,int fa)
{
    sum[u]=a[u];
    for (int v:to[u])
    {
        if (v==fa) continue;
        dfs(v,u);
        sum[u]+=sum[v];
        g[u]+=g[v]+sum[v];
        sd[u]=max(sd[u],fd[v]+1);
        if (sd[u]>fd[u]) swap(sd[u],fd[u]);
    }
    for (int v:to[u])
    {
        if (v==fa) continue;
        int maxd=fd[u];
        if (fd[v]+1==fd[u]) maxd=sd[u];
        f[u]=max(f[u],g[u]+max(f[v]-g[v],maxd*sum[v]));
    }
}
inline void solve()
{
    cin>>n;
    clear();
    for (int i=1;i<=n;++i) cin>>a[i];
    for (int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    dfs(1,0);
    // for (int i=1;i<=n;++i) cout<<g[i]<<" ";
    // cout<<endl;
    // for (int i=1;i<=n;++i) cout<<sum[i]<<" ";
    // cout<<endl;
    // for (int i=1;i<=n;++i) cout<<fd[i]<<" "<<sd[i]<<endl;
    for (int i=1;i<=n;++i) cout<<f[i]<<" ";
    cout<<endl;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}