#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,cnt;
int sz[N],dep[N],f[N][N][N],h[N],to[N<<1],nxt[N<<1];
inline void add(int u,int v)
{
    to[++cnt]=v;
    nxt[cnt]=h[u];
    h[u]=cnt;
}
void dfs(int u,int fa)
{
    f[u][0][0]=1;
    sz[u]=1;
    for (int i=h[u];i;i=nxt[i])
    {
        int v=to[i];
        if (v==fa) continue;
        dfs(v,u);
        for (int a=min(m,(sz[u]-1)<<1);a>=0;--a)
        {
            for (int c=min(m,(sz[v]-1)<<1);c>=0;--c)
            {
                if (a+c+1>m) continue;
                for (int d=min(c,dep[v]);d>=0;--d)//停在v的子树里
                {
                    f[u][a+c+1][d+1]=max(f[u][a+c+1][d+1],f[u][a][0]+f[v][c][d]);
                }
                if (a+c+2>m) continue;
                for (int b=min(a,dep[u]);b;--b)//停在前面某个子树里
                {
                    f[u][a+c+2][b]=max(f[u][a+c+2][b],f[u][a][b]+f[v][c][0]);
                }
                if (a+c+2<=m) f[u][a+c+2][0]=max(f[u][a+c+2][0],f[u][a][0]+f[v][c][0]);
            }
        }
        dep[u]=max(dep[u],dep[v]+1);
        sz[u]+=sz[v];
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
        ++u,++v;
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    int ans=0;
    for (int i=0;i<=m;++i)
    {
        for (int j=0;j<=dep[1];++j)
        {
            ans=max(ans,f[1][i][j]);
        }
    }
    printf ("%d\n",ans);
    return 0;
}