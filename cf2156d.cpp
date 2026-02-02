#include <bits/stdc++.h>
using namespace std;
int T,n;
vector<int> num,q,p[2];
int main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--)
    {
        q.clear();
        num.clear();
        cin>>n;
        for (int i=1;i<=n;++i) 
        {
            num.push_back(i);
            if (i<n) q.push_back(i);
        }
        for (int i=0;(1<<i)<=n&&num.size()>1;++i)
        {
            p[0].clear();
            p[1].clear();
            int cnt=0;
            for (int j:num) if (j&(1<<i)) ++cnt;
            for (int j:q)
            {
                cout<<"? "<<j<<" "<<(1<<i)<<endl;
                cout.flush();
                int a;
                cin>>a;
                p[a].push_back(j);
            }
            q.clear();
            vector<int> tmp;
            if (!p[1].empty()&&p[1].size()==cnt)
            {
                if (!p[0].empty()) for (int j:p[0]) q.push_back(j);
                for (int j:num) if (!(j&(1<<i))) tmp.push_back(j);
                num.clear();
                for (int j:tmp) num.push_back(j);
            }
            else
            {   
                if (!p[1].empty()) for (int j:p[1]) q.push_back(j);
                for (int j:num) if (j&(1<<i)) tmp.push_back(j);
                num.clear();
                for (int j:tmp) num.push_back(j);
            }
        }
        cout<<"! "<<num[0]<<endl;
    }
    return 0;
}