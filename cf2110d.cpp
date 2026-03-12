#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
int in[N],tin[N],b[N];
ll dis[N];
vector<pair<int,int>> e[N];
inline bool check(int limw)
{
    queue<int> q;
    for (int i=1;i<=n;++i) 
    {
        dis[i]=LONG_LONG_MIN;
        tin[i]=in[i];
    }
    dis[1]=b[1];
    q.push(1);
    while (q.size())
    {
        int u=q.front();
        q.pop();
        // cout<<"NOW IS "<<u<<" "<<dis[u]<<endl;
        for (auto [v,w]:e[u])
        {
            --tin[v];
            if (w<=limw&&dis[u]>=w)
            {
                dis[v]=max(dis[v],dis[u]+b[v]);
                if (v==n) return true;
            }
            if (!tin[v]) q.push(v);
        }
    }
    for (int i=2;i<=n;++i)
    {
        if (tin[i]&&dis[i]>=0)
        {
            q.push(i);
            while (q.size())
            {
                int u=q.front();
                q.pop();
                for (auto [v,w]:e[u])
                {
                    --tin[v];
                    if (w<=limw&&dis[u]>=w)
                    {
                        dis[v]=max(dis[v],dis[u]+b[v]);
                        if (v==n) return true;
                    }
                    if (!tin[v]) q.push(v);
                }
            }
        }
    }
    return dis[n]>=0;
}
inline void clear()
{
    for (int i=1;i<=n;++i) 
    {
        e[i].clear();
        in[i]=0;
    }
}
inline void solve()
{
    cin>>n>>m;
    clear();
    for (int i=1;i<=n;++i) cin>>b[i];
    vector<int> num;
    for (int i=1;i<=m;++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        ++in[v];
        num.push_back(w);
    }
    if (num.empty())
    {
        cout<<"-1"<<endl;
        return;
    }
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    if (!check(num.back()))
    {
        cout<<"-1"<<endl;
        return;
    }
    int l=0,r=num.size()-1;
    while (l<r)
    {
        int mid=l+r>>1;
        if (check(num[mid])) r=mid;
        else l=mid+1;
    }
    cout<<num[r]<<endl;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}