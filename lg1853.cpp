#include <bits/stdc++.h>
using namespace std;
const int N=5e4+10;
int s,n,d,sum;
int a[15],b[15],f[N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d%d",&s,&n,&d);
    s/=1000;
    for (int i=1;i<=d;++i)
    {
        scanf ("%d%d",&a[i],&b[i]);
        a[i]/=1000;
    }
    for (int i=1;i<=n;++i)
    {
        memset(f,0,sizeof(f));
        for (int j=1;j<=d;++j)
        {
            for (int k=a[j];k<=s;++k)
            {
                f[k]=max(f[k],f[k-a[j]]+b[j]);
            }
        }
        // cout<<f[s]<<endl;
        sum+=f[s];
        int t=sum/1000;
        sum-=(t*1000);
        s+=t;
        // cout<<s<<" "<<sum<<endl;
    }
    printf ("%d\n",s*1000+sum);
    return 0;
}