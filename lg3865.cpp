#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int a[N],f[N][20];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;++i) 
    {
        scanf ("%d",&a[i]);
        f[i][0]=a[i];
    }
    for (int j=1;(1<<j)<=n;++j)
    {
        for (int i=1;i+(1<<j)-1<=n;++i)
        {
            f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
            // cout<<i<<" "<<(1<<j)<<" "<<f[i][j]<<endl;
        }
    }    
    for (int i=1;i<=m;++i)
    {
        int l,r;
        scanf ("%d%d",&l,&r);
        int k=log2(r-l+1);
        printf ("%d\n",max(f[l][k],f[r-(1<<k)+1][k]));
    }
    return 0;
}