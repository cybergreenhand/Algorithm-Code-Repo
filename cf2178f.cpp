#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,mod=998244353;
int n;
int sz[N],fa[N];
ll fac[N],inv[N];
bool wh[N];
vector<int> to[N],bk;
inline ll ksm(int a,int b)
{
    ll res=1;
    while (b)
    {
        if (b&1) res=res*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    return res;
}
inline void prework()
{
    fac[0]=1;
    for (int i=1;i<=2e5;++i) 
    {
        fac[i]=fac[i-1]*i%mod;
        inv[i]=ksm(i,mod-2);
    }
}
inline void clear()
{
    bk.clear();
    for (int i=1;i<=n;++i)
    {
        to[i].clear();
        wh[i]=false;
    }
}
void dfs(int u,int f)
{
    sz[u]=1;
    fa[u]=f;
    for (int v:to[u])
    {
        if (v==f) continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
    if (sz[u]%2==0) wh[u]=true;
}
void dfs(int u)
{
    sz[u]=1;
    for (int v:to[u])
    {
        if (v==fa[u]||wh[v]) continue;
        dfs(v);
        sz[u]+=sz[v];
    }
}
inline void solve()
{
    cin>>n;
    clear();
    for (int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    dfs(1,0);
    for (int i=1;i<=n;++i)
    {
        if (wh[i])
        {
            dfs(i);
            if (i!=1) bk.push_back(i);
        }
    }
    if (!wh[1]) dfs(1);
    if (bk.empty())
    {
        cout<<"1"<<endl;
        return;
    }
    ll ans=sz[1]*fac[bk.size()-1]%mod;
    for (int i:bk) ans=ans*sz[i]%mod*sz[i]%mod;
    ll sum=0;
    for (int i:bk) sum=(sum+inv[sz[i]])%mod;
    ans=ans*sum%mod;
    cout<<ans<<endl;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    prework();
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}