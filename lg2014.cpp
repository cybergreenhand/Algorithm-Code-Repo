#include <bits/stdc++.h>
using namespace std;
const int N=305;
int n,m;
int s[N],sz[N],f[N][N];
vector<int> son[N];
void dfs(int u)
{
    if (u)
    {
        sz[u]=1;
        f[u][1]=s[u];
    }
    for (int v:son[u])
    {
        dfs(v);
        if (!u)
        {
            for (int i=sz[u];i>=0;--i)
            {
                for (int j=1;j<=sz[v];++j)
                {
                    if (i+j>m) break;
                    f[u][i+j]=max(f[u][i+j],f[u][i]+f[v][j]);
                }
            }
        }
        else
        {
            for (int i=sz[u];i>=1;--i)
            {
                for (int j=1;j<=sz[v];++j)
                {
                    if (i+j>m) break;
                    f[u][i+j]=max(f[u][i+j],f[u][i]+f[v][j]);
                }
            }
        }
        sz[u]+=sz[v];
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;++i) 
    {
        int fa;
        scanf ("%d%d",&fa,&s[i]);
        son[fa].push_back(i);
    }
    dfs(0);
    printf ("%d\n",f[0][m]);
    return 0;
}