#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n;
int p[N],f[N][N][2],sum[N];
vector<int> num;
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;++i) 
    {
        scanf ("%d",&p[i]);
        num.push_back(p[i]);
    }
    num.push_back(0);
    sort(num.begin(),num.end());
    auto last=unique(num.begin(),num.end());
    num.erase(last,num.end());
    for (int i=1;i<=n;++i)
    {
        int x=lower_bound(num.begin(),num.end(),p[i])-num.begin()+1;
        ++sum[x];
    }
    n=num.size();
    for (int i=2;i<=n;++i) sum[i]+=sum[i-1];
    int s=lower_bound(num.begin(),num.end(),0)-num.begin()+1;
    memset(f,0x3f,sizeof (f));
    f[s][s][0]=f[s][s][1]=0;
    for (int len=2;len<=n;++len)
    {
        for (int l=max(s-len+1,1),r=l+len-1;l<=s&&r<=n;++l,++r)
        {
            int res=sum[n]-sum[r-1]+sum[l-1];
            f[l][r][1]=min(f[l][r-1][1]+res*(num[r-1]-num[r-2]),f[l][r-1][0]+res*(num[r-1]-num[l-1]));
            res=sum[n]-sum[r]+sum[l];
            f[l][r][0]=min(f[l+1][r][0]+res*(num[l]-num[l-1]),f[l+1][r][1]+res*(num[r-1]-num[l-1]));
        }
    }
    printf ("%d\n",min(f[1][n][0],f[1][n][1]));
    return 0;
}