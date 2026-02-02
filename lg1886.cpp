#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,k,hh,tt;
int a[N],q[N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&k);
    for (int i=1;i<=n;++i) scanf ("%d",&a[i]);
    for (int i=1;i<=n;++i)
    {
        while (hh<=tt&&q[hh]<i-k+1) ++hh;
        while (hh<=tt&&a[q[tt]]>=a[i]) --tt;
        q[++tt]=i;
        if (i>=k) printf ("%d ",a[q[hh]]);
    }
    printf ("\n");
    hh=0;
    tt=0;
    for (int i=1;i<=n;++i)
    {
        while (hh<=tt&&q[hh]<i-k+1) ++hh;
        while (hh<=tt&&a[q[tt]]<=a[i]) --tt;
        q[++tt]=i;
        if (i>=k) printf ("%d ",a[q[hh]]);
    }
    return 0;
}