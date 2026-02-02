#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
struct Point{
    int x,y;
    bool operator< (const Point &a) const{
        if (x!=a.x) return x<a.x;
        else return y<a.y;
    }
}p[N];
Point t[N];
inline double dis(Point a,Point b)
{
    return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+1.0*(a.y-b.y)*(a.y-b.y));
}
inline bool cmp(Point a,Point b)
{
    return a.y<b.y;
}
double divide(int l,int r)
{
    if (l>=r) return 2e9;
    if (r-l==1) return dis(p[l],p[r]);
    int mid=(l+r)>>1;
    double mi=min(divide(l,mid),divide(mid+1,r)),ans=mi;
    int cnt=0;
    for (int i=l;i<=r;++i) if (abs(p[i].x-p[mid].x)<=mi) t[++cnt]=p[i];
    sort(t+1,t+cnt+1,cmp);
    for (int i=1;i<cnt;++i)
    {
        for (int j=i+1;j<=cnt&&t[j].y-t[i].y<=mi;++j)
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
    printf ("%.4lf\n",divide(1,n));
    return 0;
}