#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3.5e4+5;
int n;
int a[N],b[N],f[N],len[N];
ll g[N],suml[N],sumr[N];
vector<int> to[N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) 
    {
        cin>>a[i];
        b[i]=a[i]-i;
    }
    memset(f,0x3f,sizeof (f));
    int ans=0;
    for (int i=1;i<=n;++i)
    {
        int j=upper_bound(f+1,f+n+1,b[i])-f;
        f[j]=b[i];
        len[i]=j;
        to[j].push_back(i);
        ans=max(ans,j);
    }
    cout<<n-ans<<endl;
    b[0]=-0x3f3f3f3f;
    to[0].push_back(0);
    b[n+1]=0x3f3f3f3f;
    len[n+1]=ans+1;
    memset(g,0x3f,sizeof (g));
    g[0]=0;
    for (int i=1;i<=n+1;++i)
    {
        for (int j:to[len[i]-1])
        {
            if (j>i||b[j]>b[i]) continue;
            suml[j]=sumr[i]=0;
            for (int k=j+1;k<i;++k) suml[k]=suml[k-1]+abs(b[k]-b[j]);
            for (int k=i-1;k>j;--k) sumr[k]=sumr[k+1]+abs(b[k]-b[i]);
            for (int k=j;k<i;++k) g[i]=min(g[i],g[j]+suml[k]+sumr[k+1]);
        }
    }
    cout<<g[n+1]<<endl;
    return 0;
}