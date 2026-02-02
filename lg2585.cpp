#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,len;
char str[N];
int f[N][3],g[N][3],son[N][2];
int build(int x,int l,int r)
{
    if (str[l]=='1')
    {
        son[x][0]=++n;
        return build(n,l+1,r);
    }
    else if (str[l]=='2')
    {
        son[x][0]=++n;
        int last=build(n,l+1,r);
        son[x][1]=++n;
        return build(n,last+1,r);
    }
    else return l;
}
void dfs(int u)
{
    f[u][0]=f[u][2]=0;
    g[u][0]=g[u][2]=0;
    f[u][1]=g[u][1]=1;
    if (son[u][1])
    {
        int sl=son[u][0],sr=son[u][1];
        dfs(sl);
        dfs(sr);
        f[u][0]=min(f[sl][1]+f[sr][2],f[sl][2]+f[sr][1]);
        f[u][1]=min(f[sl][0]+f[sr][2],f[sl][2]+f[sr][0])+1;
        f[u][2]=min(f[sl][0]+f[sr][1],f[sl][1]+f[sr][0]);
        g[u][0]=max(g[sl][1]+g[sr][2],g[sl][2]+g[sr][1]);
        g[u][1]=max(g[sl][0]+g[sr][2],g[sl][2]+g[sr][0])+1;
        g[u][2]=max(g[sl][0]+g[sr][1],g[sl][1]+g[sr][0]);
    }
    else if (son[u][0])
    {
        int s=son[u][0];
        dfs(s);
        f[u][0]=min(f[s][1],f[s][2]);
        f[u][1]=min(f[s][0],f[s][2])+1;
        f[u][2]=min(f[s][0],f[s][1]);
        g[u][0]=max(g[s][1],g[s][2]);
        g[u][1]=max(g[s][0],g[s][2])+1;
        g[u][2]=max(g[s][0],g[s][1]);
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%s",str+1);
    len=strlen(str+1);
    build(++n,1,len);
    dfs(1);
    printf ("%d %d\n",max({g[1][0],g[1][1],g[1][2]}),min({f[1][0],f[1][1],f[1][2]}));
    return 0;
}