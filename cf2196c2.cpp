#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
typedef pair<int,int> pii;
const int N=35;
int n;
int cnt[N],st[N];
map<pii,bool> edge;
map<int,vector<int>> node;
vector<pii> ans;
inline void clear()
{
    ans.clear();
    edge.clear();
    node.clear();
    for (int i=1;i<=n;++i) 
    {
        cnt[i]=0;
        st[i]=0;
    }
}
inline int ask(int k)
{
    cout<<"? "<<k<<endl;
    int q;
    cin>>q;
    if (!q) return 0;
    vector<int> path(q);
    for (int i=0;i<q;++i) cin>>path[i];
    node[k]=path;
    return q;
}
inline void solve()
{
    cin>>n;
    clear();
    vector<int> t(1);
    t[0]=1;
    node[1]=t;
    st[1]=1;
    for (int i=2,pre=1;;)
    {
        int len=ask(i);
        if (!len) break;
        for (int j=0;j<node[i].size()-1;++j) 
        {
            if (!edge.count({node[i][j],node[i][j+1]})) 
            {
                ans.push_back({node[i][j],node[i][j+1]});
                edge[{node[i][j],node[i][j+1]}]=true;
            }
        }
        for (int j:node[i]) if (!st[j]) st[j]=i;
        if (node[i].size()<=node[pre].size())
        {
            for (int j=node[i].size()-1;j<node[pre].size();++j)
            {
                int u=node[pre][j];
                if (!cnt[u]) cnt[u]=i-st[u];
            }
        }
        pre=i;
        if (!cnt[node[i].back()]) ++i;
        else i+=cnt[node[i].back()];
    }
    cout<<"! "<<ans.size()<<endl;
    for (auto i:ans) cout<<i.fir<<" "<<i.sec<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}