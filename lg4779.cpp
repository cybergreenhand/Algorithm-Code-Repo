#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=2e5+5;
int n,m,s,cnt;
int dis[N],to[M],h[M],nxt[M],edge[M];
bool vis[N];
struct Point{
    int u,d;
    bool operator> (const Point &t) const
    {
        return d>t.d;
    }
};
inline void add(int u,int v,int w)
{
    to[++cnt]=v;
    nxt[cnt]=h[u];
    h[u]=cnt;
    edge[cnt]=w;
}
inline void dijkstra()
{
    for (int i=1;i<=n;++i) dis[i]=INT_MAX;
    priority_queue<Point,vector<Point>,greater<Point>> q;
    q.push({s,0});
    dis[s]=0;
    while (q.size())
    {
        int u=q.top().u;
        q.pop();
        if (vis[u]) continue;
        vis[u]=true;
        for (int i=h[u];i;i=nxt[i])
        {
            int v=to[i];
            if (dis[v]>dis[u]+edge[i])
            {
                dis[v]=dis[u]+edge[i];
                q.push({v,dis[v]});
            }
        }
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d%d",&n,&m,&s);
    for (int i=1;i<=m;++i)
    {
        int u,v,w;
        scanf ("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    dijkstra();
    for (int i=1;i<=n;++i) printf ("%d ",dis[i]);
    return 0;
}