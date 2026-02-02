#include <bits/stdc++.h>
using namespace std;
int n,m,T;
string str;
inline int eval(string s)
{
    int sum=0;
    for (int i=1;i<=n;++i)
    {
        if (s[i]=='V') sum+=5;
        else if (s[i]=='I')
        {
            if (i<n&&s[i+1]=='V') sum-=1;
            else sum+=1;
        }
    }
    return sum;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--)
    {
        cin>>n>>m;
        cin>>str;
        str=" "+str;
        int ans=0;
        for (int i=1;i<=n;++i)
        {
            if (str[i]=='X')
            {
                str[i]='V';
                ans+=5;
            }
        }
        int inc=0,same=0,cntq=0;
        for (int i=1;i<=n;++i)
        {
            if (str[i]!='?') continue;
            int j=i;
            while (j<=n&&str[j]=='?') ++j;
            int len=j-i;
            if (i>1&&str[i-1]=='I') ++len;
            if (j<=n&&str[j]=='V')
            {
                --inc;
                ++len;
            }
            inc+=len/2;
            same+=len%2;
            cntq+=j-i;
            i=j-1;
        }
        // cout<<inc<<" "<<same<<" "<<cntq<<endl;
        for (int i=1;i<=n;++i) if (str[i]=='?') str[i]='I';
        ans+=eval(str);
        // cout<<ans<<endl;
        while (m--)
        {
            int cx,cv,ci;
            cin>>cx>>cv>>ci;
            int uv=max(0,min(cv,cntq-ci)),ux=max(0,cntq-cv-ci);
            int cur=ans;
            cur+=uv*4+ux*9;
            int res=uv+ux;
            cur-=min(inc,res)*2;
            res-=(inc+same);
            cur+=max(0,res)*2;
            cout<<cur<<endl;
        }
    }
    return 0;
}