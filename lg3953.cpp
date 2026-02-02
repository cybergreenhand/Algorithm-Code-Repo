#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=1e5+5,M=2e5+5;
int T,n,m,K,P,cnt,ncnt,ans;
int h[N],to[M],nxt[M],w[M],nh[N],nto[M],nw[M],nnxt[M],dis[N];
int f[N][55];
bool vis[N],flag[N][55];
struct Node{
    int p,d;
    bool operator< (const Node &t) const
    {
        return d>t.d;
    }
};
priority_queue<Node> q;
inline void clear()
{
    cnt=ncnt=ans=0;
    memset(h,0,sizeof (h));
    memset(nh,0,sizeof (nh));
    memset(f,-0x3f,sizeof (f));
    memset(flag,false,sizeof (flag));
}
inline void add(int a,int b,int c)
{
    to[++cnt]=b;
    nxt[cnt]=h[a];
    w[cnt]=c;
    h[a]=cnt;
}
inline void add_neg(int a,int b,int c)
{
    nto[++ncnt]=b;
    nnxt[ncnt]=nh[a];
    nw[ncnt]=c;
    nh[a]=ncnt;
}
inline void dijkstra()
{
    memset(vis,false,sizeof (vis));
    memset(dis,0x3f,sizeof (dis));
    dis[n]=0;
    q.push({n,0});
    while (q.size())
    {
        int u=q.top().p;
        q.pop();
        if (vis[u]) continue;
        vis[u]=true;
        for (int i=nh[u];i;i=nnxt[i])
        {
            int v=nto[i];
            if (dis[v]>dis[u]+nw[i])
            {
                dis[v]=dis[u]+nw[i];
                q.push({v,dis[v]});
            }
        }
    }
}
bool dfs(int u,int ex)
{
    if (flag[u][ex]) return false;
    if (f[u][ex]>=0) return true;
    flag[u][ex]=true;
    if (u==n&&ex==0) f[u][ex]=1;
    else f[u][ex]=0;
    for (int i=h[u];i;i=nxt[i])
    {
        int v=to[i],delt=dis[v]+w[i]-dis[u];
        if (delt<=ex) 
        {
            if (dfs(v,ex-delt)) f[u][ex]=(f[u][ex]+f[v][ex-delt])%P; 
            else return false;
        }
    }
    flag[u][ex]=false;
    return true;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&T);
    while (T--)
    {
        scanf ("%d%d%d%d",&n,&m,&K,&P);
        clear();
        for (int i=1;i<=m;++i)
        {
            int a,b,c;
            scanf ("%d%d%d",&a,&b,&c);
            add(a,b,c);
            add_neg(b,a,c);
        }
        dijkstra();
        for (int i=0;i<=K;++i)
        {
            if (dfs(1,i)) ans=(ans+f[1][i])%P;
            else 
            {
                ans=-1;
                break;
            }
        }
        printf ("%d\n",ans);
    }
    return 0;
}