#include <bits/stdc++.h>
using namespace std;
const int N=2e3+5,M=1e3+5,mod=1e8;
int n,m;
int r[N],f[2][M];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;++i) 
    {
        scanf ("%d",&r[i]);
        r[i]%=m;
    }
    f[0][0]=1;
    for (int i=1;i<=n;++i)
    {
        for (int j=0;j<m;++j) f[i&1][j]=f[i-1&1][j];
        for (int j=0;j<m;++j)
        {
            // cout<<f[(i-1)&1][j]<<endl;
            f[i&1][(j+r[i])%m]=(f[i&1][(j+r[i])%m]+f[i-1&1][j])%mod;
        }
        // for (int j=0;j<m;++j) cout<<f[i&1][j]<<" ";
        // cout<<endl;
    }
    printf ("%d\n",(f[n&1][0]-1+mod)%mod);
    return 0;
}