#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m,mod;
struct Node{
    int l,r;
    ll sum,add,mul;
}tr[N<<2];
inline void pushup(int p)
{
    tr[p].sum=(tr[p<<1].sum+tr[p<<1|1].sum)%mod;
}
void build(int p,int l,int r)
{
    tr[p].l=l,tr[p].r=r;
    tr[p].mul=1;
    if (l==r)
    {
        scanf ("%lld",&tr[p].sum);
        return;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    pushup(p);
} 
inline void times(int p,ll k)
{
    tr[p].add=tr[p].add*k%mod;
    tr[p].sum=tr[p].sum*k%mod;
    tr[p].mul=tr[p].mul*k%mod;
}
inline void add(int p,ll k)
{
    tr[p].add=(tr[p].add+k)%mod;
    tr[p].sum=(tr[p].sum+k*(tr[p].r-tr[p].l+1)%mod)%mod;
}
inline void pushdown(int p)
{
    if (tr[p].mul!=1)
    {
        times(p<<1,tr[p].mul);
        times(p<<1|1,tr[p].mul);
        tr[p].mul=1;
    }
    if (tr[p].add)
    {
        add(p<<1,tr[p].add);
        add(p<<1|1,tr[p].add);
        tr[p].add=0;
    }
}
void times(int p,int l,int r,ll k)
{
    if (l<=tr[p].l&&tr[p].r<=r)
    {
        times(p,k);
        return;
    }
    pushdown(p);
    int mid=tr[p].l+tr[p].r>>1;
    if (l<=mid) times(p<<1,l,r,k);
    if (r>mid) times(p<<1|1,l,r,k);
    pushup(p);
}
void add(int p,int l,int r,ll k)
{
    if (l<=tr[p].l&&tr[p].r<=r)
    {
        add(p,k);
        return;
    }
    pushdown(p);
    int mid=tr[p].l+tr[p].r>>1;
    if (l<=mid) add(p<<1,l,r,k);
    if (r>mid) add(p<<1|1,l,r,k);
    pushup(p);
}
ll query(int p,int l,int r)
{
    if (l<=tr[p].l&&tr[p].r<=r) return tr[p].sum;
    pushdown(p);
    int mid=tr[p].l+tr[p].r>>1;
    ll sum=0;
    if (l<=mid) sum=(sum+query(p<<1,l,r))%mod;
    if (r>mid) sum=(sum+query(p<<1|1,l,r))%mod;
    return sum;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d%d",&n,&m,&mod);
    build(1,1,n);
    while (m--)
    {
        int opt,x,y;
        scanf ("%d%d%d",&opt,&x,&y);
        if (opt==1)
        {
            ll k;
            scanf ("%lld",&k);
            times(1,x,y,k);
        }
        else if (opt==2)
        {
            ll k;
            scanf ("%lld",&k);
            add(1,x,y,k);
        }
        else printf ("%lld\n",query(1,x,y));
    }
    return 0;
}