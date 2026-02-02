#include <bits/stdc++.h>
using namespace std;
const int N=205;
int n,maxa,mina=0x3f3f3f3f;
int a[N],s[N],f[N][N],g[N][N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;++i) 
    {
        scanf ("%d",&a[i]);
        a[i+n]=a[i];
        s[i]=s[i-1]+a[i];
    }
    for (int i=n+1;i<=(n<<1);++i) s[i]=s[i-1]+a[i];
    for (int i=1;i<=n;++i)
    {
        memset(g,0x3f,sizeof (g));
        memset(f,-0x3f,sizeof (f));
        for (int j=i;j<=i+n-1;++j) 
        {
            g[j][j]=0;
            f[j][j]=0;
        }
        for (int len=2;len<=n;++len)
        {
            for (int l=i;l+len-1<=i+n-1;++l)
            {
                int r=l+len-1;
                for (int k=l;k<r;++k)
                {
                    f[l][r]=max(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
                    g[l][r]=min(g[l][r],g[l][k]+g[k+1][r]+s[r]-s[l-1]);
                }
            }
        }
        maxa=max(maxa,f[i][i+n-1]);
        mina=min(mina,g[i][i+n-1]);
    }
    printf ("%d\n%d\n",mina,maxa);
    return 0;
}