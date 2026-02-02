#include <bits/stdc++.h>
using namespace std;
const int N=2e4+10;
int V,n;
int v[35],f[N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&V,&n);
    for (int i=1;i<=n;++i) scanf ("%d",&v[i]);
    for (int i=1;i<=n;++i)
    {
        for (int j=V;j>=v[i];--j)
        {
            if (j==v[i]) f[j]=f[j-v[i]]+v[i];
            else if (f[j-v[i]]) f[j]=max(f[j],f[j-v[i]]+v[i]);
        }
    }
    for (int i=0;i<=V;++i)
    {
        if (f[V-i])
        {
            printf ("%d\n",i);
            break;
        }
    }
    return 0;
}