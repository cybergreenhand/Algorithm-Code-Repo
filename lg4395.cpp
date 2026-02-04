#include <bits/stdc++.h>
using namespace std;
const int N=5e4+5;
int n;
int f[N][4];
vector<int> to[N];
void dfs(int u,int fa)
{
    f[u][0]=1;
    f[u][1]=2;
    f[u][2]=3;
    f[u][3]=4;
    for (int v:to[u])
    {
        if (v==fa) continue;
        dfs(v,u);
        f[u][0]+=min({f[v][1],f[v][2],f[v][3]});
        f[u][1]+=min({f[v][0],f[v][2],f[v][3]});
        f[u][2]+=min({f[v][0],f[v][1],f[v][3]});
        f[u][3]+=min({f[v][0],f[v][1],f[v][2]});
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<n;++i)
    {
        int u,v;
        scanf ("%d%d",&u,&v);
        to[u].push_back(v);
        to[v].push_back(u);
    }
    dfs(1,0);
    printf ("%d\n",min({f[1][0],f[1][1],f[1][2]}));
    return 0;
}