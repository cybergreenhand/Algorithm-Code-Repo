#include <bits/stdc++.h>
using namespace std;
inline int qpow(int a,int b,int p)
{
    int r=1;
    while (b)
    {
        if (b&1) r=1ll*r*a%p;
        a=1ll*a*a%p;
        b>>=1;
    }
    return r;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    int a,b,p;
    scanf ("%d%d%d",&a,&b,&p);
    printf ("%d^%d mod %d=%d\n",a,b,p,qpow(a,b,p));
    return 0;
}