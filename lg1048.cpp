#include <bits/stdc++.h>
using namespace std;
const int N=1e2+10,M=1e3+10;
int n,T,ans;
int v[N],w[N],f[M];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&T,&n);
    for (int i=1;i<=n;++i) scanf ("%d%d",&v[i],&w[i]);
    for (int i=1;i<=n;++i)
    {
        for (int j=T;j>=v[i];--j)
        {
            f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
    for (int i=1;i<=T;++i) ans=max(ans,f[i]);
    printf ("%d\n",ans);
    return 0;
}