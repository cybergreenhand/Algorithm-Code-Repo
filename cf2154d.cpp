#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
typedef pair<int,int> pii;
const int N=2e5+5;
int T,n,cnt;
int h[N],to[N<<1],nxt[N<<1],dis[N],f[N],in[N];
vector<int> d;
vector<pii> ans;
inline void clear()
{
    ans.clear();
    d.clear();
    cnt=0;
    for (int i=1;i<=n;++i) 
    {
        h[i]=0;
        in[i]=0;
        dis[i]=0;
    }
}
inline void add(int a,int b)
{
    to[++cnt]=b;
    nxt[cnt]=h[a];
    h[a]=cnt;
}
void dfs(int u,int fa)
{
    for (int i=h[u];i;i=nxt[i])
    {
        int v=to[i];
        if (v==fa) continue;
        dis[v]=dis[u]+1;
        f[v]=u;
        ++in[u];
        dfs(v,u);
    }
}
inline void topsort()
{
    queue<int> q;
    for (int i=1;i<n;++i) 
    {
        if (!in[i]) 
        {
            q.push(i);
            d.push_back(i);
        }
    }
    while (q.size())
    {
        int u=q.front();
        q.pop();
        int fa=f[u];
        if (--in[fa]==0&&fa!=n) 
        {
            q.push(fa);
            d.push_back(fa);
        }
    }
}
void dfs2(int u)
{
    d.push_back(u);
    for (int i=h[u];i;i=nxt[i])
    {
        int v=to[i];
        if (v==f[u]) continue;
        if (!in[v]) continue;
        dfs2(v);
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--)
    {
        clear();
        cin>>n;
        for (int i=1;i<n;++i)
        {
            int u,v;
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        dfs(1,0);
        topsort();
        dfs2(1);
        int last=0;
        for (int u:d)
        {
            int num=last^(dis[u]&1)?2:1;
            for (int i=1;i<=num;++i) ans.push_back({1,0});
            ans.push_back({2,u});
            last^=(num&1);
        }
        cout<<ans.size()<<endl;
        for (auto i:ans)
        {
            if (i.fir==1) cout<<"1"<<endl;
            else cout<<"2 "<<i.sec<<endl;
        }
        cout<<endl;
    }
    return 0;
}