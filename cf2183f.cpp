#include <bits/stdc++.h>
using namespace std;

void dfs1(int u,int x)
{
    fa[u]=x;
    for (int i=h[u];i;i=nxt[i])
    {
        int v=to[i];
        if (v==x) continue;
        dfs1(v,u);
    }
}
void dfs2(int u,int p)
{
    node[p][c[u]-'a'].push_back(u);
    for (int i=h[u];i;i=nxt[i])
    {
        int v=to[i];
        if (v==fa[u]) continue;
        dfs2(v,p);
    }
}
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--)
    {
        cin>>n;
        for (int i=1;i<=n;++i) cin>>c[i];
        for (int i=1;i<n;++i)
        {
            int u,v;
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        dfs1(1,0);
        for (int i=1;i<=n;++i) dfs2(i,i);
    }
    return 0;
}