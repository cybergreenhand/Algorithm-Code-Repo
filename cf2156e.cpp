#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n;
int a[N];
bool vis[N];
vector<int> num,val;
vector<int> pre[N],nxt[N];
inline bool check(int x)
{
    val.clear();
    for (int i=1;i<=n;++i)
    {
        pre[i].clear();
        nxt[i].clear();
    }
    int minid[]={0,0,0};
    minid[0]=1;
    for (int i=2;i<=n;++i)
    {
        for (int j=0;j<3;++j)
        {
            if (!minid[j]) break;
            if (num[a[minid[j]]-1]<=num[a[i]-1]-x) 
            {
                pre[i].push_back(minid[j]);
                nxt[minid[j]].push_back(i);
            }
            else break;
        }
        if ((minid[2]&&a[i]<=a[minid[2]])||(!minid[2]&&minid[1])) minid[2]=i;
        else if (!minid[1]||(minid[1]&&a[i]<=a[minid[1]])) minid[1]=i;
        if (minid[2]==i||minid[1]==i)
        {
            for (int j=2;j;--j) 
            {
                if (!minid[j]) continue;
                if (a[minid[j]]<a[minid[j-1]]) swap(minid[j],minid[j-1]);
                else break;
            }
        }
    }
    for (int i=1;i<=n;++i) if (pre[i].size()+nxt[i].size()>=2) val.push_back(i);
    for (int i=1;i<=n;++i)
    {
        bool flag=false;
        for (int j:pre[i]) vis[j]=true;
        for (int j:nxt[i]) vis[j]=true;
        for (int j:val)
        {
            if (j==i) continue;
            if (vis[j])
            {
                if (pre[j].size()+nxt[j].size()>2) 
                {
                    flag=true;
                    break;
                }
            }
            else
            {
                flag=true;
                break;
            }
        }
        for (int j:pre[i]) vis[j]=false;
        for (int j:nxt[i]) vis[j]=false;
        if (!flag) return false;
    }
    return true;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&T);
    while (T--)
    {
        num.clear();
        scanf ("%d",&n);
        for (int i=1;i<=n;++i) 
        {
            scanf ("%d",&a[i]);
            num.push_back(a[i]);
        }
        sort(num.begin(),num.end());
        auto last=unique(num.begin(),num.end());
        num.erase(last,num.end());
        for (int i=1;i<=n;++i) a[i]=lower_bound(num.begin(),num.end(),a[i])-num.begin()+1;
        int l=num[0]-num.back(),r=num.back()-num[0];
        while (l<r)
        {
            int mid=(l+r+1)>>1;
            if (check(mid)) l=mid;
            else r=mid-1;
        }
        printf ("%d\n",l);
    }
    return 0;
}