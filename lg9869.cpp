#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,cntn;
int lastp[N],vis[N<<2],lastn[N],org[N<<1];
bool unk[N];
vector<int> to[N<<2],node;
inline void clear()
{
    for (int i=1;i<=n;++i) unk[i]=false;
    for (int i=1;i<=(n+m)*2+3;++i) 
    {
        to[i].clear();
        vis[i]=0;
    }
}
inline int get(char c)
{
    if (c=='T') return (n+m)*2+1;
    else if (c=='F') return (n+m)*2+2;
    else return (n+m)*2+3;
}
inline void add(int a,int b)
{
    to[a].push_back(b);
    to[b].push_back(a);
}
inline void create(int i)
{
    lastp[i]=++cntn;
    lastn[i]=++cntn;
}
inline void bfs(int u,int times)
{
    queue<int> q;
    q.push(u);
    while (q.size())
    {
        int u=q.front();
        q.pop();
        vis[u]=times;
        if (u<=n*2) node.push_back(u);
        for (int v:to[u])
        {
            if (vis[v]) continue;
            q.push(v);
        }
    }
}
inline void solve()
{
    cin>>n>>m;
    clear();
    for (int i=1;i<=n;++i)
    {
        lastp[i]=i;
        lastn[i]=i+n;
        org[i]=org[i+n]=i;
    }
    cntn=n*2;
    for (int k=1;k<=m;++k)
    {
        char opt;
        cin>>opt;
        if (opt=='+')
        {
            int i,j;
            cin>>i>>j;
            if (i==j) continue;
            create(i);
            add(lastp[i],lastp[j]);
            add(lastn[i],lastn[j]);
        }
        else if (opt=='-')
        {
            int i,j;
            cin>>i>>j;
            int a=lastp[j],b=lastn[j];
            create(i);
            if (i==j)
            {
                add(lastp[i],b);
                add(lastn[i],a);
            }
            else
            {
                add(lastp[i],lastn[j]);
                add(lastn[i],lastp[j]);
            }
        }
        else
        {
            int i;
            cin>>i;
            create(i);
            if (opt=='T')
            {
                add(lastp[i],get('T'));
                add(lastn[i],get('F'));
            }
            else if (opt=='F')
            {
                add(lastp[i],get('F'));
                add(lastn[i],get('T'));
            }
            else
            {
                add(lastp[i],get('U'));
                add(lastn[i],get('U'));
            }
        }
    }
    for (int i=1;i<=n;++i) 
    {
        if (lastp[i]!=i)
        {
            add(i,lastp[i]);
            add(i+n,lastn[i]);
        }
    }
    int times=1;
    node.clear();
    bfs(get('U'),times);
    for (int i:node) unk[org[i]]=true;
    for (int i=1;i<=n;++i) 
    {
        if (vis[i]||vis[i+n]) continue;
        node.clear();
        bfs(i,++times);
        bool flag=false;
        for (int j:node) 
        {
            if (vis[org[j]]==vis[org[j]+n]) 
            {
                flag=true;
                break;
            }
        }
        if (flag) for (int j:node) unk[org[j]]=true;
    }
    int ans=0;
    for (int i=1;i<=n;++i) if (unk[i]) ++ans;
    cout<<ans<<endl;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int C,T;
    cin>>C>>T;
    while (T--) solve();
    return 0;
}