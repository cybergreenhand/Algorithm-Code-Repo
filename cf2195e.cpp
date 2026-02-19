#include <bits/stdc++.h>
using namespace std;
const int N=3e5+5,mod=1e9+7;
int n;
int f[N],lson[N],rson[N];
void dfs(int u)
{
    if (f[u]!=0x3f3f3f3f) return;
    dfs(lson[u]);
    dfs(rson[u]);
    f[u]=(f[lson[u]]+f[rson[u]]+4)%mod;
}
void calc(int u)
{
    if (lson[u]==0) return; 
    f[lson[u]]=(f[lson[u]]+1+f[u])%mod;
    f[rson[u]]=(f[rson[u]]+1+f[u])%mod;
    calc(lson[u]);
    calc(rson[u]);
}
inline void solve()
{
    cin>>n;
    for (int i=1;i<=n;++i) f[i]=0x3f3f3f3f;
    for (int i=1;i<=n;++i) 
    {
        cin>>lson[i]>>rson[i];
        if (lson[i]==0) f[i]=0;
    }
    dfs(1);
    f[1]=(f[1]+1)%mod;
    calc(1);
    for (int i=1;i<=n;++i) cout<<f[i]<<" ";
    cout<<endl;
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