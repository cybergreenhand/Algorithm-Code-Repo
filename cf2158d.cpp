#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
typedef pair<int,int> pii;
int T,n;
string cs,ce;
vector<pii> ans;
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    cin>>T;
    while (T--)
    {
        ans.clear();
        cin>>n;
        cin>>cs>>ce;
        cs=" "+cs;
        ce=" "+ce;
        if (cs[1]!=cs[2])
        {
            if (cs[2]==cs[3]) 
            {
                ans.push_back({2,3});
                if (cs[2]=='0') cs[2]=cs[3]='1';
                else cs[2]=cs[3]='0';
            }
            else
            {
                if (cs[3]==cs[4])
                {
                    ans.push_back({3,4});
                    ans.push_back({2,4});
                    cs[2]=cs[3];
                }
                else 
                {
                    ans.push_back({2,4});
                    for (int i=2;i<=4;++i)
                    {
                        if (cs[i]=='0') cs[i]='1';
                        else cs[i]='0';
                    }
                }
            }
        }
        int nowb=cs[1]-'0';
        for (int i=1;i<=n;++i)
        {
            int j=i;
            while (j<=n&&cs[j]-'0'==nowb) ++j;
            ans.push_back({1,j-1});
            nowb^=1;
            i=j;
        }
        for (int i=1;i+3<=n;++i)
        {
            int j=i;
            while (j+3<n&&ce[j]-'0'==nowb) ++j;
            if (j+3<n) 
            {
                ans.push_back({j,n});
                nowb^=1;
            }
            else if (j+3==n)
            {
                int cnt1=0,cnt0=0;
                for (int k=j;k<=n;++k) 
                {
                    if (ce[k]=='0') ++cnt0;
                    else ++cnt1;
                }
                // cout<<cnt0<<" "<<cnt1<<endl;
                if (max(cnt0,cnt1)==4) 
                {
                    // cout<<nowb<<endl;
                    if ((cnt0==4&&nowb==1)||(cnt1==4&&nowb==0))
                    {
                        ans.push_back({j,n});
                    }
                }
                else if (max(cnt0,cnt1)==3)
                {
                    char dif=cnt0==3?'1':'0';
                    int difp=j;
                    for (int k=j;k<=n;++k) 
                    {
                        if (ce[k]==dif)
                        {
                            difp=k;
                            break;
                        }
                    } 
                    // cout<<difp<<endl;
                    switch (difp-j+1)
                    {
                        case 1:
                            if (ce[j]-'0'==nowb) ans.push_back({j+1,n});
                            else 
                            {
                                ans.push_back({j,n});
                                ans.push_back({j+1,n});
                            }
                            break;
                        case 2:
                            if (ce[j]-'0'!=nowb) ans.push_back({j,n});
                            ans.push_back({j+1,n});
                            ans.push_back({j+2,n});
                            break;
                        case 3:
                            if (ce[n]-'0'!=nowb) ans.push_back({j,n});
                            ans.push_back({j,n-1});
                            ans.push_back({j,n-2});
                            break;
                        case 4:
                            if (ce[n]-'0'!=nowb) ans.push_back({j,n});
                            ans.push_back({j,n-1});
                            break;
                        default:break;
                    }
                }
                else 
                {
                    if (ce[j]!=ce[j+1]&&ce[j+1]!=ce[j+2])
                    {
                        if (ce[j]-'0'!=nowb) ans.push_back({j,n});
                        ans.push_back({j,j+2});
                        ans.push_back({j,j+1});
                        ans.push_back({j+1,n});
                    }
                    else
                    {
                        if (ce[j]==ce[j+1])
                        {
                            if (ce[j]-'0'==nowb) ans.push_back({n-1,n});
                            else ans.push_back({j,j+1});
                        }
                        else if (ce[j+1]==ce[j+2])
                        {
                            if (ce[j]-'0'!=nowb) ans.push_back({j,n});
                            ans.push_back({j+1,j+2});
                        }
                    }
                }
            }
            i=j;
        }
        cout<<ans.size()<<endl;
        for (pii i:ans) cout<<i.fir<<" "<<i.sec<<endl;
    }
    return 0;
}