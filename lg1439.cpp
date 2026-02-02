#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10,INF=1e9+10;
int n,ans;
int a[N],b[N],c[N],f[N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;++i) 
    {
        scanf ("%d",&a[i]);
        c[a[i]]=i;
    }
    for (int i=1;i<=n;++i) scanf ("%d",&b[i]);
    for (int i=1;i<=n;++i) f[i]=INF;
    for (int i=1;i<=n;++i)
    {
        int x=upper_bound(f+1,f+n+1,c[b[i]])-f;
        f[x]=c[b[i]];
    }
    for (int i=1;i<=n;++i) if (f[i]<INF) ans=i;
    printf ("%d\n",ans);
    return 0;
}