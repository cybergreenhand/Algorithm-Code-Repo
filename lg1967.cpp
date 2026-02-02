#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=5e4+5;
int n,m,Q,cnt;
int fa[N],d[N],f[N][20],g[N][20],h[N],to[N<<1],nxt[N<<1],w[N<<1];
bool vis[N];
struct Edge{
    int u,v,w;
    bool operator< (const Edge &t) const
    {
        return w>t.w;
    }
}edge[M];
inline void add(int a,int b,int c)
{
    to[++cnt]=b;
    nxt[cnt]=h[a];
    w[cnt]=c;
    h[a]=cnt;
}
int find(int x)
{
    if (x!=fa[x]) return fa[x]=find(fa[x]);
    return fa[x];
}
inline void merge(int x,int y,int z)
{
    int fx=find(x),fy=find(y);
    if (fx==fy) return;
    add(x,y,z);
    add(y,x,z);
    fa[fx]=fy;
}
void dfs(int u,int fa)
{
    vis[u]=true;
    for (int i=h[u];i;i=nxt[i])
    {
        int v=to[i];
        if (v==fa) continue;
        f[v][0]=u;
        g[v][0]=w[i];
        d[v]=d[u]+1;
        dfs(v,u);
    }
}
inline int lca(int x,int y)
{
    if (find(x)!=find(y)) return -1;
    int ans=1e9;
    if (d[x]<d[y]) swap(x,y);
    int dh=d[x]-d[y];
    for (int i=0;dh;++i)
    {
        if (dh&1) 
        {
            ans=min(ans,g[x][i]);
            x=f[x][i];
        }
        dh>>=1;
    }
    if (x==y) return ans;
    for (int i=log2(n);i>=0;--i)
    {
        if (f[x][i]!=f[y][i])
        {
            ans=min({ans,g[x][i],g[y][i]});
            x=f[x][i];
            y=f[y][i];
        }
    }
    ans=min({ans,g[x][0],g[y][0]});
    return ans;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;++i) fa[i]=i;
    for (int i=1;i<=m;++i)
    {
        int x,y,z;
        scanf ("%d%d%d",&x,&y,&z);
        edge[i]={x,y,z};
    }
    sort(edge+1,edge+m+1);
    for (int i=1;i<=m;++i)
    {
        int u=edge[i].u,v=edge[i].v;
        merge(u,v,edge[i].w);
    }
    for (int i=1;i<=n;++i) if (!vis[i]) dfs(i,0);
    for (int j=1;(1<<j)<=n;++j)
    {
        for (int i=1;i<=n;++i)
        {
            f[i][j]=f[f[i][j-1]][j-1];
            g[i][j]=min(g[i][j-1],g[f[i][j-1]][j-1]);
        }
    }
    scanf ("%d",&Q);
    while (Q--)
    {
        int x,y;
        scanf ("%d%d",&x,&y);
        printf ("%d\n",lca(x,y));
    }
    return 0;
}