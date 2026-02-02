#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int fa[N],d[N],ans[N],to[N];
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
    }
    else
    {
        int now=y;
        while (now!=x)
        {
            ans[now]=d[y]+1;
            now=to[now];
        }
        ans[x]=d[y]+1;
    }
}
int dfs(int x)
{
    if (ans[x]!=0) return ans[x];
    else return ans[x]=dfs(to[x])+1;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;++i) fa[i]=i;
    for (int i=1;i<=n;++i) 
    {
        scanf ("%d",&to[i]);
        merge(i,to[i]);
    }
    for (int i=1;i<=n;++i) if (ans[i]==0) dfs(i);
    for (int i=1;i<=n;++i) printf ("%d\n",ans[i]);
    return 0;
}