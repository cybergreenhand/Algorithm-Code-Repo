#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,cnt;
int prime[N];
bool vis[N];
vector<int> mulp[N];
vector<int> onlyp;
inline void clear()
{
    onlyp.clear();
    for (int i=1;prime[i]*prime[i]<=n;++i) mulp[i].clear();
}
inline void get_prime(int x) 
{
    for (int i=2;i<=x;++i) 
    {
        if (!vis[i]) prime[++cnt]=i;
        for (int j=1;j<=cnt;++j) 
        {
            if (i*prime[j]>x) break;
            vis[i*prime[j]]=true;
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
    get_prime(200000);
    while (T--)
    {
        cin>>n;
        if (n<=6)
        {
            for (int i=1;i<=n;++i) cout<<i<<" ";
            cout<<endl;
            continue;
        }
        clear();
        onlyp.push_back(1);
        int x=upper_bound(prime+1,prime+cnt+1,(int)sqrt(n))-prime;
        for (int i=x;prime[i]<=n&&i<=cnt;++i) onlyp.push_back(prime[i]);
        for (int i=1;i<=n;++i)
        {
            if (!vis[i]&&1ll*i*i>n) continue;
            for (int j=1;prime[j]<=i;++j)
            {
                if (i%prime[j]==0)
                {
                    if (i!=prime[j]*prime[j+1]) mulp[j].push_back(i);
                    break;
                }
            }
        }
        int end=1;
        for (int i=1;prime[i]*prime[i]<=n;++i)
        {
            if (prime[i]*prime[i+1]<=n) mulp[i].push_back(prime[i]*prime[i+1]);
            reverse(mulp[i].begin(),mulp[i].end());
            end=i;
        }
        int now=1;
        while (!onlyp.empty())
        {
            int a1,a2,a3=-1;
            a3=onlyp.back();
            onlyp.pop_back();
            if (!mulp[now].empty()&&now<=end) 
            {
                a1=mulp[now].back();
                mulp[now].pop_back();
                if (mulp[now].empty()) ++now;
            }
            else if (now>end)
            {
                cout<<a3<<" ";
                continue;
            }
            if (!mulp[now].empty()&&now<=end) 
            {
                a2=mulp[now].back();
                mulp[now].pop_back();
                if (mulp[now].empty()) ++now;
            }
            else if (now>end)
            {
                cout<<a1<<" "<<a3<<" ";
                continue;
            }
            cout<<a1<<" "<<a2<<" "<<a3<<" ";
        }
        while (now<=end)
        {
            int a1,a2,a3;
            if (!mulp[now].empty()&&now<=end) 
            {
                a1=mulp[now].back();
                mulp[now].pop_back();
                if (mulp[now].empty()) ++now;
            }
            else if (now>end) break;
            if (!mulp[now].empty()&&now<=end) 
            {
                a2=mulp[now].back();
                mulp[now].pop_back();
                if (mulp[now].empty()) ++now;
            }
            else if (now>end)
            {
                cout<<a1;
                break;
            }
            if (!mulp[now].empty()&&now<=end) 
            {
                a3=mulp[now].back();
                mulp[now].pop_back();
                if (mulp[now].empty()) ++now;
            }
            else if (now>end)
            {
                cout<<a1<<" "<<a2;
                break;
            }
            cout<<a1<<" "<<a2<<" "<<a3<<" ";
        }
        cout<<endl;
    }
    return 0;
}