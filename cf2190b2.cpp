#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105,mod=998244353;
int n;
char str[N];
ll f[2][N][N][N];
inline void solve()
{
    cin>>n;
    for (int i=1;i<=n;++i) cin>>str[i];
    memset(f[0],0,sizeof (f[0]));
    f[0][0][0][0]=1;
    for (int i=1;i<=n;++i)
    {
        memset(f[i&1],0,sizeof (f[i&1]));
        f[i&1][0][0][0]=f[i-1&1][0][0][0];
        for (int s=1;s<=i;++s)
        {
            if (s>=2&&str[i]==')') f[i&1][s][s][s-2]=f[i-1&1][s-1][0][s-1];
            for (int j=0;j<=s;++j)
            {
                if (j==1) continue;
                for (int k=(j==0?s:0);k<=s;++k)
                {
                    if ((s+k)&1) continue;
                    f[i&1][s][j][k]=(f[i&1][s][j][k]+f[i-1&1][s][j][k])%mod;
                    if (j==s) continue;
                    if (str[i]=='(') 
                    {
                        if (k>0) f[i&1][s][j][k]=(f[i&1][s][j][k]+f[i-1&1][s-1][j][k-1])%mod;
                    }
                    else 
                    {
                        if (k+1<=s-1&&j!=0) 
                        {
                            f[i&1][s][j][k]=(f[i&1][s][j][k]+f[i-1&1][s-1][j][k+1])%mod;
                        }
                    }
                }
            }
        }
        // cout<<"I IS "<<i<<endl;
        // for (int s=0;s<=i;++s)
        // {
        //     for (int j=0;j<=s;++j)
        //     {
        //         if (j==1) continue;
        //         for (int k=(j==0?s:0);k<=s;++k)
        //         {
        //             if ((s+k)&1) continue;
        //             cout<<s<<" "<<j<<" "<<k<<" "<<f[i&1][s][j][k]<<endl;
        //         }
        //     }
        // } 
    }
    ll ans=0;
    for (int s=6;s<=n;s+=2)
    {
        for (int j=2;j<s/2;++j)
        {
            ans=(ans+f[n&1][s][j][0]*(s-2)%mod)%mod;
            // cout<<"S IS "<<s<<" J IS "<<j<<" "<<f[n&1][s][j][0]<<endl;
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