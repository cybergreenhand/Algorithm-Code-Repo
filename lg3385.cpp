#include <bits/stdc++.h>
using namespace std;
const int N=2e3+5,M=6e3+5;
int n,m,T,cnt;
int dis[N],h[N],sum[N],to[M],nxt[M],w[M];
bool vis[N];
inline void add(int a,int b,int c)
{
    to[++cnt]=b;
    nxt[cnt]=h[a];
    w[cnt]=c; 
    h[a]=cnt;
}
inline bool bellmanford()
{
    queue<int> q;
    memset(dis,0x3f,sizeof (dis));
    memset(sum,0,sizeof (sum));
    memset(vis,false,sizeof (vis));
    dis[1]=0;
    q.push(1);
    vis[1]=true;
    while (q.size())
    {
        int u=q.front();
        q.pop();
        vis[u]=false;
        ++sum[u];
        if (sum[u]>=n) return true;
        for (int i=h[u];i;i=nxt[i])
        {
            int v=to[i];
            if (dis[v]>dis[u]+w[i])
            {
                dis[v]=dis[u]+w[i];
                if (!vis[v])
                {
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
    return false;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&T);
    while (T--)
    {
        scanf ("%d%d",&n,&m);
        cnt=0;
        memset(h,0,sizeof (h));
        memset(nxt,0,sizeof (nxt));
        for (int i=1;i<=m;++i)
        {
            int u,v,w;
            scanf ("%d%d%d",&u,&v,&w);
            if (w>=0) 
            {
                add(u,v,w);
                add(v,u,w);
            }
            else add(u,v,w);
        }
        if (bellmanford()) printf ("YES\n");
        else printf ("NO\n");
    }
    return 0;
}