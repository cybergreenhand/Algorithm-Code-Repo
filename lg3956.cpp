#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,m;
int c[N][N],f[2][N][N];
int gx[]={1,-1,0,0},gy[]={0,0,1,-1};
struct Grid{
    int x,y,c;
};
queue<Grid> q;
inline void bfs()
{
    memset(f,0x3f,sizeof (f));
    f[c[1][1]][1][1]=0;
    q.push({1,1,c[1][1]});
    while (q.size())
    {
        auto t=q.front();
        q.pop();
        for (int i=0;i<4;++i)
        {
            int x=t.x+gx[i],y=t.y+gy[i];
            if (x>0&&x<=m&&y>0&&y<=m)
            {
                if (c[x][y]!=-1)
                {
                    int cost=f[t.c][t.x][t.y];
                    if (t.c!=c[x][y]) ++cost;
                    if (cost<f[c[x][y]][x][y]) 
                    {
                        f[c[x][y]][x][y]=cost;
                        q.push({x,y,c[x][y]});
                    }
                }
                else if (c[t.x][t.y]!=-1)
                {
                    if (f[t.c][t.x][t.y]+2<f[t.c][x][y]) 
                    {
                        f[t.c][x][y]=f[t.c][t.x][t.y]+2;
                        q.push({x,y,t.c});
                    }
                    if (f[t.c][t.x][t.y]+3<f[t.c^1][x][y])
                    {
                        f[t.c^1][x][y]=f[t.c][t.x][t.y]+3;
                        q.push({x,y,t.c^1});
                    }
                }
            }
        }
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&m,&n);
    for (int i=1;i<=m;++i)
    {
        for (int j=1;j<=m;++j)
        {
            c[i][j]=-1;
        }
    }
    for (int i=1;i<=n;++i) 
    {
        int x,y;
        scanf ("%d%d",&x,&y);
        scanf ("%d",&c[x][y]);
    }
    bfs();
    if (c[m][m]!=-1) 
    {
        if (f[c[m][m]][m][m]<0x3f3f3f3f) printf ("%d\n",f[c[m][m]][m][m]);
        else printf ("-1\n");
    }
    else 
    {
        int ans=min(f[0][m][m],f[1][m][m]);
        if (ans<0x3f3f3f3f) printf ("%d\n",ans);
        else printf ("-1\n");
    }
    return 0;
}