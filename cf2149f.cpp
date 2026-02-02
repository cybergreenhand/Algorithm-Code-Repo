#include <bits/stdc++.h>
using namespace std;
int T,H,D;
inline bool check(int cr)
{   
    ++cr;
    int p=D/cr;
    int n=D-cr*p,m=cr-n;
    if (1ll*n*(p+1)*(p+2)/2+1ll*m*p*(p+1)/2>H+cr-1) return false;
    else return true;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--)
    {
        cin>>H>>D;
        --H;
        if (H==0)
        {
            cout<<D*2<<endl;
            continue;
        }
        int l=0,r=D;
        while (l<r)
        {
            int mid=l+r>>1;
            if (check(mid)) r=mid;
            else l=mid+1;
        }
        cout<<D+r<<endl;
    }
    return 0;
}