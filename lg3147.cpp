#include <bits/stdc++.h>
using namespace std;
const int N=262150;
int n,ans;
int f[N][60];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;++i)
    {
        int a;
        scanf ("%d",&a);
        f[i][a]=i+1;
    }
    for (int x=1;x<=58;++x)
    {
        for (int i=1;i<=n;++i)
        {
            if (!f[i][x]) f[i][x]=f[f[i][x-1]][x-1];
            if (f[i][x]) ans=max(ans,x);
        }
    }
    printf ("%d\n",ans);
    return 0;
}