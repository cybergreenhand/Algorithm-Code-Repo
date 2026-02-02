#include <bits/stdc++.h>
using namespace std;
const int N=405;
int n,ans;
int f[N][N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    memset(f,-0x3f,sizeof (f));
    for (int i=1;i<=n;++i) 
    {
        scanf ("%d",&f[i][i]);
        ans=max(ans,f[i][i]);
    }
    for (int len=2;len<=n;++len)
    {
        for (int l=1,r=l+len-1;r<=n;++l,++r)
        {
            for (int k=l;k<r;++k)
            {
                if (f[l][k]>0&&f[l][k]==f[k+1][r]) 
                {
                    f[l][r]=max(f[l][r],f[l][k]+f[k+1][r]);
                }
            }
            for (int p=l;p+2<=r;++p)
            {
                if (f[l][p]<=0) continue;
                for (int q=p+2;q<=r;++q)
                {
                    if (f[p+1][q-1]>0&&f[l][p]==f[q][r])
                    {
                        f[l][r]=max(f[l][r],f[l][p]+f[q][r]+f[p+1][q-1]);
                    }
                }
            }
            ans=max(ans,f[l][r]);
        }
    }
    printf ("%d\n",ans);
    return 0;
}