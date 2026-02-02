#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+5;
int n,C;
ll ans;
ll sum[N];
int w[N];
void dfs(int now,ll s)
{
    ans=max(ans,s);
    int x=upper_bound(w+1,w+now+1,C-s)-w-1;
    for (int i=x;i>=1;--i)
    {
        if (s+sum[i]<=C)
        {
            ans=max(ans,s+sum[i]);
            return;
        }
        dfs(i-1,s+w[i]);
        dfs(i-1,s);
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&C);
    for (int i=1;i<=n;++i) 
    {
        scanf ("%d",&w[i]);
        sum[i]=sum[i-1]+w[i];
    }
    dfs(n,0);
    printf ("%lld\n",ans);
    return 0;
}