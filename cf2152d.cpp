#include <bits/stdc++.h>
using namespace std;
const int N=2.5e5+5;
int T,n,m;
int a[N],sum1[N],sum2[N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--)
    {
        cin>>n>>m;
        for (int i=1;i<=n;++i) cin>>a[i];
        for (int i=1;i<=n;++i) sum1[i]=sum2[i]=0;
        for (int i=1;i<=n;++i)
        {
            int j=0;
            while ((1<<j+1)<=a[i]) ++j;
            if (a[i]==(1<<j)+1) sum2[i]=1,sum1[i]=j;
            else if (a[i]==(1<<j)) sum1[i]=j;
            else sum1[i]=j+1;
            sum1[i]+=sum1[i-1];
            sum2[i]+=sum2[i-1];
        }
        while (m--)
        {
            int l,r;
            cin>>l>>r;
            cout<<sum1[r]-sum1[l-1]+((sum2[r]-sum2[l-1])>>1)<<endl;
        }
    }
    return 0;
}