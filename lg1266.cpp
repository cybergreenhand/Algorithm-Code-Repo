#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
typedef pair<int,int> pii;
const double eps=1e-7;
const int N=155,M=22505,V=505;
int n,m,D,cnt;
int h[N],to[M],nxt[M],vy[M],len[M];
double dis[N][V];
bool vis[N][V];
vector<int> ans;
struct Point{
    int u;
    double w;
    int v;
    bool operator> (const Point &t) const
    {
        return w>t.w+eps;
    }
};
pii from[N][V];
priority_queue<Point,vector<Point>,greater<Point>> q;
inline void add(int a,int b,int v,int l)
{
    to[++cnt]=b;
    nxt[cnt]=h[a];
    len[cnt]=l;
    vy[cnt]=v;
    h[a]=cnt;
}
inline void dijkstra()
{
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=500;++j)
        {
            dis[i][j]=2e9;
        }
    }
    q.push({1,dis[1][70]=0,70});
    while (q.size())
    {
        int u=q.top().u,ov=q.top().v;
        q.pop();
        if (vis[u][ov]) continue;
        vis[u][ov]=true;
        for (int i=h[u];i;i=nxt[i])
        {
            int v=to[i];
            if (!vy[i])
            {
                if (dis[v][ov]>dis[u][ov]+1.0*len[i]/ov+eps)
                {
                    dis[v][ov]=dis[u][ov]+1.0*len[i]/ov;
                    from[v][ov]={u,ov};
                    q.push({v,dis[v][ov],ov});
                }
            }
            else
            {
                if (dis[v][vy[i]]>dis[u][ov]+1.0*len[i]/vy[i]+eps)
                {
                    dis[v][vy[i]]=dis[u][ov]+1.0*len[i]/vy[i];
                    from[v][vy[i]]={u,ov};
                    q.push({v,dis[v][vy[i]],vy[i]});
                }
            }
        }
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d%d",&n,&m,&D);
    ++D;
    for (int i=1;i<=m;++i)
    {
        int a,b,v,l;
        scanf ("%d%d%d%d",&a,&b,&v,&l);
        ++a,++b;
        add(a,b,v,l);
    }
    dijkstra();
    double fast=2e9;
    int fv=0;
    for (int i=1;i<=500;++i)
    {
        if (fast>dis[D][i]+eps)
        {
            fast=dis[D][i];
            fv=i;
        }
    }
    for (pii i={D,fv};i.fir;i=from[i.fir][i.sec]) ans.push_back(i.fir-1);
    reverse(ans.begin(),ans.end());
    for (int i:ans) printf ("%d ",i);
    return 0;
}