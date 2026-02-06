#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int T,n,m;
ll sum[N];
struct Elf{
    int a,h,id;
    bool operator< (const Elf &b) const
    {
        return a<b.a;
    }
}e[N];
vector<pair<int,int>> ans;
inline void solve()
{
    cin>>n>>m;
    for (int i=1;i<=n;++i) 
    {
        cin>>e[i].a;
        e[i].h=e[i].a;
        e[i].id=i;
    }
    sort(e+1,e+n+1);
    if (m==0)
    {
        if (n==2)
        {
            cout<<"-1"<<endl;
            return;
        }
        for (int i=1;i<=n;++i) sum[i]=sum[i-1]+e[i].a;
        if (sum[n-1]<e[n].a)
        {
            cout<<"-1"<<endl;
            return;
        }
        int now=1;
        while (true)
        {
            if (sum[n-1]-sum[now-1]>=e[n].a&&sum[n-1]-sum[now]<e[n].a) break;
            ans.push_back({e[now].id,e[now+1].id});
            ++now;
        }
        for (int i=now;i<n;++i) ans.push_back({e[i].id,e[n].id});
        cout<<ans.size()<<endl;
        for (auto x:ans) cout<<x.first<<" "<<x.second<<endl;
        ans.clear();
        return;
    }
    if (n<m*2)
    {
        cout<<"-1"<<endl;
        return;
    }
    int now=1;
    while (n-now+1>m*2)
    {
        ans.push_back({e[now].id,e[now+1].id});
        ++now;
    }
    for (int i=1;i<=m;++i) ans.push_back({e[now+i-1+m].id,e[now+i-1].id});
    cout<<ans.size()<<endl;
    for (auto x:ans) cout<<x.first<<" "<<x.second<<endl;
    ans.clear();
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--) solve();
    return 0;
}