#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5,mod=998244353;
int T,n,m;
ll f[N],a[N];
struct Edge{
    int u,v;
}e[N];
vector<int> out[N];
map<ll,ll> sum[N];
inline bool cmp(int i,int j)
{
    return a[e[i].v]<a[e[j].v];
}
inline void clear()
{
    for (int i=1;i<=m;++i) f[i]=0;
    for (int i=1;i<=n;++i) 
    {
        out[i].clear();
        sum[i].clear();
    }
}
ll calc(int i)
{
    if (f[i]) return f[i];
    f[i]=1;
    if (out[e[i].v].empty()) return f[i];
    ll s=a[e[i].u]+a[e[i].v];
    if (sum[e[i].v][s]) f[i]=(f[i]+sum[e[i].v][s])%mod;
    else
    {
        int l=0,r=out[e[i].v].size()-1;
        while (l<r)
        {
            int mid=l+r>>1;
            if (a[e[out[e[i].v][mid]].v]<s) l=mid+1;
            else r=mid;
        }
        for (int j=r;j<out[e[i].v].size();++j)
        {
            if (a[e[out[e[i].v][j]].v]==s) sum[e[i].v][s]=(sum[e[i].v][s]+calc(out[e[i].v][j]))%mod;
            else break;
        }
        f[i]=(f[i]+sum[e[i].v][s])%mod;
    }
    return f[i];
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--)
    {
        cin>>n>>m;
        clear();
        for (int i=1;i<=n;++i) cin>>a[i];
        for (int i=1;i<=m;++i)
        {
            cin>>e[i].u>>e[i].v;
            out[e[i].u].push_back(i);
        }
        for (int i=1;i<=n;++i) sort(out[i].begin(),out[i].end(),cmp);
        ll ans=0;
        for (int i=1;i<=m;++i) ans=(ans+calc(i))%mod;
        cout<<ans<<endl;
    }
    return 0;
}