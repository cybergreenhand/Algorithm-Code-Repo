#include <bits/stdc++.h>
using namespace std;
int T,n;
int main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--)
    {
        cin>>n;
        vector<int> s[10000];
        int cnt=0;
        if (n&1) 
        {
            s[++cnt].push_back(n);
            --n;
        }
        for (int i=1;i<=n;i+=2)
        {
            s[++cnt].push_back(i);
            if (i+1<=n) s[cnt].push_back(i+1);
        }
        bool flag=false;
        for (int i=1;i<=cnt;++i) 
        {
            if (s[i].size()<2) continue;
            cout<<s[i][0]<<" "<<s[i][1]<<endl;
            cout.flush();
            int ans;
            cin>>ans;
            if (ans==1) 
            {
                flag=true;
                break;
            }
        }
        if (flag) continue;
        int now=1;
        while (!flag)
        {
            for (int i:s[now])
            {
                for (int j:s[now+1])
                {
                    cout<<i<<" "<<j<<endl;
                    cout.flush();
                    int ans;
                    cin>>ans;
                    if (ans==1)
                    {
                        flag=true;
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) break;
            ++cnt;
            for (int i:s[now]) s[cnt].push_back(i);
            for (int i:s[now+1]) s[cnt].push_back(i);
            now+=2;
        }
    }
    return 0;
}