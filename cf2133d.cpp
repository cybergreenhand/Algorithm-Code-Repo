#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int T,n;
int h[N];
ll sum[N],f[N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--)
    {
        cin>>n; 
        for (int i=1;i<=n;++i) 
        {
            cin>>h[i];
            sum[i]=sum[i-1]+h[i];
        }
        for (int i=1;i<=n;++i) f[i]=1e18;
        f[n+1]=0,f[n]=h[n];
        ll minf=sum[n]-n;
        for (int i=n-1;i>=1;--i)
        {   
            f[i]=minf+max(0,h[i+1]-i)-(sum[i+1]-(i+1))+h[i];
            minf=min(minf,f[i+1]+sum[i]-i);
        }
        cout<<f[1]<<endl;
    }
    return 0;
}