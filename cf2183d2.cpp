#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,maxd;
int fa[N],d[N],tim[N];
vector<int> node[N],to[N],col[N],p;
inline void clear()
{
    maxd=0;
    for (int i=0;i<=n;++i)
    {
        to[i].clear();
        node[i].clear();
        col[i].clear();
    }
}
void dfs(int u,int f)
{
    fa[u]=f;
    node[d[u]].push_back(u);
    maxd=max(maxd,d[u]);
    for (int v:to[u])
    {
        if (v==f) continue;
        d[v]=d[u]+1;
        dfs(v,u);
    }
}
inline void solve()
{
    cin>>n;
    clear();
    for (int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    dfs(1,0);
    for (int i=0;i<=maxd;++i) 
    {
        bool same=true;
        int t=0;
        p.clear();
        for (int j=0;j<node[i].size();++j)
        {
            int k=node[i][j];
            if (j<node[i].size()-1&&fa[k]!=fa[node[i][j+1]]) same=false;
            tim[k]=++t;
            if (tim[k]==tim[fa[k]]) p.push_back(k);
        }
        if (p.size())
        {
            if (same) tim[p[0]]=++t;
            else
            {
                if (p.size()==1)
                {
                    for (int j:node[i])
                    {
                        if (fa[j]!=fa[p[0]])
                        {
                            swap(tim[j],tim[p[0]]);
                            break;
                        }
                    }
                }
                else
                {
                    int a=tim[p[0]];
                    for (int j=0;j<p.size()-1;++j) tim[p[j]]=tim[p[j+1]];
                    tim[p.back()]=a;
                }
            }
        }
    }
    int ans=0;
    for (int i=1;i<=n;++i) 
    {
        ans=max(ans,tim[i]);
        col[tim[i]].push_back(i);
    }
    cout<<ans<<endl;
    for (int i=1;i<=ans;++i)
    {
        cout<<col[i].size()<<" ";
        for (int j:col[i]) cout<<j<<" ";
        cout<<endl;
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--) solve();
    return 0;
}