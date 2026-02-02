#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+5;
int T,n,H,R;
int fa[N],x[N],y[N],z[N];
inline ll dist(int i,int j)
{
    return 1ll*(x[i]-x[j])*(x[i]-x[j])+1ll*(y[i]-y[j])*(y[i]-y[j])+1ll*(z[i]-z[j])*(z[i]-z[j]);
}
inline int find(int x)
{
    if (x!=fa[x]) return fa[x]=find(fa[x]);
    return x;
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
    scanf ("%d",&T);
    while (T--)
    {
        scanf ("%d%d%d",&n,&H,&R);
        for (int i=1;i<=n;++i) 
        {
            scanf ("%d%d%d",&x[i],&y[i],&z[i]);
            fa[i]=i;
        }
        fa[0]=0;
        fa[n+1]=n+1;
        for (int i=1;i<=n;++i)
        {
            if (z[i]<=R) fa[i]=0;
            if (z[i]+R>=H) merge(i,n+1);
        }
        for (int i=1;i<n;++i)
        {
            for (int j=i+1;j<=n;++j)
            {
                if (dist(i,j)<=1ll*(R<<1)*(R<<1))
                {
                    merge(i,j);
                }
            }
        }
        int x=find(0),y=find(n+1);
        if (x==y) puts("Yes");
        else puts("No");
    }
    return 0;
}