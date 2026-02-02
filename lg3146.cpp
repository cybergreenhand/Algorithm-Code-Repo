#include <bits/stdc++.h>
using namespace std;
const int N=255;
int n,ans;
int f[N][N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;++i) 
    {
        scanf ("%d",&f[i][i]);
        ans=max(ans,f[i][i]);
    }
    for (int len=2;len<=n;++len)
    {
        for (int l=1;l+len-1<=n;++l)
        {
            int r=l+len-1;
            for (int k=l;k<r;++k)
            {
                if (f[l][k]==f[k+1][r]&&f[l][k]) f[l][r]=max(f[l][r],f[l][k]+1);
            }
            ans=max(ans,f[l][r]);
        }
    }
    printf ("%d\n",ans);
    return 0;
}