#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int T,n;
ll f[N],b[N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--)
    {
        cin>>n;
        for (int i=1;i<=n;++i) cin>>b[i];
        b[n+1]=b[1],b[n+2]=b[2];
        ll ans=1e18;
        for (int i=0;i<=n;++i) f[i]=1e18;
        f[0]=f[1]=0;
        for (int i=2;i<=n;++i)
        {
            if (i-2==0||i-2>1) f[i]=min(f[i],f[i-2]+abs(b[i]-b[i-1]));
            if (i-3==0||i-3>1) 
            {
                if ((b[i]-b[i-1])*(b[i-1]-b[i-2])>=0) f[i]=min(f[i],f[i-3]+abs(b[i]-b[i-1])+abs(b[i-1]-b[i-2]));
                else f[i]=min(f[i],f[i-3]+max(abs(b[i]-b[i-1]),abs(b[i-1]-b[i-2])));
            }
        }
        ans=min(ans,f[n]);
        for (int i=1;i<=n+1;++i) f[i]=1e18;
        f[1]=f[2]=0;
        for (int i=3;i<=n+1;++i)
        {
            if (i-2==1||i-2>2) f[i]=min(f[i],f[i-2]+abs(b[i]-b[i-1]));
            if (i-3==1||i-3>2) 
            {
                if ((b[i]-b[i-1])*(b[i-1]-b[i-2])>=0) f[i]=min(f[i],f[i-3]+abs(b[i]-b[i-1])+abs(b[i-1]-b[i-2]));
                else f[i]=min(f[i],f[i-3]+max(abs(b[i]-b[i-1]),abs(b[i-1]-b[i-2])));
            }
        }
        ans=min(ans,f[n+1]);
        for (int i=2;i<=n+2;++i) f[i]=1e18;
        f[2]=f[3]=0;
        for (int i=4;i<=n+2;++i)
        {
            if (i-2==2||i-2>3) f[i]=min(f[i],f[i-2]+abs(b[i]-b[i-1]));
            if (i-3==2||i-3>3) 
            {
                if ((b[i]-b[i-1])*(b[i-1]-b[i-2])>=0) f[i]=min(f[i],f[i-3]+abs(b[i]-b[i-1])+abs(b[i-1]-b[i-2]));
                else f[i]=min(f[i],f[i-3]+max(abs(b[i]-b[i-1]),abs(b[i-1]-b[i-2])));
            }
        }
        ans=min(ans,f[n+2]);
        cout<<ans<<endl;
    }
    return 0;
}