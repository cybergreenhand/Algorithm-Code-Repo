#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e5+5,mod=998244353;
int T,n,cnt;
int h[N],to[N<<1],nxt[N<<1];
ll f[N][3];
inline void clear()
{
    cnt=0;
    for (int i=1;i<=n;++i) 
    {
        h[i]=0;
        f[i][1]=f[i][0]=1;
        f[i][2]=0;
    }
}
inline void add(int a,int b)
{
    to[++cnt]=b;
    nxt[cnt]=h[a];
    h[a]=cnt;
}
void dfs(int u,int fa)
{
    for (int i=h[u];i;i=nxt[i])
    {
        int v=to[i];
        if (v==fa) continue;
        dfs(v,u);
        f[u][1]=f[u][1]*(f[v][1]+1)%mod;
        f[u][2]=(f[u][2]+f[v][1]+f[v][2])%mod;
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&T);
    while (T--)
    {
        scanf ("%d",&n);
        clear();
        for (int i=1;i<n;++i)
        {
            int u,v;
            scanf ("%d%d",&u,&v);
            add(u,v);
            add(v,u);
        }
        dfs(1,0);
        printf ("%lld\n",(f[1][1]+f[1][2]+f[1][0])%mod);
    }
    return 0;
}