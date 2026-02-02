#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,T,sx,sy,ex,ey;
char str[N];
bool a[N][N];
int f[N][N][20];
int gx[]={1,-1,0,0},gy[]={0,0,1,-1};
void dfs(int x,int y,int tim)
{
    if (abs(sx-x)+abs(sy-y)>tim) return;
    if (f[x][y][tim]) return;
    for (int i=0;i<4;++i)
    {
        int xx=x+gx[i],yy=y+gy[i];
        if (xx>0&&xx<=n&&yy>0&&yy<=m&&a[xx][yy]&&tim)
        {
            dfs(xx,yy,tim-1);
            f[x][y][tim]+=f[xx][yy][tim-1];
        }
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d%d",&n,&m,&T);
    for (int i=1;i<=n;++i) 
    {
        scanf ("%s",str);
        for (int j=1;j<=m;++j)
        {
            if (str[j-1]=='.') a[i][j]=true;
            else a[i][j]=false;
        }
    }
    scanf ("%d%d%d%d",&sx,&sy,&ex,&ey);
    if (!a[ex][ey])
    {
        printf ("0\n");
        return 0;
    }
    f[sx][sy][0]=1;
    dfs(ex,ey,T);
    printf ("%d\n",f[ex][ey][T]);
    return 0;
}