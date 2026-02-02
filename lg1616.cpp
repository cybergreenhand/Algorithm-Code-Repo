#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5,M=1e7+5;
int T,n;
ll ans;
int v[N],w[N];
ll f[M];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&T,&n);
    for (int i=1;i<=n;++i) scanf ("%d%d",&v[i],&w[i]);
    for (int i=1;i<=n;++i)
    {
        for (int j=v[i];j<=T;++j)
        {
            f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
    for (int i=1;i<=T;++i) ans=max(ans,f[i]);
    printf ("%lld\n",ans);
    return 0;
}