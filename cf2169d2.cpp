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
        if (y==1) 
        {
            cout<<"-1"<<endl;
            continue;
        }
        for (ll i=0;i<x;)
        {
            ll cur=(k-1)/(y-1);
            if (!cur) break;
            ll maxk=(cur+1)*(y-1)+cur,cnt=(maxk-k)/cur;
            cnt=min(x-i,cnt);
            k+=cnt*cur;
            if (k>1e12)
            {
                cout<<"-1"<<endl;
                break;
            }
            i+=cnt;
        }
        if (k<=1e12) cout<<k<<endl;
    }
    return 0;
}