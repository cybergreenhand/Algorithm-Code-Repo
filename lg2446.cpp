#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e3+5,M=7e4+5;
int n,m,cnt;
int in[N],to[M],nxt[M],h[N],w[M];
ll dis[N],dism[N];
bool vis[N];
struct Point{
    int u;
    ll edge;
    bool operator> (const Point &t) const
    {
        return edge>t.edge;
    }
};
priority_queue<Point,vector<Point>,greater<Point>> q;
vector<int> pt[N];
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
    q.push({1,0});
    dis[1]=0;
    while (q.size())
    {
        int u=q.top().u;
        q.pop();
        // cout<<u<<endl;
        if (vis[u]) continue;
        vis[u]=true;
        for (int i=h[u];i;i=nxt[i])
        {
            int v=to[i];
            if (vis[v]) continue;
            dis[v]=min(dis[v],dis[u]+w[i]);
            if (!in[v]) 
            {
                dis[v]=max(dis[v],dism[v]);
                q.push({v,dis[v]});
            }
        }
        for (int v:pt[u])
        {
            --in[v];
            dism[v]=max(dism[v],dis[u]);
            if (!in[v])
            {
                dis[v]=max(dis[v],dism[v]);
                q.push({v,dis[v]});
            }
        }
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=m;++i)
    {
        int u,v,w;
        scanf ("%d%d%d",&u,&v,&w);
        if (u==v) continue;
        add(u,v,w);
    }
    for (int i=1;i<=n;++i)
    {
        int c;
        scanf ("%d",&c);
        in[i]+=c;
        for (int j=1;j<=c;++j)
        {
            int id;
            scanf ("%d",&id);
            pt[id].push_back(i);
        }
    }
    dijkstra();
    // for (int i=1;i<=n;++i) cout<<i<<" "<<dis[i]<<" "<<dism[i]<<endl;
    printf ("%lld\n",dis[n]);
    return 0;
}