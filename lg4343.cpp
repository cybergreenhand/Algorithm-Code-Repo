#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
int n,k,ma;
bool flag;
ll L=1e18,R;
int x[N];
inline int calc(ll m)
{
    int num=0;
    ll sum=0;
    for (int i=1;i<=n;++i) 
    {
        sum+=x[i];
        if (sum>=m) 
        {
            ++num;
            sum=0;
        }
        else if (sum<0) sum=0;
    }
    return num;
}
inline void dbsrch(ll l,ll r)
{
    // cout<<l<<" "<<r<<endl;
    if (l>r) return;
    ll mid=(l+r)>>1;
    int t=calc(mid);
    if (t>k) dbsrch(mid+1,r);
    else if (t<k) dbsrch(l,mid-1);
    else 
    {
        flag=true;
        if (mid<L)
        {
            L=mid;
            dbsrch(l,mid-1);
        }
        if (mid>R)
        {
            R=mid;
            dbsrch(mid+1,r);
        }
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&k);
    for (int i=1;i<=n;++i) 
    {
        scanf ("%d",&x[i]);
        ma=max(ma,x[i]);
    }
    dbsrch(1,1e11);
    if (flag) printf ("%lld %lld\n",L,R);
    else printf ("-1\n");
    return 0;
}