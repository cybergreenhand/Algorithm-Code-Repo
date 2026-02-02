#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e7+5,M=3e5+5;
int n,m,l,r,s,e;
ll mx,ans;
ll a[2][N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=m;++i)
    {
        scanf ("%d%d%d%d",&l,&r,&s,&e);
        ll d=(e-s)/(r-l);
        a[0][l]+=s;
        a[0][r+1]-=e;
        a[1][l+1]+=d;
        a[1][r+1]-=d;
    }
    for (int i=1;i<=n;++i)
    {
        a[1][i]+=a[1][i-1];
        a[0][i]+=(a[1][i]+a[0][i-1]);
        mx=max(mx,a[0][i]);
        ans^=a[0][i];
    }
    printf ("%lld %lld\n",ans,mx);
    return 0;
}