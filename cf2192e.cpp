#include <bits/stdc++.h>
using namespace std;

inline void solve()
{
    cin>>n;
    for (int i=1;i<=n;++i) 
    {
        cin>>a[i];
        ++cnta[a[i]];
    }
    for (int i=1;i<=n;++i)
    {
        cin>>b[i];
        ++cntb[b[i]];
    }
    for (int i=1;i<=n;++i)
    {
        if ((cnta[i]+cntb[i])&1) 
        {
            cout<<"-1"<<endl;
            return;
        }
        dcnt[i]=cntb[i]-cnta[i];
        if (abs(dcnt[i])&1)
        {
            cout<<"-1"<<endl;
            return;
        }
    }
    
}
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}