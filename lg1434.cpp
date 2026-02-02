#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,ans;
int h[N][N],f[N][N];
int gx[]={1,-1,0,0},gy[]={0,0,1,-1};
void dfs(int x,int y)
{
    if (f[x][y]) return;
    f[x][y]=1;
    for (int i=0;i<4;++i)
    {
        int xx=x+gx[i],yy=y+gy[i];
        if (xx>0&&xx<=n&&yy>0&&yy<=m&&h[x][y]>h[xx][yy])
        {
            dfs(xx,yy);
            f[x][y]=max(f[x][y],f[xx][yy]+1);
        }
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            scanf ("%d",&h[i][j]);
        }
    }
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            dfs(i,j);
            ans=max(ans,f[i][j]);
        }
    }
    printf ("%d\n",ans);
    return 0;
}