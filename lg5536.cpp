#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int d[N],nxt[N];
vector<int> to[N];
struct cmp{
    bool operator() (int i,int j)
    {
        return d[i]<d[j];
    }
};
priority_queue<int,vector<int>,cmp> q;
int dfs1(int u,int fa)
{
    int node=u;
    for (int v:to[u])
    {
        if (v==fa) continue;
        int p=dfs1(v,u);
        if (d[v]+1>d[u]) 
        {
            d[u]=d[v]+1;
            node=p;
        }
    }
    return node;
}
void dfs2(int u,int fa)
{
    d[u]=0;
    for (int v:to[u])
    {
        if (v==fa) continue;
        dfs2(v,u);
        if (d[v]+1>d[u])
        {
            d[u]=d[v]+1;
            nxt[u]=v;
        }
    }
}
void dfs3(int u,int fa)
{
    d[u]=0;
    for (int v:to[u])
    {
        if (v==fa) continue;
        dfs3(v,u);
        d[u]=max(d[u],d[v]+1);
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<n;++i)
    {
        int u,v;
        scanf ("%d%d",&u,&v);
        to[u].push_back(v);
        to[v].push_back(u);
    }
    int p=dfs1(1,0);
    // cout<<p<<endl;
    dfs2(p,0);
    for (int i=p;i;i=nxt[i])
    {
        if (d[i]==(d[p]>>1))
        {
            p=i;
            break;
        }
    }
    // cout<<p<<endl;
    dfs3(p,0);
    for (int i=1;i<=n;++i) q.push(i);
    int ans;
    while (m--)
    {
        int u=q.top();
        // cout<<u<<endl;
        q.pop();
        ans=d[u];
    }
    if (q.size()&&d[q.top()]==ans) ++ans;
    printf ("%d\n",ans);
    return 0;
}