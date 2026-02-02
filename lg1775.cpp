#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=305;
int n;
int m[N],s[N];
ll f[N][N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    memset(f,0x3f,sizeof (f));
    for (int i=1;i<=n;++i) 
    {
        scanf ("%d",&m[i]);
        s[i]=s[i-1]+m[i];
        f[i][i]=0;
    }
    for (int len=2;len<=n;++len)
    {
        for (int i=1;i+len-1<=n;++i)
        {
            int j=i+len-1;
            for (int k=i;k<j;++k)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
            }
        }
    }
    printf ("%lld\n",f[1][n]);
    return 0;
}