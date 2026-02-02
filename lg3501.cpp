#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5,P=1331,mod=998244353;
int n;
ll ans;
ll sum[2][N],pw[N];
char str[N],strt[N];
inline ll geth(int l,int r,int t)
{
    return (sum[t][r]-sum[t][l-1]*pw[r-l+1]%mod+mod)%mod;
}
inline bool check(int sp,int len)
{
    return geth(sp-len,sp-1,0)==geth(n-(sp+len+1)+1,n-(sp+2)+1,1);
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d\n",&n);
    for (int i=1;i<=n;++i)
    {
        scanf ("%c",&str[i]);
        strt[i]=str[i]=='0'?'1':'0';
    }
    pw[0]=1;
    for (int i=1;i<=n;++i) pw[i]=pw[i-1]*P%mod;
    for (int i=1;i<=n;++i)
    {
        sum[0][i]=(sum[0][i-1]*P%mod+str[i]-'0')%mod;
        sum[1][i]=(sum[1][i-1]*P%mod+strt[n-i+1]-'0')%mod;
    }
    for (int i=1;i<n;++i)
    {
        if (str[i]!=str[i+1])
        {
            int l=0,r=min(i-1,n-i-1);
            while (l<r)
            {
                int mid=l+r+1>>1;
                if (check(i,mid)) l=mid;
                else r=mid-1;
            }
            // cout<<i<<" "<<l<<endl;
            ans+=l+1;
        }
    }
    printf ("%lld\n",ans);
    return 0;
}