#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,tot=1;
int a[N],b[N],del[N],to[N<<1],nxt[N<<1],idx[N<<1],deg[N];
bool vise[N];
vector<int> ans;
inline void add(int u,int v)
{
    to[++tot]=v;
    nxt[tot]=del[u];
    del[u]=tot;
}
void dfs(int u)
{
    for (int i=del[u];i>1;i=del[u])
    {
        del[u]=nxt[i];
        if (vise[idx[i]]) continue;
        vise[idx[i]]=true;
        if (i&1) ans.push_back(idx[i]);
        dfs(to[i]);
    }
}
inline void clear()
{
    tot=1;
    ans.clear();
    for (int i=1;i<=n;++i)
    {
        del[i]=0;
        deg[i]=0;
        vise[i]=false;
    }
}
inline void solve()
{
    cin>>n;
    clear();
    for (int i=1;i<=n;++i) cin>>a[i];
    for (int i=1;i<=n;++i) cin>>b[i];
    for (int i=1;i<=n;++i)
    {
        add(a[i],b[i]);
        idx[tot]=i;
        add(b[i],a[i]);
        idx[tot]=i;
        ++deg[a[i]];
        ++deg[b[i]];
    }
    for (int i=1;i<=n;++i) 
    {
        if (deg[i]&1)
        {
            cout<<"-1"<<endl;
            return;
        }
    }
    for (int i=1;i<=n;++i) dfs(i);
    cout<<ans.size()<<endl;
    for (int i:ans) cout<<i<<" ";
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