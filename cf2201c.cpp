#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5,mod=998244353;
int n;
int sum[N];
ll f[N];
char str[N];
inline ll qpow(int a,int b)
{
    ll res=1;
    while (b)
    {
        if (b&1) res=res*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    return res;
}
inline void solve()
{
    cin>>n;
    for (int i=1;i<=n;++i) cin>>str[i];
    ll ans=0;
    for (int i=1;i<=n;++i) if (str[i]=='(') ans=(ans+qpow(2,i-1))%mod;
    for (int i=1;i<=n;++i)
    {
        if (str[i]=='(') sum[i]=sum[i-1]+1;
        else sum[i]=sum[i-1]-1;
    }
    ll tot=0;
    queue<int> q;
    for (int i=1;i<=n;++i)
    {
        if (str[i]==')') 
        {
            f[i]=(tot+1)%mod;
            tot=(tot+f[i])%mod;
            ans=(ans+f[i])%mod;
        }
        else
        {
            if (sum[i]<2) f[i]=0;
            else
            {
                f[i]=(tot+1)%mod;
                tot=(tot+f[i])%mod;
                q.push(i);
            }
        }
        if (sum[i]<2) 
        {
            while (q.size())
            {
                int j=q.front();
                q.pop();
                tot=(tot-f[j]+mod)%mod;
            }
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