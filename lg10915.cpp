#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int P=131,mod=998244353,N=5e5+5;
int n,ans;
string str;
ll a[2][N],pw[N];
inline int get(int l,int r,int t)
{
    return (a[t][r]-a[t][l-1]*pw[r-l+1]%mod+mod)%mod;
}
inline bool check1(int len,int x)
{
    for (int i=len+2;i+(x<<1)-1<n-len+1;++i) if (get(i,i+x-1,0)==get(len+1,len+x,1)) return true;
    return false;
}
inline bool check2(int len,int x)
{
    for (int i=len+2;i+(x<<1)-1<n-len+1;++i) if (get(len+1,len+x,0)==get(i,i+x-1,1)) return true;
    return false;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>str;
    n=str.length();
    str=" "+str;
    pw[0]=1;
    for (int i=1;i<=n;++i)
    {
        pw[i]=pw[i-1]*P%mod;
        a[0][i]=(a[0][i-1]*P+str[i]-'a')%mod;
        a[1][i]=(a[1][i-1]*P+str[n-i+1]-'a')%mod;
    }
    int l=0,r=n>>1;
    while (l<r)
    {
        int mid=l+r+1>>1;
        if (get(1,mid,0)==get(1,mid,1)) l=mid;
        else r=mid-1;
    }
    int t=l;
    l=0,r=n>>1;
    while (l<r)
    {
        int mid=l+r+1>>1;
        if (check1(t,mid)) l=mid;
        else r=mid-1;
    }
    ans=max(ans,t+l);
    l=0,r=n>>1;
    while (l<r)
    {
        int mid=l+r+1>>1;
        if (check2(t,mid)) l=mid;
        else r=mid-1;
    }
    ans=max(ans,t+l);
    cout<<ans<<endl;
    return 0;
}