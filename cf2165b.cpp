#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e3+5,mod=998244353;
int T,n;
int a[N],cnt[N];
ll f[N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--)
    {
        memset(f,0,sizeof (f));
        memset(cnt,0,sizeof (cnt));
        cin>>n;
        for (int i=1;i<=n;++i) 
        {
            cin>>a[i];
            ++cnt[a[i]];
        }
        int maxc=0;
        for (int i=1;i<=n;++i) maxc=max(maxc,cnt[i]);
        f[0]=1;
        for (int i=1;i<=n;++i)
        {
            if (cnt[i])
            {
                for (int j=n;j>=cnt[i];--j)
                {
                    f[j]=(f[j]+cnt[i]*f[j-cnt[i]]%mod)%mod;
                }
            }
        }
        ll ans=0;
        for (int i=maxc;i<=n;++i) ans=(ans+f[i])%mod;
        cout<<ans<<endl;
    }
    return 0;
}