#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n;
int a[N],f[N][3];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;++i) scanf ("%d",&a[i]);
    for (int i=1;i<=n;++i)
    {
        for (int j=0;j<3;++j)
        {
            f[i][j]=1e9;
        }
    }
    f[1][a[1]+1]=0;
    for (int i=2;i<=n;++i)
    {
        if (a[i]==-1)
        {
            f[i][0]=f[i-1][0];
            f[i][2]=f[i-1][2]+2;
        }
        else if (a[i]==0)
        {
            f[i][0]=f[i-1][0]+1;
            f[i][1]=min(f[i-1][0],f[i-1][1]);
            f[i][2]=f[i-1][2]+1;
        }
        else
        {
            f[i][0]=f[i-1][0]+2;
            f[i][1]=f[i-1][0]+1;
            f[i][2]=min({f[i-1][0],f[i-1][1],f[i-1][2]});
        }
    }
    int ans=min({f[n][0],f[n][1],f[n][2]});
    if (ans<1e9) printf ("%d\n",ans);
    else printf ("BRAK\n");
    return 0;   
}