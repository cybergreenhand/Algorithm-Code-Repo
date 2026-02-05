#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n;
inline ll ask(int l,int r)
{
    cout<<"? "<<l<<" "<<r<<endl;
    ll sum;
    cin>>sum;
    return sum;
}
ll solve(int l,int r)
{
    if (l==r) return ask(l,r);
    int L=l,R=r;
    ll sum=ask(l,r);
    while (l<r)
    {
        int mid=l+r>>1;
        ll x=ask(L,mid);
        if (x*2==sum) 
        {
            l=r=mid;
            break;
        }
        else if (x*2>sum) r=mid;
        else l=mid+1; 
    }
    if (r-L+1<=R-l) return solve(L,r);
    else return solve(l+1,R);
}
inline void solve()
{
    cin>>n;
    ll ans=solve(1,n);
    cout<<"! "<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--) solve();
    return 0;
}