#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
char s[N];
int suml[N],sumr[N],nxtl[N];
vector<int> pos;
inline bool check(int pos,int cnt)
{
    return sumr[n]-sumr[pos]>=cnt;
}
inline void solve()
{
    cin>>n;
    pos.clear();
    for (int i=1;i<=n;++i) 
    {
        cin>>s[i];
        sumr[i]=sumr[i-1];
        suml[i]=suml[i-1];
        if (s[i]==')')
        {
            pos.push_back(i);
            ++sumr[i];
        }
        else ++suml[i];
    }
    int pre=n+1;
    for (int i=n;i>=1;--i)
    {
        if (s[i]==')') nxtl[i]=pre;
        else pre=i;
    }
    int ans=0;
    for (int i:pos)
    {
        if (suml[n]-suml[i]==0) break;
        int cnt=suml[i-1]-sumr[i-1];
        int l=0,r=suml[n]-suml[i]-1;
        while (l<r)
        {
            int mid=l+r+1>>1;
            if (check(nxtl[i],mid)) l=mid;
            else r=mid-1;
        }
        if (r>0) ans=max(ans,i-1+r+cnt+r);
    }
    if (!ans) cout<<"-1"<<endl;
    else cout<<ans<<endl;
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