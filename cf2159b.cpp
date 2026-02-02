#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N=505,M=250005,INF=1e9;
int T,n,m;
int minn[N];
string str[M],strt[N];
vector<vector<int>> ans,tag;
inline void solve(string s[])
{
    for (int u=1;u<n;++u)
    {
        for (int d=u+1;d<=n;++d)
        {
            int pre=0;
            for (int j=1;j<=m;++j)
            {
                if (s[u][j]=='1'&&s[d][j]=='1')
                {
                    // cout<<u<<" "<<d<<" "<<j<<endl;
                    if (pre) 
                    {
                        // cout<<j<<" "<<pre<<endl;
                        for (int k=pre;k<=j;++k)
                        {
                            tag[d][k]=min(tag[d][k],(d-u+1)*(j-pre+1));
                        }
                    }
                    pre=j;
                }
            }
        }
        for (int j=1;j<=m;++j)
        {
            for (int k=u;k<=n+1;++k) minn[k]=INF;
            for (int k=n;k>=u;--k)
            {
                minn[k]=min(tag[k][j],minn[k+1]);
                ans[k][j]=min(ans[k][j],minn[k]);
            }
        }
    }
}
inline void work()
{
    cin>>n>>m;
    for (int i=1;i<=n;++i) 
    {
        cin>>str[i];
        str[i]=" "+str[i];
    }
    bool ist=false;
    if (n>m)
    {
        ist=true;
        swap(n,m);
        for (int i=1;i<=n;++i)
        {
            strt[i].reserve(m+1);
            for (int j=1;j<=m;++j)
            {
                strt[i][j]=str[j][i];
            }
        }
    }
    ans.assign(n+1,vector<int>(m+1,INF));
    tag.assign(n+1,vector<int>(m+1,INF));
    if (ist) solve(strt);
    else solve(str);
    if (ist)
    {
        for (int i=1;i<=m;++i)
        {
            for (int j=1;j<=n;++j)
            {
                if (ans[j][i]==INF) cout<<"0"<<" ";
                else cout<<ans[j][i]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        for (int i=1;i<=n;++i)
        {
            for (int j=1;j<=m;++j)
            {
                if (ans[i][j]==INF) cout<<"0"<<" ";
                else cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while (T--) work();
    return 0;
}