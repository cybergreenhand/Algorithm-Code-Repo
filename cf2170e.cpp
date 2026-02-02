#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e5+5,mod=998244353;
int T,n,m;
int lim[N];
ll f[N],sumf[N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--)
    {
        cin>>n>>m;
        for (int i=1;i<=n;++i) f[i]=sumf[i]=lim[i]=0;
        while (m--)
        {
            int l,r;
            cin>>l>>r;
            lim[r]=max(lim[r],l);
        }
        for (int i=1;i<=n;++i) lim[i]=max(lim[i],lim[i-1]);
        // for (int i=1;i<=n;++i) cout<<lim[i]<<" ";
        // cout<<endl;
        f[0]=1;
        sumf[1]=1;
        for (int i=1;i<=n;++i)
        {
            f[i]=(sumf[i]-sumf[lim[i]]+mod)%mod;
            sumf[i+1]=(sumf[i]+f[i])%mod;
        }
        cout<<(f[n]<<1)%mod<<endl;
    }
    return 0;
}