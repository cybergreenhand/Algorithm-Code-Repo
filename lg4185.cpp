#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int fa[N],s[N];
struct Tree{
    int a,b,c;
    bool operator< (const Tree &t) const
    {
        return c<t.c;
    }
}tr[N];
struct Query{
    int k,v,id,ans;
    bool operator< (const Query &t) const
    {
        return k<t.k;
    }
}q[N];
int find(int x)
{
    if (x!=fa[x]) return fa[x]=find(fa[x]);
    return fa[x];
}
inline void merge(int x,int y)
{
    int fx=find(x),fy=find(y);
    if (fx!=fy) 
    {
        fa[fx]=fy;
        s[fy]+=s[fx];
    }
}
inline bool cmp(Query a,Query b)
{
    return a.id<b.id;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;++i) 
    {
        fa[i]=i;
        s[i]=1;
    }
    for (int i=1;i<n;++i) scanf ("%d%d%d",&tr[i].a,&tr[i].b,&tr[i].c);
    for (int i=1;i<=m;++i) 
    {
        scanf ("%d%d",&q[i].k,&q[i].v);
        q[i].id=i;
    }
    sort(tr+1,tr+n);
    sort(q+1,q+m+1);
    for (int i=n-1,j=m;j>=1;--j)
    {
        while (i>=1&&tr[i].c>=q[j].k)
        {
            merge(tr[i].a,tr[i].b);
            --i;
        }
        q[j].ans=s[find(q[j].v)]-1;
    }
    sort(q+1,q+m+1,cmp);
    for (int i=1;i<=m;++i) printf ("%d\n",q[i].ans);
    return 0;
}