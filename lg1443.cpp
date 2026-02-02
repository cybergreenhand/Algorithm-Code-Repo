#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
const int N=405;
int n,m,X,Y;
int pace[N][N];
int gx[]={1,1,2,2,-1,-1,-2,-2},gy[]={2,-2,1,-1,-2,2,-1,1};
queue<pair<int,int>> q;
inline void bfs()
{
    q.push({X,Y});
    while (q.size())
    {
        auto t=q.front();
        q.pop();
        for (int i=0;i<8;++i)
        {
            int x=t.fir+gx[i],y=t.sec+gy[i];
            if (x>0&&x<=n&&y>0&&y<=m&&pace[x][y]==-1)
            {
                pace[x][y]=pace[t.fir][t.sec]+1;
                q.push({x,y});
            }
        }
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d%d%d",&n,&m,&X,&Y);
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            pace[i][j]=-1;
        }
    }
    pace[X][Y]=0;
    bfs();
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            printf ("%d ",pace[i][j]);
        }
        printf ("\n");
    }
    return 0;
}