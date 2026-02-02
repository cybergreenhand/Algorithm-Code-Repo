#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,k;
int dep[N],son[N],cnt[N];
vector<int> e[N];
bitset<N> dp;
int main()
{
	ios::sync_with_stdio(false);
	cin>>T;
    while (T--)
    {
        cin>>n>>k;
        fill(son+1,son+n+1,1);
        fill(cnt+1,cnt+n+1,0);
        dp.reset();
        fill(dep+1,dep+n+1,0);
        dep[1]=1;
        cnt[1]=1;
        for (int i=2;i<=n;i++)
        {
            int f;
            cin>>f;
            dep[i]=dep[f]+1;
            son[f]=0;
            cnt[dep[i]]++;
        }
        int md=1e9;
        for (int i=1;i<=n;i++) if(son[i]) md=min(md,dep[i]);
        dp[0]=1;
        int sum=0;
        for (int i=1;i<=md;i++)
        {
            dp|=(dp<<cnt[i]);
            sum+=cnt[i];
        }
        if (sum<=max(k,n-k))
        {
            cout<<md<<endl;
            continue;
        }
        bool flag=false;
        for (int i=0;i<=sum;i++)
        {
            if(dp[i]&&i<=k&&sum-i<=n-k)
            {
                cout<<md<<endl;
                flag=true;
                break;
            }
        }
        if (!flag) cout<<md-1<<endl;
    }
	return 0;
}
