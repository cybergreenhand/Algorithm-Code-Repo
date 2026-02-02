#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,m,c;
int f[N],fw[N];
ll d[N];
bool vis[N];
struct Edge{
    int v,w;
};
vector<Edge> to[N];
vector<int> D;
void dfs(int u,int fa)
{
    f[u]=fa;
    for (Edge e:to[u])
    {
        if (e.v==fa||vis[e.v]) continue;
        fw[e.v]=e.w;
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
    for (int i=1;i<=m;++i)
    {
        int a,b,c;
        scanf ("%d%d%d",&a,&b,&c);
        to[a].push_back({b,c});
        to[b].push_back({a,c});
    }
    dfs(1,0);
    d[c]=0;
    dfs(c,0);
    ll ans=d[c];
    for (int i=c;i;i=f[i]) 
    {
        vis[i]=true;
        d[i]=0;
        D.push_back(i);
    }
    ll maxd=0,j=0;
    for (int i=0;i<D.size();j+=fw[D[i]],++i) 
    {
        if (j==0||j==ans) continue;
        dfs(D[i],0);
        maxd=max(maxd,d[c]+min(j,ans-j));
    }
    ans+=maxd;
    printf ("%lld\n",ans);
    return 0;
}