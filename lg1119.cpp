#include <bits/stdc++.h>
using namespace std;
const int N=205;
int n,m,Q;
int t[N];
int f[N][N];
vector<int> p,fix;
struct Edge{
    int v,w;
};
vector<Edge> edge[N];
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    memset(f,0x3f,sizeof (f));
    for (int i=1;i<=n;++i) f[i][i]=0;
    for (int i=1;i<=n;++i) scanf ("%d",&t[i]);
    for (int i=1;i<=m;++i)
    {
        int x,y,w;
        scanf ("%d%d%d",&x,&y,&w);
        ++x,++y;
        edge[x].push_back({y,w});
        edge[y].push_back({x,w});
    }
    scanf ("%d",&Q);
    int now=1,last=1;
    while (Q--)
    {
        int x,y,tim;
        scanf ("%d%d%d",&x,&y,&tim);
        ++x,++y;
        if (last<=n)
        {
            while (t[now]<=tim&&now<=n) ++now;
            p.clear();
            for (int u=last;u<now;++u)
            {   
                p.push_back(u);
                fix.push_back(u);
                for (auto i:edge[u])
                {
                    int v=i.v,w=i.w;
                    if (t[v]>tim) continue; 
                    f[u][v]=w;
                    f[v][u]=w;
                }
            }
            // cout<<last<<" "<<now<<endl;
            last=now;
            if (!p.empty())
            {
                for (int k:fix)
                {
                    for (int i:fix)
                    {
                        for (int j:fix)
                        {
                            f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                        }
                    }
                }
            }
        }
        if (f[x][y]<0x3f3f3f3f) printf ("%d\n",f[x][y]);
        else printf ("-1\n");
    }
    return 0;
}