#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int p1=13,p2=131,mod=998244353,N=1e6+5;
int m;
string str;
ll a[2][N],pw[2][N];
inline int get_h(int l,int r,int p,int t)
{
    return (a[t][r]-a[t][l-1]*pw[t][r-l+1]%mod+mod)%mod;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>str>>m;
    pw[0][0]=pw[1][0]=1;
    for (int i=1;i<=str.length();++i)
    {
        pw[0][i]=pw[0][i-1]*p1%mod;
        pw[1][i]=pw[1][i-1]*p2%mod;
        a[0][i]=(a[0][i-1]*p1+str[i-1])%mod;
        a[1][i]=(a[1][i-1]*p2+str[i-1])%mod;
    }
    for (int i=1;i<=m;++i)
    {
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if (get_h(l1,r1,p1,0)==get_h(l2,r2,p1,0)&&get_h(l1,r1,p2,1)==get_h(l2,r2,p2,1)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}