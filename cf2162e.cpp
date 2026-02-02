#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,m;
int a[N];
bool vis[N];
vector<int> av,nav;
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    cin>>T;
    while (T--)
    {
        av.clear();
        nav.clear();
        memset(vis,false,sizeof (vis));
        cin>>n>>m;
        for (int i=1;i<=n;++i) 
        {
            cin>>a[i];
        }
        for (int i=n;i>=1;--i)
        {
            if (!vis[a[i]]) 
            {
                vis[a[i]]=true;
                nav.push_back(a[i]);
            }
        }
        reverse(nav.begin(),nav.end());
        for (int i=1;i<=n;++i) if (!vis[i]) av.push_back(i);
        bool flag=av.empty()?false:true,is=false;
        if (!av.empty()&&av.size()==1) is=true;
        for (int i=1;i<=m;++i)
        {
            if (!av.empty())
            {
                cout<<av.back()<<" ";
                av.pop_back();
            }
            else if (!nav.empty()&&is)
            {
                int t=nav.back();
                nav.pop_back();
                cout<<nav.back()<<" ";
                nav.pop_back();
                nav.push_back(t);
                is=false;
            }
            else if (!nav.empty()&&flag)
            {
                cout<<nav.back()<<" ";
                nav.pop_back();
            }
            else if (!nav.empty()&&!flag) cout<<nav[i-1]<<" ";
        }
        cout<<endl;
    }
    return 0;
}