#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
int n;
ll up,low;
ll a[N],b[N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;++i) 
    {
        scanf ("%lld",&a[i]);
        b[i]=a[i]-a[i-1];
    }
    for (int i=2;i<=n;++i) 
    {
        if (b[i]>0) up+=b[i];
        else if (b[i]<0) low-=b[i];
    }
    printf ("%lld\n%lld\n",max(up,low),max(up,low)-min(up,low)+1);
    return 0;
}