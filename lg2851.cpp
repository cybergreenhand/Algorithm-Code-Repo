#include <bits/stdc++.h>
using namespace std;
const int N=105,M=2e4+5;
int n,T,hh,tt;
int v[N],c[N],f[M],q[M],Q[M];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&T);
    for (int i=1;i<=n;++i) scanf ("%d",&v[i]);
    for (int i=1;i<=n;++i) scanf ("%d",&c[i]);
    memset(f,0x3f,sizeof (f));
    f[0]=0;
    for (int i=1;i<=n;++i)
    {
        if (c[i]>(T<<1)/v[i]) c[i]=(T<<1)/v[i];
        for (int mod=0;mod<v[i];++mod)
        {
            hh=1;
            tt=0;
            for (int k=0;k<=((T<<1)-mod)/v[i];++k)
            {
                while (hh<=tt&&k-q[hh]>c[i]) ++hh;
                while (hh<=tt&&Q[tt]>=f[k*v[i]+mod]-k) --tt;
                q[++tt]=k;
                Q[tt]=f[k*v[i]+mod]-k;
                f[k*v[i]+mod]=Q[hh]+k;
            }
        }
    }
    for (int i=1;i<=n;++i)
    {
        for (int j=(T<<1)-v[i];j>=0;--j)
        {
            f[j]=min(f[j],f[j+v[i]]+1);
        }
    }
    if (f[T]<0x3f3f3f3f) printf ("%d\n",f[T]);
    else puts("-1");
    return 0;
}