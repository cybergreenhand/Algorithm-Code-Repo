#include <bits/stdc++.h>
using namespace std;
#define ll long long
int T;
ll x,y,k;
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--)
    {
        cin>>x>>y>>k;
        if (k<y)
        {
            cout<<k<<endl;
            continue;
        }
        if (y==1)
        {
            cout<<"-1"<<endl;
            continue;
        }
        ll p=k/y,q=k%y;
        for (int i=1;i<=x;++i)
        {
            ll n=p,m=p+q;
            while (m>=y) 
            {
                n+=m/y;
                m=m/y+m%y;
            }
            p=n,q=m;
            if (p*y+q>1e12) 
            {
                p=0,q=-1;
                break;
            }
        }
        cout<<p*y+q<<endl;
    }
    return 0;
}