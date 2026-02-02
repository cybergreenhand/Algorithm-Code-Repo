#include <bits/stdc++.h>
using namespace std;
int n;
int f[55][55];
char str[55];
void dfs(int l,int r)
{
    if (f[l][r]<=50) return;
    if (l>=r) return;
    if (str[l]==str[r])
    {
        dfs(l,r-1);
        dfs(l+1,r);
        f[l][r]=min(f[l+1][r],f[l][r-1]);
    }
    for (int k=l;k<r;++k)
    {
        dfs(l,k);
        dfs(k+1,r);
        f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]);
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%s",str+1);
    n=strlen(str+1);
    memset(f,0x3f3f3f3f,sizeof (f));
    for (int i=1;i<=n;++i) f[i][i]=1;
    dfs(1,n);
    printf ("%d\n",f[1][n]);
    return 0;
}