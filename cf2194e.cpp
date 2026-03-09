#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int n,m;
ll mf[N],mmf[N];
inline void solve()
{
    cin>>n>>m;
    for (int i=1;i<=n+m;++i) mf[i]=mmf[i]=LLONG_MIN;
    vector<vector<int>> a(n+1,vector<int>(m+1));
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            cin>>a[i][j];
        }
    }
    vector<vector<ll>> fo(n+1,vector<ll>(m+1)),fn(n+1,vector<ll>(m+1));
    fo[1][1]=a[1][1];
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            if (i==1&&j==1) continue;
            if (i==1) fo[i][j]=fo[i][j-1]+a[i][j];
            else if (j==1) fo[i][j]=fo[i-1][j]+a[i][j];
            else
            {
                if (fo[i-1][j]>=fo[i][j-1]) fo[i][j]=fo[i-1][j]+a[i][j];
                else if (fo[i-1][j]<fo[i][j-1]) fo[i][j]=fo[i][j-1]+a[i][j];
            }
        }
    }
    fn[n][m]=a[n][m];
    for (int i=n;i>=1;--i)
    {
        for (int j=m;j>=1;--j)
        {
            if (i==n&&j==m) continue;
            if (i==n) fn[i][j]=fn[i][j+1]+a[i][j];
            else if (j==m) fn[i][j]=fn[i+1][j]+a[i][j];
            else
            {
                if (fn[i+1][j]>=fn[i][j+1]) fn[i][j]=fn[i+1][j]+a[i][j];
                else if (fn[i+1][j]<fn[i][j+1]) fn[i][j]=fn[i][j+1]+a[i][j];
            }
        }
    }
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            mf[i+j]=max(mf[i+j],fo[i][j]+fn[i][j]-a[i][j]);
            if (mf[i+j]>mmf[i+j]) swap(mf[i+j],mmf[i+j]);
        }
    }
    ll ans=LLONG_MAX;
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            ll maxv=0;
            if (fo[i][j]+fn[i][j]-a[i][j]==mmf[i+j]) maxv=mf[i+j];
            else maxv=mmf[i+j];
            ans=min(ans,max(fo[i][j]+fn[i][j]-a[i][j]*3ll,maxv));
        }
    }
    cout<<ans<<endl;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}