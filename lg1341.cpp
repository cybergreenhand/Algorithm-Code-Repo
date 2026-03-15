#include <bits/stdc++.h>
using namespace std;
const int N=2710;
int n;
int del[N];
vector<pair<int,int>> to[N];
bool vis[N];
stack<int> st;
void dfs(int u)
{
    for (int i=del[u];i<to[u].size();i=del[u])
    {
        auto [v,id]=to[u][i];
        del[u]=i+1;
        if (vis[id]) continue;
        vis[id]=1;
        dfs(v);
    }
    st.push(u);
}
inline void solve()
{
    cin>>n;
    int mins=100;
    for (int i=1;i<=n;++i)
    {
        char x,y;
        cin>>x>>y;
        int u=x,v=y;
        mins=min({mins,u,v});
        to[u].push_back({v,i});
        to[v].push_back({u,i});
    }
    int S=0,T=0;
    for (int i='A';i<='Z';++i) 
    {
        if (to[i].size()&1)
        {
            if (!S) S=i;
            else if (!T)
            {
                T=i;
                if (S>T) swap(S,T);
            }
            else 
            {
                cout<<"No Solution"<<endl;
                return;
            }
        }
        sort(to[i].begin(),to[i].end());
    }
    for (int i='a';i<='z';++i) 
    {
        if (to[i].size()&1)
        {
            if (!S) S=i;
            else if (!T)
            {
                T=i;
                if (S>T) swap(S,T);
            }
            else 
            {
                cout<<"No Solution"<<endl;
                return;
            }
        }
        sort(to[i].begin(),to[i].end());
    }
    if (S&&!T)
    {
        cout<<"No Solution"<<endl;
        return;
    }
    if (!S) S=mins;
    dfs(S);
    while (st.size()) 
    {
        cout<<(char)st.top();
        st.pop();
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    solve();
    return 0;
}