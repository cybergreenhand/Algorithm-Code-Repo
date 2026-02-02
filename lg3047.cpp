#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,cnt;
int f[N][25],h[N],to[N<<1],nxt[N<<1];
inline void add(int u,int v)
{
    to[++cnt]=v;
    nxt[cnt]=h[u];
    h[u]=cnt;
}
void dfs(int u,int fa)
{
    for (int i=h[u];i;i=nxt[i])
    {
        int v=to[i];
        if (v==fa) continue;
        dfs(v,u);
        for (int j=1;j<=m;++j) f[u][j]+=f[v][j-1];
    }
}
void changert(int u,int fa)
{
    if (fa)
    {
        for (int j=m;j>=1;--j) 
        {
            f[u][j]+=f[fa][j-1];
            if (j>1) f[u][j]-=f[u][j-2];
        }
    }
    for (int i=h[u];i;i=nxt[i])
    {
        int v=to[i];
        if (v==fa) continue;
        changert(v,u);
    }
}   
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<n;++i)
    {
        int u,v;
        scanf ("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    for (int i=1;i<=n;++i) scanf ("%d",&f[i][0]);
    dfs(1,0);
    changert(1,0);
    for (int i=1;i<=n;++i) 
    {
        int sum=0;
        for (int j=0;j<=m;++j) sum+=f[i][j];
        printf ("%d\n",sum);
    }
    return 0;
}