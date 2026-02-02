#include <bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,m,q,cnt;
int fa[N],d[N],h[N],to[N<<1],nxt[N<<1],c[N];
bool vis[N];
inline void add(int a,int b)
{
    to[++cnt]=b;
    nxt[cnt]=h[a];
    h[a]=cnt;
}
int find(int x)
{
    if (x!=fa[x]) return fa[x]=find(fa[x]);
    return fa[x];
}
inline void merge(int x,int y)
{
    int fx=find(x),fy=find(y);
    if (fx==fy) return;
    fa[fx]=fy;
    c[fy]=max({c[fx],c[fy],(c[fx]+1)/2+(c[fy]+1)/2+1});
}
void dfs(int u,int f)
{
    vis[u]=true;
    if (f) fa[u]=f;
    int x=find(u);
    for (int i=h[u];i;i=nxt[i])
    {
        int v=to[i];
        if (v==f) continue;
        dfs(v,u);
        c[x]=max(c[x],d[u]+d[v]+1);
        d[u]=max(d[u],d[v]+1);
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d%d",&n,&m,&q);
    for (int i=1;i<=n;++i) fa[i]=i;
    for (int i=1;i<=m;++i)
    {
        int x,y;
        scanf ("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    for (int i=1;i<=n;++i) if (!vis[i]) dfs(i,0);
    while (q--)
    {
        int opt;
        scanf ("%d",&opt);
        if (opt==1)
        {
            int x;
            scanf ("%d",&x);
            printf ("%d\n",c[find(x)]);
        }
        else
        {
            int x,y;
            scanf ("%d%d",&x,&y);
            merge(x,y);
        }
    }
    return 0;
}