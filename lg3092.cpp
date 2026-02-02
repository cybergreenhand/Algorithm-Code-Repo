#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=(1<<16)+5;
int n,m,ans=-1;
int v[20],c[N],sum[N],f[M];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&m,&n);
    for (int i=1;i<=m;++i) scanf ("%d",&v[i]);
    for (int i=1;i<=n;++i) 
    {
        scanf ("%d",&c[i]);
        sum[i]=sum[i-1]+c[i];
    }
    for (int i=1;i<(1<<m);++i)
    {
        for (int j=0;j<m;++j)
        {
            if (i&(1<<j))
            {
                int k=i^(1<<j);
                f[i]=max(f[i],(int)(upper_bound(sum+f[k],sum+n+1,v[j+1]+sum[f[k]])-sum-1));
            }
        }
    }
    for (int i=1;i<(1<<m);++i)
    {
        if (f[i]==n)
        {
            int res=0;
            for (int j=0;j<m;++j)
            {
                if (i&(1<<j)) continue;
                res+=v[j+1];
            }
            ans=max(ans,res);
        }
    }
    printf ("%d\n",ans);
    return 0;
}