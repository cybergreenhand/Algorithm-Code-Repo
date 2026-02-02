#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fir first
#define sec second
typedef pair<int,int> pii;
const int N=2e5+5;
int T,n,cnt;
int vis[N],prime[N];
unordered_map<int,bool> flag;
pii a[N];
vector<int> u;
inline void get_prime(int x) 
{
    for (int i=2;i<=x;++i) 
    {
        if (!vis[i]) 
        {
            prime[++cnt]=i;
            vis[i]=cnt;
        }
        for (int j=1;j<=cnt;++j) 
        {
            if (i*prime[j]>x) break;
            vis[i*prime[j]]=j;
            if (i%prime[j]==0) break;
        }
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    get_prime(200001);
    while (T--)
    {
        u.clear();
        flag.clear();
        cin>>n;
        for (int i=1;i<=n;++i) cin>>a[i].sec;
        for (int i=1;i<=n;++i) cin>>a[i].fir;
        sort(a+1,a+n+1);
        bool is=true;
        for (int i=1;i<=n;++i)
        {
            int t=a[i].sec;
            while (t>1)
            {
                int p=prime[vis[t]];
                if (flag[vis[t]]) 
                {
                    is=false;
                    break;
                }
                flag[vis[t]]=true;
                u.push_back(vis[t]);
                while (t%p==0) t/=p;
            }
            if (!is) break;
        }
        if (!is)
        {
            cout<<"0"<<endl;
            continue;
        }
        ll ans=a[1].fir+a[2].fir;
        // cout<<"FUCK"<<" "<<ans<<endl;
        for (int i:u) 
        {
            // cout<<prime[i]<<" ";
            if (a[1].sec%prime[i]==0) continue;
            ans=min(ans,1ll*((prime[i]-(a[1].sec%prime[i]))%prime[i])*a[1].fir);
        }
        // cout<<"NOW"<<" "<<ans<<endl;
        // cout<<endl;
        for (int i=1;i<=n;++i)
        {
            int t=a[i].sec+1;
            while (t>1)
            {
                int p=prime[vis[t]];
                if (flag[vis[t]])
                {
                    ans=min(ans,1ll*a[i].fir);
                    break;
                }
                t/=p;
            }
        }
        cout<<ans<<endl;
        // cout<<endl;
    }
    return 0;
}