#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,mod;
struct Tree{
    int l,r;
    ll times;
}tr[N<<2];
inline void pushup(int p)
{
    tr[p].times=tr[p<<1].times*tr[p<<1|1].times%mod;
}
void build(int p,int l,int r)
{
    tr[p].l=l,tr[p].r=r;
    if (l==r)
    {
        tr[p].times=1;
        return;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    pushup(p);
}
void modify(int p,int x,int y)
{
    if (tr[p].l==x&&tr[p].r==x)
    {
        tr[p].times=y;
        return;
    }
    int mid=tr[p].l+tr[p].r>>1;
    if (x<=mid) modify(p<<1,x,y);
    else modify(p<<1|1,x,y);
    pushup(p);
}
inline void solve()
{
    scanf ("%d%d",&n,&mod);
    build(1,1,n);
    for (int i=1;i<=n;++i)
    {
        int opt;
        scanf ("%d",&opt);
        if (opt==1)
        {
            int m;
            scanf ("%d",&m);
            modify(1,i,m);
            printf ("%lld\n",tr[1].times);
        }
        else
        {
            int pos;
            scanf ("%d",&pos);
            modify(1,pos,1);
            printf ("%lld\n",tr[1].times);
        }
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    int T;
    scanf ("%d",&T);
    while (T--) solve();
    return 0;
}