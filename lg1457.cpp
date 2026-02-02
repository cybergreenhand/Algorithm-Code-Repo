#include <bits/stdc++.h>
using namespace std;
const int N=55;
int n,m,cntr,ans=1,ax,ay;
char ad;
int fa[N*N],sz[N*N];
bool vis[N][N],wall[N][N][4];
int gx[]={0,-1,0,1},gy[]={-1,0,1,0};
int find(int x)
{
    if (x!=fa[x]) return fa[x]=find(fa[x]);
    return fa[x];
}
inline void merge(int x,int y)
{
    int fx=find(x),fy=find(y);
    if (fx==fy) return;
    fa[fx]=fy;
    sz[fy]+=sz[fx];
    --cntr;
    ans=max(ans,sz[fy]);
}
void dfs(int x,int y)
{
    vis[x][y]=true;
    for (int i=0;i<4;++i)
    {
        if (wall[x][y][i]) continue;
        int xx=x+gx[i],yy=y+gy[i];
        if (vis[xx][yy]) continue;
        merge((x-1)*m+y,(xx-1)*m+yy);
        dfs(xx,yy);
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&m,&n);
    cntr=n*m;
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            fa[(i-1)*m+j]=(i-1)*m+j;
            sz[(i-1)*m+j]=1;
            int x;
            scanf ("%d",&x);
            for (int k=0;k<4;++k)//西，北，东，南
            {
                if (x>>k&1) wall[i][j][k]=true;
            }
        }
    }
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            if (!vis[i][j]) dfs(i,j);
        }
    }
    printf ("%d\n%d\n",cntr,ans);
    for (int j=1;j<=m;++j)
    {
        for (int i=n;i>=1;--i)
        {
            if (wall[i][j][1]&&i>1)
            {
                int fx=find((i-1)*m+j),fy=find((i-2)*m+j);
                if (fx==fy) continue;
                if (ans<sz[fx]+sz[fy])
                {
                    ans=sz[fx]+sz[fy];
                    ax=i,ay=j;
                    ad='N';
                }
            }
            if (wall[i][j][2]&&j<m)
            {
                int fx=find((i-1)*m+j),fy=find((i-1)*m+j+1);
                if (fx==fy) continue;
                if (ans<sz[fx]+sz[fy])
                {
                    ans=sz[fx]+sz[fy];
                    ax=i,ay=j;
                    ad='E';
                }
            }
        }
    }
    printf ("%d\n%d %d %c\n",ans,ax,ay,ad);
    return 0;
}