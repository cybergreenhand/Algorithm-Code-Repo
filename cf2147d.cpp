#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int T,n;
int a[N],cnt[N];
bool vis[N];
vector<int> num,odd,even;
inline void clear()
{
    num.clear();
    odd.clear();
    even.clear();
    for (int i=1;i<=n;++i)
    {
        cnt[i]=0;
        vis[i]=false;
    }
}
inline bool cmp(int i,int j)
{
    return cnt[i]>cnt[j];
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--)
    {
        cin>>n;
        clear();
        for (int i=1;i<=n;++i) 
        {
            cin>>a[i];
            if (a[i]&1) num.push_back(a[i]);
        }
        sort(num.begin(),num.end());
        auto last=unique(num.begin(),num.end());
        num.erase(last,num.end());
        for (int i=1;i<=n;++i)
        {
            if (!(a[i]&1)) continue;
            int x=lower_bound(num.begin(),num.end(),a[i])-num.begin()+1;
            ++cnt[x];
        }
        for (int i=1;i<=num.size();++i) odd.push_back(i);
        sort(odd.begin(),odd.end(),cmp);
        ll ansA=0,ansB=0;
        for (int i=0;i<odd.size();++i)
        {
            if (i&1) ansB+=cnt[odd[i]];
            else ansA+=cnt[odd[i]];
        }
        num.clear();
        for (int i=1;i<=n;++i)
        {
            if (a[i]&1) --a[i];
            if (!a[i]) continue;
            num.push_back(a[i]);
        }
        sort(num.begin(),num.end());
        last=unique(num.begin(),num.end());
        num.erase(last,num.end());
        for (int i=1;i<=num.size();++i) cnt[i]=0;
        for (int i=1;i<=n;++i)
        {
            if (!a[i]) continue;
            int x=lower_bound(num.begin(),num.end(),a[i])-num.begin()+1;
            ++cnt[x];
        }
        ll sum=0;
        for (int i=1;i<=num.size();++i) sum+=1ll*cnt[i]*num[i-1];
        sum>>=1;
        ansA+=sum;
        ansB+=sum;
        cout<<ansA<<" "<<ansB<<endl;
    }
    return 0;
}