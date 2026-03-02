#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,mod=998244353;
int n,m;
ll tot;
struct Node{
    int l,r;
    int cnt;
    ll sum;
}tr[N<<2];
ll a[N];
vector<ll> num;
inline ll qpow(ll a,ll b)
{
    ll res=1;
    while (b)
    {
        if (b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
inline void pushup(int p)
{
    tr[p].sum=tr[p<<1].sum+tr[p<<1|1].sum;
    tr[p].cnt=tr[p<<1].cnt+tr[p<<1|1].cnt;
}
void build(int p,int l,int r)
{
    tr[p].l=l,tr[p].r=r;
    if (l==r) return;
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}
void modify(int p,int x)
{
    if (tr[p].l==x&&tr[p].r==x)
    {
        tr[p].cnt=1;
        tr[p].sum=num[x-1];
        return;
    }
    int mid=tr[p].l+tr[p].r>>1;
    if (x<=mid) modify(p<<1,x);
    else modify(p<<1|1,x);
    pushup(p);
}
int queryrk(int p,int x)
{
    if (tr[p].l==tr[p].r) return tr[p].r;
    if (tr[p<<1].cnt>=x) return queryrk(p<<1,x);
    else return queryrk(p<<1|1,x-tr[p<<1].cnt);
}
ll querysum(int p,int x)
{
    if (x==0) return 0;
    if (tr[p].l==tr[p].r) return tr[p].sum;
    if (x<=tr[p<<1].cnt) return querysum(p<<1,x);
    else return tr[p<<1].sum+querysum(p<<1|1,x-tr[p<<1].cnt);
}
inline ll costl(int i)
{
    ll x=num[queryrk(1,i-1)-1],sum=querysum(1,i-2);
    // if (x*(i-2)<sum) 
    // {
    //     cout<<n<<" "<<i<<" "<<x<<" "<<sum<<endl;
    //     cout<<"FUCK"<<endl;
    //     return 0;
    // }
    return x*(i-2)-sum;
}
inline ll costr(int i)
{
    ll x=num[queryrk(1,i+1)-1],sum=querysum(1,i+1);
    // if (tot<sum+x*(n-i-1))
    // {
    //     cout<<n<<" "<<i<<" "<<x<<" "<<sum<<endl;
    //     cout<<"CAO"<<endl;
    //     return 0;
    // }
    return tot-sum-(n-i-1)*x;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m;
    for (int i=1;i<=m;++i) 
    {
        cin>>a[i];
        num.push_back(a[i]);
    }
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for (int i=1;i<=m;++i) a[i]=lower_bound(num.begin(),num.end(),a[i])-num.begin()+1;
    build(1,1,m);
    for (int i=1;i<=m;++i)
    {
        ++n;
        tot+=num[a[i]-1];
        modify(1,a[i]);
        if (i<3) continue;
        int l=2,r=i-1;
        while (l<r)
        {
            int mid=l+r+1>>1;
            if (costl(mid)<costr(mid)) l=mid;
            else r=mid-1;
        }
        ll ans=max(costl(r),costr(r));
        l=2,r=i-1;
        while (l<r)
        {
            int mid=l+r>>1;
            if (costl(mid)<costr(mid)) l=mid+1;
            else r=mid;
        }
        ans=min(ans,max(costl(r),costr(r)));
        // cout<<ans<<" ";
        cout<<ans%mod*qpow(i-2,mod-2)%mod<<endl;
    }
    return 0;
}