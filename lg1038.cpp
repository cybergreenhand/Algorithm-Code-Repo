#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=105,M=1e4+5;
int n,m,cnt;
int to[M],nxt[M],h[M],in[N],out[N],w[M];
ll c[N],u[N];
queue<int> q;
inline void add(int x,int y,int z)
{
    to[++cnt]=y;
    nxt[cnt]=h[x];
    w[cnt]=z;
    h[x]=cnt;
    ++in[y];
    ++out[x];
}
inline void bfs()
{
    for (int i=1;i<=n;++i) if (c[i]>0) q.push(i);
    while (q.size())
    {
        int t=q.front();
        q.pop();
        for (int i=h[t];i;i=nxt[i])
        {
            int v=to[i];
            --in[v];
            c[v]+=w[i]*c[t];
            if (!in[v])
            {
                c[v]-=u[v];
                if (c[v]>0) q.push(v);
            }
        }
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;++i) scanf ("%lld%lld",&c[i],&u[i]);
    for (int i=1;i<=m;++i)
    {
        int x,y,z;
        scanf ("%d%d%d",&x,&y,&z);
        add(x,y,z);
    }
    bfs();
    bool flag=false;
    for (int i=1;i<=n;++i)
    {
        if (!out[i]&&c[i]>0)
        {
            flag=true;
            printf ("%d %d\n",i,c[i]);
        }
    }
    if (!flag) printf ("NULL\n");
    return 0;
}