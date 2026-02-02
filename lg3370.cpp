#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int p1=131,p2=1331,mod=999823,N=1e6;
int n,ans;
string str;
bool vis1[N],vis2[N];
inline int get_h(string s,int p)
{
    ll sum=0;
    for (int i=0;i<s.length();++i) sum=(sum*p+s[i])%mod;
    return sum;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>str;
        int a=get_h(str,p1),b=get_h(str,p2);
        if (vis1[a]&&vis2[b]) continue;
        ++ans;
        vis1[a]=vis2[b]=true;
    }
    cout<<ans<<endl;
    return 0;
}