#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,tt;
int v[N],p[N],del[N<<1],st[N<<1];
vector<int> numv,nump;
vector<pair<int,int>> to[N<<1];
bool vis[N],link[N<<1];
map<pair<int,int>,int> mp;
void dfs(int u)
{
    for (int i=del[u];i<to[u].size();i=del[u])
    {
        auto [v,id]=to[u][i];
        del[u]=i+1;
        if (vis[id]) continue;
        vis[id]=true;
        // cout<<u<<" "<<v<<endl;
        dfs(v);
    }
    st[++tt]=u;
}
inline void clear()
{
    tt=0;
    mp.clear();
    numv.clear();
    nump.clear();
    for (int i=1;i<=n;++i) vis[i]=false;
    for (int i=1;i<=(n<<1);++i)
    {
        link[i]=false;
        to[i].clear();
        del[i]=0;
    }
}
inline void solve()
{
    cin>>n;
    clear();
    for (int i=1;i<=n;++i)
    {
        cin>>v[i]>>p[i];
        numv.push_back(v[i]);
        nump.push_back(p[i]);
    }
    // cout<<n<<endl;
    // for (int i=1;i<=n;++i) cout<<v[i]<<" "<<p[i]<<endl;
    sort(numv.begin(),numv.end());
    numv.erase(unique(numv.begin(),numv.end()),numv.end());
    sort(nump.begin(),nump.end());
    nump.erase(unique(nump.begin(),nump.end()),nump.end());
    for (int i=1;i<=n;++i)
    {
        v[i]=lower_bound(numv.begin(),numv.end(),v[i])-numv.begin()+1;
        p[i]=lower_bound(nump.begin(),nump.end(),p[i])-nump.begin()+1;
        mp[{v[i],p[i]+numv.size()}]=i;
        to[v[i]].push_back({p[i]+numv.size(),i});
        to[p[i]+numv.size()].push_back({v[i],i});
    }
    queue<int> q;
    link[1]=true;
    q.push(1);
    while (q.size())
    {
        int u=q.front();
        q.pop();
        for (auto [v,id]:to[u])
        {
            if (link[v]) continue;
            link[v]=true;
            q.push(v);
        }
    }
    for (int i=1;i<=numv.size()+nump.size();++i)
    {
        if (!link[i])
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    int S=0,T=0;
    for (int i=1;i<=numv.size();++i)
    {
        if (to[i].size()&1)
        {
            if (!S) S=i;
            else if (!T) T=i;
            else
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    for (int i=numv.size()+1;i<=numv.size()+nump.size();++i)
    {
        if (to[i].size()&1)
        {
            if (!S) S=i;
            else if (!T) T=i;
            else
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    if (S&&!T) 
    {
        cout<<"NO"<<endl;
        return;
    }
    if (!S) S=1;
    dfs(S);
    cout<<"YES"<<endl;
    reverse(st+1,st+tt+1);
    for (int i=1;i<tt;++i) 
    {
        if (st[i]<=numv.size()) cout<<mp[{st[i],st[i+1]}]<<" ";
        else cout<<mp[{st[i+1],st[i]}]<<" ";
    }
    cout<<endl;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    // cout<<T<<endl;
    while (T--) solve();
    return 0;
}