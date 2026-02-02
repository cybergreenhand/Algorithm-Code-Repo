#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=205,M=5e4+10;
int n;
ll m;
int s[N],c[N];
ll f[2][M];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%lld",&n,&m);
    for (int i=1;i<=n;++i) scanf ("%d",&s[i]);
    for (int i=1;i<=n;++i) scanf ("%d",&c[i]);
    f[0][0]=1;
    for (int i=1;i<=n;++i)
    {
        memcpy(f[i&1],f[(i-1)&1],sizeof(f[i&1]));
        for (int j=1;j<=s[i];++j)
        {
            for (int k=j*c[i];k<=5e4;++k)
            {
                if (f[(i-1)&1][k-j*c[i]]) f[i&1][k]=max(f[i&1][k],f[(i-1)&1][k-j*c[i]]*j);
            }
        }
    }
    for (int i=0;i<=5e4;++i) 
    {
        if (f[n&1][i]>=m)
        {
            // cout<<f[n&1][i]<<endl;
            printf ("%d\n",i);
            break;
        }
    }
    return 0;
}