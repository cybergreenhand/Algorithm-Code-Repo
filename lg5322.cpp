#include <bits/stdc++.h>
using namespace std;
const int N=105,M=2e4+5;
int s,n,m;
int a[N][N],f[M],cnt[N];
struct Sub{
    int v,w;
}g[N][N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d%d",&s,&n,&m);
    for (int i=1;i<=s;++i)
    {
        for (int j=1;j<=n;++j) 
        {
            scanf ("%d",&a[j][i]);
        }
    }
    for (int i=1;i<=n;++i)
    {
        sort(a[i]+1,a[i]+s+1);
        for (int j=1;j<=s;++j)
        {
            g[i][++cnt[i]].v=(a[i][j]<<1)+1;
            g[i][cnt[i]].w=i*j;
        }
    }
    for (int i=1;i<=n;++i)
    {
        for (int j=m;j>=0;--j)
        {
            for (int k=1;k<=cnt[i];++k)
            {
                if (j>=g[i][k].v) f[j]=max(f[j],f[j-g[i][k].v]+g[i][k].w);
            }
        }
    }
    printf ("%d\n",f[m]);
    return 0;
}