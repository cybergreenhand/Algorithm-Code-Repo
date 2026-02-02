#include <bits/stdc++.h>
using namespace std;
int n,maxa,mina=100,sum;
int a[70],cnt[55];
bool dfs(int res,int num,int len,int last)
{
    if (res<mina) return false;
    if (num==1) return true;
    for (int i=min(last,res);i>=mina;--i)
    {
        if (cnt[i])
        {
            --cnt[i];
            if (i==res)
            {
                if (dfs(len,num-1,len,maxa)) return true;
                else 
                {
                    ++cnt[i];
                    return false;
                }
            }
            else 
            {
                if (dfs(res-i,num,len,i)) return true;
                else
                {
                    if (res==len)
                    {
                        ++cnt[i];
                        return false;
                    }
                }
            }
            ++cnt[i];
        }
    }
    return false;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=1;i<=n;++i) 
    {
        cin>>a[i];
        if (a[i]>50)
        {
            --i;
            continue;
        }
        sum+=a[i];
        ++cnt[a[i]];
        maxa=max(maxa,a[i]);
        mina=min(mina,a[i]);
    }
    for (int i=maxa;i<=sum;++i) 
    {
        if (sum%i==0) 
        {
            if (dfs(i,sum/i,i,maxa))
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;  
}