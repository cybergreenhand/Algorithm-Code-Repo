#include <bits/stdc++.h>
using namespace std;
const int N=105,M=25005;
int T,n;
int a[N],f[M];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&T);
    while (T--)
    {
        scanf ("%d",&n);
        memset(f,0,sizeof (f));
        int V=0;
        for (int i=1;i<=n;++i)
        {
            scanf ("%d",&a[i]);
            V=max(V,a[i]);
        }
        f[0]=1;
        for (int i=1;i<=n;++i)
        {
            for (int j=a[i];j<=V;++j)
            {
                f[j]+=f[j-a[i]];
            }
        }
        int ans=0;
        for (int i=1;i<=n;++i) if (f[a[i]]==1) ++ans;
        printf ("%d\n",ans);
    }
    return 0;
}