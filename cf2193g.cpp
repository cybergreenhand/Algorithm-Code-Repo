#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n;
vector<int> p,to[N];
void dfs(int u,int fa)
{
    p.push_back(u);
    for (int v:to[u])
    {
        if (v==fa) continue;
        dfs(v,u);
    }
}
inline int ask(int u,int v)
{
    cout<<"? "<<u<<" "<<v<<endl;
    cout.flush();
    int ans;
    cin>>ans;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--)
    {
        cin>>n;
        p.clear();
        for (int i=1;i<=n;++i) to[i].clear();
        for (int i=1;i<n;++i)
        {
            int u,v;
            cin>>u>>v;
            to[u].push_back(v);
            to[v].push_back(u);
        }
        dfs(1,0);
        bool flag=false;
        for (int i=0;i+1<p.size();i+=2)
        {
            if (ask(p[i],p[i+1]))
            {
                flag=true;
                if (ask(p[i],p[i])) 
                {
                    cout<<"! "<<p[i]<<endl;
                    cout.flush();
                }
                else
                {
                    cout<<"! "<<p[i+1]<<endl;
                    cout.flush();
                }
            }
        }
        if (!flag&&p.size()&1) 
        {
            cout<<"! "<<p.back()<<endl;
            cout.flush();
        }
    }
    return 0;
}