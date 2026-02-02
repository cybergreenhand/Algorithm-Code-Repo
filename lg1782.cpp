#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5;
int n,m,C,hh,tt,a,b,c,v,w,d;
int q[N];
ll f[N],Q[N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d%d",&n,&m,&C);
    for (int i=1;i<=n;++i)
    {   
        scanf ("%d%d%d",&v,&w,&d);
        if (d>C/v) d=C/v;
        for (int mod=0;mod<v;++mod)
        {
            hh=0;
            tt=-1;
            for (int k=0;k<=(C-mod)/v;++k)
            {
                while (hh<=tt&&k-q[hh]>d) ++hh;
                while (hh<=tt&&Q[tt]<=f[k*v+mod]-k*w) --tt;
                q[++tt]=k;
                Q[tt]=f[k*v+mod]-k*w;
                f[k*v+mod]=Q[hh]+k*w;
            }
        }
    }
    for (int i=1;i<=m;++i) 
    {
        scanf ("%d%d%d",&a,&b,&c);
        for (int j=C;j>=0;--j)
        {
            for (int k=0;k<=j;++k)
            {
                f[j]=max(f[j],f[j-k]+1ll*a*k*k+b*k+c);
            }
        }
    }
    printf ("%lld\n",f[C]);
    return 0;
}