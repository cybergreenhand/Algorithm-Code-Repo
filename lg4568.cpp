#include <bits/stdc++.h>
using namespace std;
const int N=1.1e5+5,M=2.1e6+5;
int n,m,T,cnt,s,t;
int dis[N],h[N],to[M],nxt[M],w[M];
bool vis[N];
struct Point{
    int u,w;
    bool operator> (const Point &t) const
    {
        return w>t.w;
    }
};
priority_queue<Point,vector<Point>,greater<Point>> q;
inline void add(int a,int b,int c)
{
    to[++cnt]=b;
    nxt[cnt]=h[a];
    w[cnt]=c;
    h[a]=cnt;
}
inline void dijkstra()
{
    memset(dis,0x3f,sizeof (dis));
    q.push({s,dis[s]=0});
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
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d%d%d%d",&n,&m,&T,&s,&t);
    ++s,++t;
    for (int i=1;i<=m;++i) 
    {
        int a,b,c;
        scanf ("%d%d%d",&a,&b,&c);
        ++a,++b;
        add(a,b,c);
        add(b,a,c);
        for (int j=1;j<=T;++j)
        {
            add(a+(j-1)*n,b+j*n,0);
            add(b+(j-1)*n,a+j*n,0);
            add(a+j*n,b+j*n,c);
            add(b+j*n,a+j*n,c);
        }
    }
    dijkstra();
    int ans=0x3f3f3f3f;
    for (int i=0;i<=T;++i) ans=min(ans,dis[t+i*n]);
    printf ("%d\n",ans);
    return 0;
}