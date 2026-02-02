#include <bits/stdc++.h>
using namespace std;
int T,n,m;
int a[200010];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    cin>>T;
    while (T--)
    {
        set<int> s,us;
        vector<int> ans;
        cin>>n>>m;
        bool flag=true;
        for (int i=1;i<=n;++i) 
        {
            cin>>a[i];
            if (1ll*a[i]*(n+1)<=m)
            {
                flag=false;
            }
            s.insert(a[i]);
            us.insert(a[i]);
        }
        if (!flag)
        {
            cout<<"-1"<<endl;
            continue;
        }
        while (s.size())
        {
            int t=*s.begin();
            ans.push_back(t);
            for (int i=1;t*i<=m;++i)
            {
                auto it=us.find(t*i);
                if (it==us.end())
                {
                    flag=false;
                    break;
                }
                auto jt=s.find(t*i);
                if (jt!=s.end()) s.erase(jt);
            }
            if (!flag) break;
        }
        if (!flag) cout<<"-1"<<endl;
        else
        {
            cout<<ans.size()<<endl;
            for (int i:ans) cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}