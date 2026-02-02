#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for (int i=1;i<=n;++i) 
    {
        int c;
        cin>>c;
        ++cnt[c];
    }
    while (m--)
    {
        int opt;
        ll x;
        cin>>opt>>x;
        if (opt==1) ++cnt[x];
        else if (opt==2) --cnt[x];
        else
        {
            ll num=1,ans=0,pos=0;
            for (int i=60;i>=0;--i)
            {
                int j=i;
                while (j>=0&&(x>>j&1)) --j;
                if (j<i)
                {
                    ll s=pow2[cnt[pos+i]];
                    for (int k=0;k<i-j+1;++k) s=(s-C(cnt[pos+i],k)+mod)%mod;
                    ans=(ans+num*s%mod*pow2[sum[pos+i-1]]%mod)%mod;
                    num=num*C(cnt[pos+i],i-j)%mod;
                    pos+=i-j;
                }
                else 
                {
                    --j;
                    while (j>=0&&(x>>j&1)) --j;
                    ll s=pow2[cnt[pos+i]];
                    for (int k=0;k<(i-1)-j+1;++k) s=(s-C(cnt[pos+i],k)+mod)%mod;
                    ans=(ans+num*s%mod*pow2[sum[pos+i-1]]%mod)%mod; 
                    num=num*C(cnt[pos+i],(i-1)-j)%mod;
                }
                i=j;
            }
        }
    }
    return 0;
}