#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n;
int a[N],sz[N],f[N];
bool vis[N];
vector<int> node,to[N],g[N],ans;
void dfs1(int u,int fa)
{
    for (int v:to[u])
    {
        if (v==fa) continue;
        if (a[v]&&a[u]) 
        {
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs1(v,u);
    }
}
void dfs2(int u,int fa)
{
    sz[u]=1;
    node.push_back(u);
    for (int v:g[u])
    {
        if (v==fa) continue;
        dfs2(v,u);
        sz[u]+=sz[v];
        if (sz[v]&1) ++f[v];
        else ++f[u];
    }
}
inline void clear()
{
    ans.clear();
    for (int i=1;i<=n;++i)
    {
        to[i].clear();
        g[i].clear();
        vis[i]=false;
        f[i]=0;
        sz[i]=0;
    }
}
inline void solve()
{
    cin>>n;
    clear();
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        a[i]&=1;
    }
    for (int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    for (int i=1;i<=n;++i) 
    {
        int sum=0;
        for (int j:to[i]) sum^=a[j];
        if (!a[i]&&sum!=a[i])
        {
            ans.push_back(i);
            vis[i]=true;
        }
    }
    dfs1(1,0);
    for (int i=1;i<=n;++i)
    {
        if (vis[i]||!a[i]) continue;
        node.clear();
        dfs2(i,0);
        if (sz[i]%2==0)
        {
            cout<<"NO"<<endl;
            return;
        }
        queue<int> q;
        for (int i:node) 
        {
            if (!f[i]) 
            {
                q.push(i);
                vis[i]=true;
            }
        }
        while (q.size())
        {
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for (int v:to[u])
            {
                if (!vis[v]&&!a[v])
                {
                    vis[v]=true;
                    ans.push_back(v);
                }
            }
            for (int v:g[u])
            {
                --f[v];
                if (!f[v]) 
                {
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
    }
    if (ans.size()!=n) cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        for (int i:ans) cout<<i<<" ";
        cout<<endl;
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while (T--) solve();
    return 0;
}