#include <bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,m,cnt,c;
int d[N],f[N],pred[N],nxtd[N],dp[N];
bool vis[N];
struct Edge{
    int v,w;
};
vector<Edge> to[N];
void dfs(int u,int fa)
{
    f[u]=fa;
    for (Edge e:to[u])
    {
        if (e.v==fa||vis[e.v]) continue;
        d[e.v]=d[u]+e.w;
        if (d[e.v]>d[c]) c=e.v;
        dfs(e.v,u);
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<n;++i)
    {
        int u,v,w;
        scanf ("%d%d%d",&u,&v,&w);
        to[u].push_back({v,w});
        to[v].push_back({u,w});
    }
    dfs(1,0);
    d[c]=0;
    dfs(c,0);
    for (int i=c;i;i=f[i])
    {
        dp[++cnt]=i;
        vis[i]=true;
        pred[cnt]=d[c]-d[i];
    }
    for (int i=1;i<=cnt;++i) nxtd[i]=d[dp[i]];
    int maxd=0;
    for (int i=1;i<=cnt;++i) 
    {
        d[dp[i]]=0;
        dfs(dp[i],0);
        maxd=max(maxd,d[c]);
    }
    int l=1,r=1,ans=0x3f3f3f3f;
    for (;l<=cnt;++l)
    {
        while (r<cnt&&nxtd[l]-nxtd[r+1]<=m) ++r;
        ans=min(ans,max({maxd,pred[l],nxtd[r]}));
    }
    printf ("%d\n",ans);
    return 0;
}