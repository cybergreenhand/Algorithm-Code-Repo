#include <bits/stdc++.h>
using namespace std;
const int N=510,M=1030;
int m;
int del[N];
vector<pair<int,int>> to[N];
vector<int> node;
bool vis[M],exist[N];
stack<int> st;
void dfs(int u)
{
    for (int i=del[u];i<to[u].size();i=del[u])
    {
        auto [v,id]=to[u][i];
        del[u]=i+1;
        if (vis[id]) continue;
        vis[id]=true;
        dfs(v);
    }
    st.push(u);
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&m);
    for (int i=1;i<=m;++i)
    {
        int u,v;
        scanf ("%d%d",&u,&v);
        if (!exist[u]) 
        {
            exist[u]=true;
            node.push_back(u);
        }
        if (!exist[v])
        {
            exist[v]=true;
            node.push_back(v);
        }
        to[u].push_back({v,i});
        to[v].push_back({u,i});
    }
    int S=0,T=0,mins=501;
    for (int i:node) 
    {
        mins=min(mins,i);
        sort(to[i].begin(),to[i].end());
        if (to[i].size()&1)
        {
            if (!S) S=i;
            else if (!T) 
            {
                T=i;
                if (S>T) swap(S,T);
            }
        }
    }
    if (!S) S=mins;
    dfs(S);
    while (st.size())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}