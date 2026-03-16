#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=8e3+5,mod=998244353;
int n;
int a[N],t[N],nxt[N];
ll f[N];
inline void solve()
{
    cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i];
    for (int i=1;i<=n;++i) f[i]=0;
    f[0]=1;
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=i;++j) t[i-j+1]=a[j];
        for (int j=1;j<=i;++j) nxt[j]=0;
        for (int j=2,k=0;j<=i;++j)
        {
            while (k&&t[j]!=t[k+1]) k=nxt[k];
            if (t[j]==t[k+1]) ++k;
            nxt[j]=k;
        }
        for (int j=1;j<=i;++j) if (!nxt[j]) f[i]=(f[i]+f[i-j])%mod;
    }
    cout<<f[n]<<endl;
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