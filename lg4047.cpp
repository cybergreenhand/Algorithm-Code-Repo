#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m;
int x[N],y[N],dis[N];
bool vis[N];
vector<int> edge;
inline int getd(int i,int j)
{
    return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;++i) scanf ("%d%d",&x[i],&y[i]);
    memset(dis,0x3f,sizeof (dis));
    dis[1]=0;
    for (int i=1;i<=n;++i)
    {
        int minid=0;
        for (int j=1;j<=n;++j) if (!vis[j]&&dis[j]<dis[minid]) minid=j;
        vis[minid]=true;
        edge.push_back(dis[minid]);
        for (int j=1;j<=n;++j) if (!vis[j]) dis[j]=min(dis[j],getd(minid,j));
    }
    sort(edge.begin(),edge.end(),greater<int>());
    printf ("%.2lf\n",sqrt(1.0*edge[m-2]));
    return 0;
}