#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+5;
int n,x0;
ll ans;
ll f[N][N][2];
struct Egg{
    int x,y,v;
    bool operator< (const Egg &t) const 
    {
        return x<t.x;
    } 
}a[N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&x0);
    a[n+1].x=x0;
    for (int i=1;i<=n;++i) scanf("%d",&a[i].x);
    for (int i=1;i<=n;++i)
    {
        scanf ("%d",&a[i].y);
        ans+=a[i].y;
    }
    for (int i=1;i<=n;++i) scanf("%d",&a[i].v);
    n++;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i)
    {
        for (int j=i;j<=n;++j)
        {
            f[i][j][0]=f[i][j][1]=1e18;
        }
    }
    for (int i=1;i<=n;++i)
    {
        if (a[i].x==x0)
        {
            f[i][i][0]=f[i][i][1]=0;
            break;
        }
    }
    for (int i=1;i<=n;++i) a[i].v+=a[i-1].v;
    for (int i=1;i<=n;++i)
    {
        for (int l=1,r=l+i;r<=n;++l,++r)
        {
            f[l][r][0]=min(f[l+1][r][0]+1ll*(a[l+1].x-a[l].x)*(a[l].v+a[n].v-a[r].v),f[l+1][r][1]+1ll*(a[r].x-a[l].x)*(a[l].v+a[n].v-a[r].v));
            f[l][r][1]=min(f[l][r-1][0]+1ll*(a[r].x-a[l].x)*(a[l-1].v+a[n].v-a[r-1].v),f[l][r-1][1]+1ll*(a[r].x-a[r-1].x)*(a[l-1].v+a[n].v-a[r-1].v));
        }
    }
    printf("%.3lf\n",(ans-min(f[1][n][0],f[1][n][1]))/1000.0);
    return 0;
}
