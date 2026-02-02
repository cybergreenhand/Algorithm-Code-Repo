#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int T,Y,n;
int c[N],cnt[N],pos[N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--)
    {
        cin>>n>>Y;
        memset(cnt,0,sizeof (cnt));
        for (int i=1;i<=n;++i) 
        {
            cin>>c[i];
            ++cnt[c[i]];
        }
        sort(c+1,c+n+1);
        for (int i=0;i<=c[n];++i) pos[i]=upper_bound(c+1,c+n+1,i)-c;
        ll ans=-1e18;
        for (int x=2;x<=max(c[n],2);++x)
        {
            ll sum=0;
            for (int i=1;x*(i-1)+1<=c[n];++i)
            {
                int p=pos[x*(i-1)],q=x*i<=c[n]?pos[x*i]-1:n;
                sum+=1ll*i*(q-p+1)-1ll*Y*max(q-p+1-cnt[i],0);
            }
            ans=max(ans,sum);
        }
        cout<<ans<<endl;
    }
    return 0;
}