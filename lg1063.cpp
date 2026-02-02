#include <bits/stdc++.h>
using namespace std;
const int N=205;
int n,ans;
int h[N],t[N],f[N][N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf ("%d",&h[i]);
        if (i>1) t[i-1]=h[i];
        else t[n]=h[1];
    }
    for (int i=n+1;i<=(n<<1);++i) 
    {
        h[i]=h[i-n];
        t[i]=t[i-n];
    }
    for (int i=1;i<=n;++i)
    {
        memset(f,-0x3f,sizeof (f));
        for (int j=1;j<=(n<<1);++j) f[j][j]=0;
        for (int len=2;len<=n;++len)
        {
            for (int l=i;l+len-1<=i+n-1;++l)
            {
                int r=l+len-1;
                for (int k=l;k<r;++k)
                {
                    f[l][r]=max(f[l][r],f[l][k]+f[k+1][r]+h[l]*t[k]*t[r]);
                }
            }
        }
        ans=max(ans,f[i][i+n-1]);
    }
    printf ("%d\n",ans);
    return 0;
}