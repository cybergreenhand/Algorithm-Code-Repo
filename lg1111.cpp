#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5,M=1e5+5;
int n,m,cnt;
int fa[N];
struct Edge{
    int x,y,t;
    bool operator< (const Edge &a) const
    {
        return t<a.t;
    }
}edge[M];
inline int find(int x)
{
    if (x!=fa[x]) return fa[x]=find(fa[x]);
    return x;
}
inline void merge(int x,int y)
{
    int fx=find(x),fy=find(y);
    if (fx!=fy)
    {
        fa[fx]=fy;
        --cnt;
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    cnt=n;
    for (int i=1;i<=m;++i) scanf ("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].t);
    for (int i=1;i<=n;++i) fa[i]=i;
    sort(edge+1,edge+m+1);
    for (int i=1;i<=m;++i)
    {
        merge(edge[i].x,edge[i].y);
        if (cnt==1)
        {
            printf ("%d\n",edge[i].t);
            return 0;
        }
    }
    printf ("-1\n");
    return 0;
}