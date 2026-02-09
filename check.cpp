#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int fa[N];
bool vis[N];
vector<int> node,to[N];
inline void clear()
{
    for (int i=1;i<=n;++i) to[i].clear();
}
void dfs(int u,int f)
{
    fa[u]=f;
    for (int v:to[u])
    {
        if (v==f) continue;
        dfs(v,u);
    }
}
inline void solve(int T)
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
    cin>>m;
    int sum=0;
    for (int i=1;i<=m;++i)
    {
        for (int i=1;i<=n;++i) vis[i]=false;
        node.clear();
        int x;
        cin>>x;
        sum+=x;
        for (int j=1;j<=x;++j)
        {
            int u;
            cin>>u;
            vis[u]=true;
            node.push_back(u);
        }
        for (int j:node) 
        {
            if (vis[fa[j]])
            {
                cout<<"WRONG ON "<<T<<endl;
                return;
            }
        }
    }
    if (sum!=n)
    {
        cout<<"WRONG ON "<<T<<endl;
        return;
    }
    cout<<"CORRECT ON "<<T<<endl;
}
int main()
{
    freopen("a.out","r",stdin);
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    for (int i=1;i<=T;++i) solve(i);
    return 0;
}