#include <bits/stdc++.h>
using namespace std;
const int N=205,M=2e4+5;
const double eps=1e-7;
int n,m,cnt;
double ans=2e9;
int h[N],to[M],nxt[M],x[N],y[N],pre[N];
bool vis[N];
double dis[N],w[M];
struct Edge{
    int u,v;
}edge[M];
struct Point{
    int u;
    double w;
    bool operator> (const Point &t) const
    {
        return w>t.w+eps;
    }
};
inline double getd(Edge e)
{
    return sqrt(1.0*(x[e.u]-x[e.v])*(x[e.u]-x[e.v])+1.0*(y[e.u]-y[e.v])*(y[e.u]-y[e.v]));
}
inline bool same(Edge e,int id)
{
    if (e.u==id&&e.v==pre[id]) return true;
    else if (e.u==pre[id]&&e.v==id) return true;
    return false;
}
inline void add(int a,int b,double c)
{
    to[++cnt]=b;
    nxt[cnt]=h[a];
    w[cnt]=c;
    h[a]=cnt;
}
inline void dijkstra(bool flag)
{
    memset(vis,false,sizeof (vis));
    for (int i=1;i<=n;++i) dis[i]=2e9;
    priority_queue<Point,vector<Point>,greater<Point>> q;
    q.push({1,dis[1]=0});
    while (q.size())
    {
        int u=q.top().u;
        q.pop();
        if (vis[u]) continue;
        vis[u]=true;
        for (int i=h[u];i;i=nxt[i])
        {
            int v=to[i];
            if (dis[v]>dis[u]+w[i])
            {
                dis[v]=dis[u]+w[i];
                if (flag) pre[v]=u;
                q.push({v,dis[v]});
            }
        }
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;++i) scanf ("%d%d",&x[i],&y[i]);
    for (int i=1;i<=m;++i) 
    {
        scanf ("%d%d",&edge[i].u,&edge[i].v);
        if (edge[i].u==edge[i].v) continue;
        add(edge[i].u,edge[i].v,getd(edge[i]));
        add(edge[i].v,edge[i].u,getd(edge[i]));
    }
    dijkstra(true);
    for (int i=n;pre[i]>=1;i=pre[i])
    {
        cnt=0;
        memset(h,0,sizeof (h));
        memset(nxt,0,sizeof (nxt));
        for (int j=1;j<=m;++j)
        {
            if (same(edge[j],i)) continue;
            if (edge[j].u==edge[j].v) continue;
            add(edge[j].u,edge[j].v,getd(edge[j]));
            add(edge[j].v,edge[j].u,getd(edge[j]));
        }
        dijkstra(false);
        ans=min(ans,dis[n]);
    }
    if (ans<2e9) printf ("%.2lf\n",ans);
    else printf ("-1\n");
    return 0;
}