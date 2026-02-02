#include <bits/stdc++.h>
using namespace std;
#define ll long long
int m;
ll f[65];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    f[0]=f[1]=1;
    for (int i=2;i<=60;++i) f[i]=f[i-1]+f[i-2];
    scanf ("%d",&m);
    while (m--)
    {
        ll a,b;
        scanf ("%lld%lld",&a,&b);
        while (a!=b)
        {
            if (a<b) swap(a,b);
            int x=lower_bound(f+1,f+60+1,a)-f;
            a-=f[x-1];
        }
        printf ("%lld\n",a);
    }
    return 0;
}