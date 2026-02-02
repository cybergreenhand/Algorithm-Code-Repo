#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=6e3+5;
int T,n;
ll ans;
int fa[N],sz[N];
struct Edge{
    int u,v,w;
    bool operator< (const Edge &t) const
    {
        return w<t.w;
    }
}edge[N];
int find(int x)
{
    if (x!=fa[x]) return fa[x]=find(fa[x]);
    return fa[x];
}
inline void merge(int x,int y,int z)
{
    int fx=find(x),fy=find(y);
    ans+=1ll*(sz[fx]*sz[fy]-1)*(z+1);
    fa[fx]=fy;
    sz[fy]+=sz[fx];
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&T);
    while (T--)
    {
        scanf ("%d",&n);
        for (int i=1;i<=n;++i) fa[i]=i,sz[i]=1;
        for (int i=1;i<n;++i)
        {
            int x,y,z;
            scanf ("%d%d%d",&x,&y,&z);
            edge[i]={x,y,z};
        }
        sort(edge+1,edge+n);
        ans=0;
        for (int i=1;i<n;++i)
        {
            int u=edge[i].u,v=edge[i].v,w=edge[i].w;
            merge(u,v,w);
        }
        printf ("%lld\n",ans);
    }
    return 0;
}