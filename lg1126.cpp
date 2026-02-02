#include <bits/stdc++.h>
using namespace std;
const int N=55;
int n,m;
int pace[4][N][N],ob[N][N];
int gx[]={-1,1,0,0},gy[]={0,0,-1,1};
struct Grid{
    int x,y,d;
};
queue<Grid> q;
inline int judge(char c)
{
    switch (c)
    {
        case 'N':return 0;
        case 'S':return 1;
        case 'W':return 2;
        case 'E':return 3;
        default:return -1;
    }
}
inline bool check(int sx,int sy,int ex,int ey,int dir)
{
    int move=max(abs(sx-ex),abs(sy-ey));
    for (int i=0;i<=move;++i)
    {
        int x=sx+gx[dir]*i,y=sy+gy[dir]*i;
        if (ob[x][y]||ob[x+1][y]||ob[x][y+1]||ob[x+1][y+1]) return false;
    }
    return true;
}
inline int bfs()
{
    int sx,sy,ex,ey;
    char d;
    memset(pace,0x3f,sizeof (pace));
    scanf ("%d%d%d%d %c",&sx,&sy,&ex,&ey,&d);
    if (check(sx,sy,sx,sy,judge(d)))
    {
        q.push({sx,sy,judge(d)});
        pace[judge(d)][sx][sy]=0;
    }
    while (q.size())
    {
        auto t=q.front();
        q.pop();
        for (int dir=0;dir<4;++dir)
        {
            for (int move=0;move<=3;++move)
            {
                int cost=pace[t.d][t.x][t.y];
                if (dir==(t.d^1)) cost+=2;
                else if (dir!=t.d) ++cost;
                if (dir==0)
                {
                    int x=t.x+gx[dir]*move,y=t.y+gy[dir]*move;
                    if (x>0&&x<n&&y>0&&y<m&&check(t.x,t.y,x,y,dir))
                    {
                        if (move!=0) ++cost;
                        if (pace[dir][x][y]>cost)
                        {
                            pace[dir][x][y]=cost;
                            q.push({x,y,dir});
                        }
                    }
                }
                else if (dir==1)
                {
                    int x=t.x+gx[dir]*move,y=t.y+gy[dir]*move;
                    if (x>0&&x<n&&y>0&&y<m&&check(t.x,t.y,x,y,dir))
                    {
                        if (move!=0) ++cost;
                        if (pace[dir][x][y]>cost)
                        {
                            pace[dir][x][y]=cost;
                            q.push({x,y,dir});
                        }
                    }
                }
                else if (dir==2)
                {
                    int x=t.x+gx[dir]*move,y=t.y+gy[dir]*move;
                    if (x>0&&x<n&&y>0&&y<m&&check(t.x,t.y,x,y,dir))
                    {
                        if (move!=0) ++cost;
                        if (pace[dir][x][y]>cost)
                        {
                            pace[dir][x][y]=cost;
                            q.push({x,y,dir});
                        }
                    }
                }
                else
                {
                    int x=t.x+gx[dir]*move,y=t.y+gy[dir]*move;
                    if (x>0&&x<n&&y>0&&y<m&&check(t.x,t.y,x,y,dir))
                    {
                        if (move!=0) ++cost;
                        if (pace[dir][x][y]>cost)
                        {
                            pace[dir][x][y]=cost;
                            q.push({x,y,dir});
                        }
                    }
                }
            }
        }
    }
    int ans=0x3f3f3f3f;
    for (int i=0;i<4;++i) ans=min(ans,pace[i][ex][ey]);
    if (ans==0x3f3f3f3f) return -1;
    return ans;
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
            scanf ("%d",&ob[i][j]);
        }
    }
    printf ("%d\n",bfs());
    return 0;
}