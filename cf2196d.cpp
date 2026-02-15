#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
int st[N];
char str[N],sd[N];
bool vis[N];
inline void solve()
{
    cin>>n;
    for (int i=1;i<=n;++i) vis[i]=false;
    for (int i=1;i<=n;++i) cin>>str[i];
    int tt=0;
    for (int i=1;i<=n;++i)
    {
        if (str[i]=='(') st[++tt]=i;
        else if (str[i]==')'&&tt) 
        {
            vis[st[tt--]]=true;
            vis[i]=true;
        }
    }
    tt=0;
    for (int i=1;i<=n;++i)
    {
        if (str[i]=='[') st[++tt]=i;
        else if (str[i]==']'&&tt) 
        {
            vis[st[tt--]]=true;
            vis[i]=true;
        }
    }
    int m=0;
    for (int i=1;i<=n;++i) if (!vis[i]) sd[++m]=str[i];
    int lef=0;
    for (int i=1;i<=m;++i)
    {
        if (sd[i]=='('||sd[i]=='[') 
        {
            if (!lef) lef=i;
        }
        else if (lef)
        {
            cout<<m/2<<endl;
            return;
        }
    }
    if (lef&&(lef-1)%2) cout<<m/2+1<<endl;
    else cout<<m/2<<endl;
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