#include <bits/stdc++.h>
using namespace std;
void write(__int128 x)
{
    if (x>9) write(x/10);
    putchar(x%10+'0');
    return;
}
int n,m;
int a[85][85];
__int128 ans;
__int128 f[85][85];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            scanf ("%d",&a[i][j]);
        }
    }
    for (int i=1;i<=n;++i)
    {
        memset(f,0,sizeof (f));
        for (int j=1;j<=m;++j) f[j][j]=a[i][j]*2;
        for (int len=2;len<=m;++len)
        {
            for (int l=1;l+len-1<=m;++l)
            {
                int r=l+len-1;
                f[l][r]=max(f[l+1][r]+a[i][l],f[l][r-1]+a[i][r])*2;
            }
        }
        ans+=f[1][m];
    }
    write(ans);
    putchar('\n');
    return 0;
}