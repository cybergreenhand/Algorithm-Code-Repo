#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e5+5;
int n,m,T,cnt;
int dis[N],f[N],h[N],to[M],nxt[M],w[M];
bool vis[N];
struct Edge{
    int u,v,w;
}edge[M];
struct Point{
    int u,w;
    bool operator> (const Point &t) const
    {
        return w>t.w;
    }
};
priority_queue<Point,vector<Point>,greater<Point>> q;
inline void add(int x,int y,int z)
{
    to[++cnt]=y;
    nxt[cnt]=h[x];
    w[cnt]=z;
    h[x]=cnt;
}
inline void dijkstra()
{
    memset(dis,0x3f,sizeof (dis));
    memset(vis,false,sizeof (vis));
    q.push({1,0});
    dis[1]=0;
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
                q.push({v,dis[v]});
            }
        }
    }
}
inline bool check(int line)
{
    cnt=0;
    memset(h,0,sizeof (h));
    memset(nxt,0,sizeof (nxt));
    for (int i=1;i<=m;++i)
    {
        int u=edge[i].u,v=edge[i].v,w=edge[i].w;
        if (f[u]>line||f[v]>line) continue;
        add(u,v,w);
        add(v,u,w);
    }
    dijkstra();
    return dis[n]<=T;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d%d",&n,&m,&T);
    int l=1,r=0;
    for (int i=1;i<=n;++i) 
    {
        scanf ("%d",&f[i]);
        r=max(r,f[i]);
    }
    for (int i=1;i<=m;++i)
    {
        int a,b,c;
        scanf ("%d%d%d",&a,&b,&c);
        edge[i]={a,b,c};
    }
    if (!check(r))
    {
        printf ("AFK\n");
        return 0;
    }
    while (l<r)
    {
        int mid=l+r>>1;
        if (check(mid)) r=mid;
        else l=mid+1;
    }
    printf ("%d\n",r);
    return 0;
}