#include <bits/stdc++.h>
using namespace std;
const int N=130;
int H,n,ans=10;
int f[N][N];
struct Rubbish{
    int t,f,h;
    bool operator< (const Rubbish &a) const{
        return t<a.t;
    }
}r[N];
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf ("%d%d",&H,&n);
    for (int i=1;i<=n;++i) scanf ("%d%d%d",&r[i].t,&r[i].f,&r[i].h);
    sort(r+1,r+n+1);
    memset(f,-0x3f,sizeof(f));
    f[0][0]=10;
    for (int i=1;i<=n;++i)
    {
        for (int j=0;j<H;++j)
        {
            if (f[i-1][j]>=r[i].t-r[i-1].t) f[i][j]=f[i-1][j]+r[i].f-(r[i].t-r[i-1].t);
            if (j>=r[i].h&&f[i-1][j-r[i].h]>=r[i].t-r[i-1].t) f[i][j]=max(f[i][j],f[i-1][j-r[i].h]-(r[i].t-r[i-1].t));
            if (f[i][j]>=0) ans=max(ans,r[i].t+f[i][j]);
            // cout<<i<<" "<<j<<" "<<ans<<endl;
        }
        for (int j=H;j<=H+25;++j)
        {
            if (f[i-1][j]>=r[i].t-r[i-1].t) f[i][j]=f[i-1][j]+r[i].f-(r[i].t-r[i-1].t);
            if (j>=r[i].h&&f[i-1][j-r[i].h]>=r[i].t-r[i-1].t) f[i][j]=max(f[i][j],f[i-1][j-r[i].h]-(r[i].t-r[i-1].t));
            if (f[i][j]>=0) 
            {
                printf ("%d\n",r[i].t);
                return 0;
            }
        }
    }   
    printf ("%d\n",ans);
    return 0;
}