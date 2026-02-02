#include <bits/stdc++.h>
using namespace std;
const int N=4e4+5,M=1e5+5;
int n,m;
int fa[N];
struct Criminal{
    int x,y,z;
    bool operator< (const Criminal &t) const
    {
        return z<t.z;
    }
}c[M];
int find(int x)
{
    if (x!=fa[x]) return fa[x]=find(fa[x]);
    return fa[x];
}
inline void merge(int x,int y)
{
    int fx=find(x),fy=find(y);
    if (fx!=fy) fa[fx]=fy;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=(n<<1);++i) fa[i]=i;
    for (int i=1;i<=m;++i) scanf ("%d%d%d",&c[i].x,&c[i].y,&c[i].z);
    sort(c+1,c+m+1);
    for (int i=m;i>=1;--i)
    {
        merge(c[i].x,c[i].y+n);
        merge(c[i].x+n,c[i].y);
        int fx=find(c[i].x),fxn=find(c[i].x+n);
        if (fx==fxn)
        {
            printf ("%d\n",c[i].z);
            return 0;
        }
        int fy=find(c[i].y),fyn=find(c[i].y+n);
        if (fy==fyn)
        {
            printf ("%d\n",c[i].z);
            return 0;
        }
    }
    printf ("0\n");
    return 0;
}