#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5,mod=1e5+3;
int n,m;
int dis[N],cnt[N];
bool vis[N];
queue<int> q;
vector<int> to[N];
inline void bfs()
{
    memset(dis,0x3f,sizeof dis);
    cnt[1]=1;
    dis[1]=0;
    q.push(1);
    vis[1]=true;
    while (q.size())
    {
        int u=q.front();
        q.pop();
        for (int v:to[u])
        {
            if (dis[v]>dis[u]+1) 
            {
                dis[v]=dis[u]+1;
                cnt[v]=cnt[u];
            }
            else if (dis[v]==dis[u]+1) cnt[v]=(cnt[v]+cnt[u])%mod;
            if (!vis[v]) 
            {
                q.push(v);
                vis[v]=true;
            }
        }
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=m;++i)
    {
        int x,y;
        scanf ("%d%d",&x,&y);
        if (x==y) continue;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    bfs();
    // for (int i=1;i<=n;++i) cout<<dis[i]<<" "<<cnt[i]<<endl;
    for (int i=1;i<=n;++i) printf ("%d\n",cnt[i]);
    return 0;   
}