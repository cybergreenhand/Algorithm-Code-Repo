#include <bits/stdc++.h>
using namespace std;
const int N=205,M=5005;
int n,m,V,ans;
int v[N],w[N],f[2][M][105];
vector<int> val;
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d%d",&m,&V,&n);
    for (int i=1;i<=n;++i) scanf ("%d%d",&v[i],&w[i]);
    memset(f[0],-0x3f,sizeof (f[0]));
    f[0][0][1]=0;
    for (int i=1;i<=n;++i)
    {
        memset(f[i&1],-0x3f,sizeof (f[i&1]));
        for (int j=0;j+v[i]<=V;++j)
        {
            for (int k=1;k<=m;++k)
            {
                if (f[i-1&1][j][k]>=0) f[i-1&1][j+v[i]][k+m]=f[i-1&1][j][k]+w[i];
                else break;
            }
        }
        for (int j=0;j<=V;++j)
        {
            sort(f[i-1&1][j]+1,f[i-1&1][j]+(m<<1)+1,greater<int>());
            for (int k=1;k<=m;++k) f[i&1][j][k]=f[i-1&1][j][k];
        }
        // cout<<i<<endl;
        // for (int j=0;j<=V;++j)
        // {
        //     cout<<j<<": "<<endl;
        //     for (int k=1;k<=m;++k)
        //     {
        //         if (f[i&1][j][k]>=0) cout<<f[i&1][j][k]<<" ";
        //         else break;
        //     }
        //     cout<<endl;
        // }
    }
    for (int i=1;i<=m;++i) ans+=f[n&1][V][i];
    printf ("%d\n",ans);
    return 0;
}