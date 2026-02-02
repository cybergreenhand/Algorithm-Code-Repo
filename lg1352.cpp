#include <bits/stdc++.h>
using namespace std;
const int N=6e3+5;
int n,rt;
int r[N],f[N][2];
bool vis[N];
vector<int> son[N];
void dfs(int x,int fa)
{
    f[x][1]=r[x];
    for (int y:son[x])
    {
        dfs(y,x);
        f[x][0]+=max(f[y][0],f[y][1]);
        f[x][1]+=f[y][0];
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;++i) scanf ("%d",&r[i]);
    for (int i=1;i<n;++i)
    {
        int l,k;
        scanf ("%d%d",&l,&k);
        son[k].push_back(l);
        vis[l]=true;
    }
    for (int i=1;i<=n;++i) 
    {
        if (!vis[i]) 
        {
            rt=i;
            break;
        }
    }
    dfs(rt,0);
    printf ("%d\n",max(f[rt][0],f[rt][1]));
    return 0;
}