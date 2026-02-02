#include <bits/stdc++.h>
using namespace std;
const int N=305;
int n;
int a[N],f[N][N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;++i) scanf ("%d",&a[i]);
    memset(f,0x3f,sizeof (f));
    for (int i=1;i<=n;++i) f[i][i]=1;
    for (int len=2;len<=n;++len)
    {
        for (int l=1,r=l+len-1;r<=n;++l,++r)
        {
            if (a[l]==a[r]) f[l][r]=min(f[l][r-1],f[l+1][r]);
            for (int k=l;k<r;++k) f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]);
        }
    }
    printf ("%d\n",f[1][n]);
    return 0;
}