#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
int a[N],f[N][20];
int solve(int l,int r)
{
    if (r-l+1<3) return 0;
    int maxi=0,k=log2(r-l+1);
    if (a[f[l][k]]>a[f[r-(1<<k)+1][k]]) maxi=f[l][k];
    else maxi=f[r-(1<<k)+1][k];
    if (maxi==l) return solve(maxi+1,r);
    if (maxi==r) return solve(l,maxi-1);
    return min(solve(l,maxi-1)+r-maxi,solve(maxi+1,r)+maxi-l);
}
inline void solve()
{
    cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i];
    for (int i=1;i<=n;++i) f[i][0]=i;
    for (int j=1;(1<<j)<=n;++j)
    {
        for (int i=1;i+(1<<j)-1<=n;++i)
        {
            if (a[f[i][j-1]]>a[f[i+(1<<j-1)][j-1]]) f[i][j]=f[i][j-1];
            else f[i][j]=f[i+(1<<j-1)][j-1];
        }
    }
    cout<<solve(1,n)<<endl;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}