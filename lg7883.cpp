#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=4e5+10;
int n;
struct Point{
    int x,y;
    bool operator< (const Point &a) const{
        if (x!=a.x) return x<a.x;
        else return y<a.y;
    }
}p[N];
Point t[N];
inline ll dis(Point a,Point b)
{
    return 1ll*(a.x-b.x)*(a.x-b.x)+1ll*(a.y-b.y)*(a.y-b.y);
}
inline bool cmp(Point a,Point b)
{
    return a.y<b.y;
}
ll divide(int l,int r)
{
    if (l>=r) return 1e18;
    if (r-l==1) return dis(p[l],p[r]);
    int mid=(l+r)>>1;
    ll ans=min(divide(l,mid),divide(mid+1,r));
    double mn=sqrt(ans);
    int cnt=0;
    for (int i=l;i<=r;++i) if (abs(p[i].x-p[mid].x)<=mn) t[++cnt]=p[i];
    sort(t+1,t+cnt+1,cmp);
    for (int i=1;i<cnt;++i)
    {
        for (int j=i+1;j<=cnt&&t[j].y-t[i].y<=mn;++j)
        {
            ans=min(ans,dis(t[i],t[j]));
        }
    }
    return ans;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;++i) scanf ("%d%d",&p[i].x,&p[i].y);
    sort(p+1,p+n+1);
    printf ("%lld\n",divide(1,n));
    return 0;
}