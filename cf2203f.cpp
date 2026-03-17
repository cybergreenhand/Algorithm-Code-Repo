#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e6+5;
int n;
int fa[N],lsiz[N],rsiz[N],siz[N],cnt[N];
ll ans[N];
map<int,int> mp;
vector<int> cntr;
int build(int l,int r)
{
    if (l>r) return 0;
    if (l==r) 
    {
        siz[l]=1;
        mp[0]=1;
        return l;
    }
    int mid=l+r>>1;
    int lson=build(l,mid-1),rson=build(mid+1,r);
    lsiz[mid]=siz[lson],rsiz[mid]=siz[rson];
    fa[lson]=fa[rson]=mid;
    siz[mid]=siz[lson]+siz[rson]+1;
    mp[rsiz[mid]]=1;
    return mid;
}
inline void solve()
{
    cin>>n;
    build(1,n);
    for (auto [x,y]:mp) cntr.push_back(x);
    for (int i=1;i<=n;++i)
    {
        for (int j:cntr) if (j+lsiz[i]+2<=n) ans[j+lsiz[i]+2]+=cnt[j];
        ++cnt[rsiz[i]];
        int cur=fa[i];
        while (cur)
        {
            if (cur>i)
            {
                if (rsiz[i]+lsiz[cur]+2<=n) --ans[rsiz[i]+lsiz[cur]+2];
            }
            else
            {
                if (lsiz[i]+rsiz[cur]+2<=n) --ans[lsiz[i]+rsiz[cur]+2];
            }
            ++ans[abs(cur-i)];
            cur=fa[cur];
        }
    }
    for (int i=n;i>=0;--i) cout<<ans[i]<<" ";
    cout<<endl;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}