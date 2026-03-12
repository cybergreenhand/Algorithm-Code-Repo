#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int in[N],out[N],del[N];
vector<int> to[N];
stack<int> st;
void dfs(int u)
{
    for (int i=del[u];i<to[u].size();i=del[u])
    {
        del[u]=i+1;
        dfs(to[u][i]);
    }
    st.push(u);
}
inline void solve()
{
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=m;++i)
    {
        int u,v;
        scanf ("%d%d",&u,&v);
        to[u].push_back(v);
        ++in[v],++out[u];
    }
    bool existc=true;
    int S=0,T=0;
    for (int i=1;i<=n;++i)
    {
        if (in[i]!=out[i])
        {
            existc=false;
            if (abs(in[i]-out[i])>1)
            {
                printf ("No\n");
                return;
            }
            if (in[i]>out[i]) 
            {
                if (!T) T=i;
                else 
                {
                    printf ("No\n");
                    return;
                }
            }
            else 
            {
                if (!S) S=i;
                else
                {
                    printf ("No\n");
                    return;
                }
            }
        }
    }
    if (!existc&&(!S||!T))
    {
        printf ("No\n");
        return;
    }
    if (existc) S=1;
    for (int i=1;i<=n;++i) sort(to[i].begin(),to[i].end());
    dfs(S);
    while (st.size()) 
    {
        printf ("%d ",st.top());
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