#include <bits/stdc++.h>
using namespace std;
const double P=3.1415926,eps=1e-5;
int n,maxx,maxy,minx=1e9,miny=1e9,cnt;
double ans;
int x[10],y[10];
bool vis[10];
double r[10];
inline double dist(int i,int j)
{
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
inline bool check(int id,double R)
{
    if (x[id]+R>maxx+eps||x[id]-R+eps<minx||y[id]+R>maxy+eps||y[id]-R+eps<miny) return false;
    for (int i=1;i<=n;++i)
    {
        if (!vis[i]||i==id) continue;
        if (dist(i,id)-R-r[i]<eps) return false;
    }
    return true;
}
void dfs(double s)
{
    if (cnt==n)
    {
        ans=max(ans,s);
        return;
    }
    for (int i=1;i<=n;++i)
    {
        if (vis[i]) continue;
        vis[i]=true;
        ++cnt;
        double L=0,R=min(maxx-minx,maxy-miny);
        while (R-L>eps)
        {
            double mid=(L+R)/2;
            if (check(i,mid)) L=mid;
            else R=mid;
        }
        r[i]=L;
        dfs(s+P*r[i]*r[i]);
        --cnt;
        vis[i]=false;
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=2;++i)
    {
        int X,Y;
        scanf ("%d%d",&X,&Y);
        maxx=max(maxx,X);
        minx=min(minx,X);
        maxy=max(maxy,Y);
        miny=min(miny,Y);
    }
    for (int i=1;i<=n;++i) scanf ("%d%d",&x[i],&y[i]);
    dfs(0);
    printf ("%.0lf\n",(maxx-minx)*(maxy-miny)-round(ans));
    return 0;
}