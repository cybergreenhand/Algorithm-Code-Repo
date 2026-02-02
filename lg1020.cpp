#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ans,cnt;
int a[N],f[N],g[N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    while (scanf ("%d",&a[++n])!=EOF);
    --n;
    memset(f,-0x3f,sizeof (f));
    for (int i=1;i<=n;++i)
    {
        int x=upper_bound(f+1,f+n+1,a[i],greater<int>())-f;
        f[x]=a[i];
        ans=max(ans,x);
        if (g[cnt]<a[i]) g[++cnt]=a[i];
        else
        {
            x=lower_bound(g+1,g+cnt+1,a[i])-g;
            g[x]=a[i];
        }
    }
    printf ("%d\n%d\n",ans,cnt);
    return 0;
}