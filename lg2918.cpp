#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,h,ans=0x7f7f7f7f;
int p[110],c[110],f[N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&h);
    for (int i=1;i<=n;++i) scanf ("%d%d",&p[i],&c[i]);
    memset(f,0x7f,sizeof(f));
    f[0]=0;
    for (int i=1;i<=n;++i)
    {
        for (int j=p[i];j<=(h<<1);++j)
        {
            f[j]=min(f[j],f[j-p[i]]+c[i]);
        }
    }
    for (int i=h;i<=(h<<1);++i) ans=min(ans,f[i]);
    printf ("%d\n",ans);
    return 0;
}