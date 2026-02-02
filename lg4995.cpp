#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int h[310];
ll ans;
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;++i) scanf ("%d",&h[i]);
    sort(h+1,h+n+1);
    int l=1,r=n,now=0;
    while (l<r)
    {
        if (abs(h[l]-now)>abs(h[r]-now))
        {
            ans+=(h[l]-now)*(h[l]-now);
            now=h[l++];
        }
        else 
        {
            ans+=(h[r]-now)*(h[r]-now);
            now=h[r--];
        }
    }
    ans+=(h[r]-now)*(h[r]-now);
    printf ("%lld\n",ans);
    return 0;
}