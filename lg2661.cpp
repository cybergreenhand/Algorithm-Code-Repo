#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,ans=1e9;
int fa[N],d[N];
int find(int x)
{
    if (x!=fa[x])
    {
        int t=fa[x];
        fa[x]=find(fa[x]);
        d[x]+=d[t];
    }
    return fa[x];
}
inline void merge(int x,int y)
{
    int fy=find(y);
    if (x!=fy) 
    {
        fa[x]=fy;
        d[x]=d[y]+1;
        // cout<<x<<" "<<y<<" "<<d[x]<<" "<<d[y]<<endl;
    }
    else 
    {
        // cout<<x<<" "<<y<<endl;
        // cout<<d[x]<<" "<<d[y]<<endl;
        ans=min(ans,d[y]+1);
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;++i) fa[i]=i;
    for (int i=1;i<=n;++i) 
    {
        int t;
        scanf ("%d",&t);
        merge(i,t);
    }
    printf ("%d\n",ans);
    return 0;
}