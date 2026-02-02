#include <bits/stdc++.h>
using namespace std;
const int N=110,M=4e4+10;
int n,W,v,w,m,hh,tt;
int q[M],f[M],Q[M];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&W);
    for (int i=1;i<=n;++i) 
    {
        scanf ("%d%d%d",&v,&w,&m);
        if (m>(W/w)) m=W/w;
        for (int b=0;b<w;++b)
        {
            hh=0;
            tt=-1;
            for (int a=0;a<=(W-b)/w;++a)
            {
                while (hh<=tt&&a-q[hh]>m) ++hh;
                while (hh<=tt&&Q[tt]<=f[a*w+b]-a*v) --tt;
                q[++tt]=a;
                Q[tt]=f[a*w+b]-a*v;
                f[a*w+b]=Q[hh]+a*v;
            }
        }
        // for (int i=0;i<=W;++i) cout<<f[i]<<" ";
        // cout<<endl;
    }
    
    printf ("%d\n",f[W]);
    return 0;
}