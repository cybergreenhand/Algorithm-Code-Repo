#include <bits/stdc++.h>
using namespace std;
const int N=16005;
int n,cnt,ans=INT_MIN;
int a[N],f[N],h[N],to[N<<1],nxt[N<<1];
inline void add(int x,int y)
{
    to[++cnt]=y;
    nxt[cnt]=h[x];
    h[x]=cnt;
}
void dfs(int x,int fa)
{
    f[x]=a[x];
    for (int i=h[x];i;i=nxt[i])
    {
        int y=to[i];
        if (y==fa) continue;
        dfs(y,x);
        f[x]+=max(f[y],0);
    }
    ans=max(ans,f[x]);
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;++i) scanf ("%d",&a[i]);
    for (int i=1;i<n;++i)
    {
        int x,y;
        scanf ("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    printf ("%d\n",ans);
    return 0;
}