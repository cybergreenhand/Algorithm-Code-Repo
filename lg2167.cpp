#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1000003;
int T,n,m;
int p[55];
ll f[20],c[20][20];
char s[20][55];
inline int ksm(int a,int b)
{
    ll res=1;
    while (b)
    {
        if (b&1) res=1ll*res*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    return res;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    for (int i=0;i<=15;++i)
    {
        for (int j=0;j<=i;++j)
        {
            if (j==0||j==i) c[i][j]=1;
            else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
    while (T--)
    {
        memset(f,0,sizeof (f));
        cin>>n>>m;
        for (int i=1;i<=n;++i) cin>>s[i]+1;
        int len=strlen(s[1]+1);
        for (int i=0;i<(1<<n);++i)
        {
            int num=__builtin_popcount(i);
            if (num<m) continue;
            memset(p,0,sizeof (p));
            bool flag=true;
            for (int j=1;j<=n;++j)
            {
                if (i>>(j-1)&1)
                {
                    for (int k=1;k<=len;++k)
                    {
                        if (p[k]&&s[j][k]!='?'&&p[k]!=s[j][k]-'a'+1)
                        {
                            flag=false;
                            break;
                        }
                        else if (s[j][k]!='?'&&!p[k]) p[k]=s[j][k]-'a'+1;
                    }
                }
            }
            if (flag) 
            {
                int cnt=0;
                for (int j=1;j<=len;++j) if (!p[j]) ++cnt;
                f[num]=(f[num]+ksm(26,cnt))%mod;
            }
        }
        ll ans=f[m];
        for (int i=m+1;i<=n;++i)
        {
            if ((i-m)&1) ans=(ans-c[i][m]*f[i]%mod+mod)%mod;
            else ans=(ans+c[i][m]*f[i]%mod)%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}