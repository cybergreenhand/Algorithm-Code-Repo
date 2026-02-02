#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5,M=6e5+5;
int n,m,K,T,cnt;
int h[N],to[M],nxt[M],w[M],inr[N];
ll dis[N];
bool vis[N];
struct Edge{
    int u,v,w;
}edge[M];
struct Point{
    int u;
    ll w;
    bool operator> (const Point &t) const
    {
        return w>t.w;
    }
};
priority_queue<Point,vector<Point>,greater<Point>> q;
inline void clear()
{
    cnt=0;
    memset(h,0,sizeof (h));
    memset(nxt,0,sizeof (nxt));
}
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
    memset(vis,false,sizeof (vis));
    q.push({0,dis[0]=0});
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
    scanf ("%d",&T);
    while (T--)
    {
        scanf ("%d%d%d",&n,&m,&K);
        for (int i=1;i<=m;++i)
        {
            int x,y,z;
            scanf ("%d%d%d",&x,&y,&z);
            edge[i]={x,y,z};
        }
        for (int i=1;i<=K;++i) scanf ("%d",&inr[i]);
        ll ans=LONG_LONG_MAX;
        for (int i=0;(1<<i)<=n;++i)
        {
            clear();
            for (int j=1;j<=K;++j)
            {
                if (inr[j]&(1<<i)) 
                {
                    add(0,inr[j],0);
                    // cout<<inr[j]<<" TYPE IS 0"<<endl;
                }
                else 
                {
                    add(inr[j],n+1,0);
                    // cout<<inr[j]<<" TYPE IS 1"<<endl;
                }
            }
            for (int j=1;j<=m;++j)
            {
                int x=edge[j].u,y=edge[j].v,z=edge[j].w;
                if (x==y) continue;
                add(x,y,z);
            }
            dijkstra();
            ans=min(ans,dis[n+1]);
            // cout<<dis[n+1]<<endl;
        }
        for (int i=0;(1<<i)<=n;++i)
        {
            clear();
            for (int j=1;j<=K;++j)
            {
                if (inr[j]&(1<<i)) 
                {
                    add(inr[j],n+1,0);
                    // cout<<inr[j]<<" TYPE IS 1"<<endl;
                }
                else 
                {
                    add(0,inr[j],0);
                    // cout<<inr[j]<<" TYPE IS 0"<<endl;
                }
            }
            for (int j=1;j<=m;++j)
            {
                int x=edge[j].u,y=edge[j].v,z=edge[j].w;
                if (x==y) continue;
                add(x,y,z);
            }
            dijkstra();
            ans=min(ans,dis[n+1]);
            // cout<<dis[n+1]<<endl;
        }
        // cout<<endl;
        printf ("%lld\n",ans);
    }
    return 0;
}