#include <bits/stdc++.h>
using namespace std;
const int N=5e3+5,M=2e5+5;
int n,m,cnt,ans;
int fa[N];
struct Edge{
    int u,v,w;
    bool operator< (const Edge &t) const
    {
        return w<t.w;
    }
}edge[M];
int find(int x)
{
    if (x!=fa[x]) return fa[x]=find(fa[x]);
    return fa[x];
}
inline bool merge(int x,int y)
{
    int fx=find(x),fy=find(y);
    if (fx==fy) return false;
    fa[fx]=fy;
    --cnt;
    return true;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    cnt=n;
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
        int u=edge[i].u,v=edge[i].v,w=edge[i].w;
        if (merge(u,v)) ans+=w;
        if (cnt==1) break;
    }
    if (cnt==1) printf ("%d\n",ans);
    else printf ("orz\n");
    return 0;
}