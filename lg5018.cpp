#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,ans;
int sz[N],val[N],l[N],r[N];
void calc(int u)
{
    if (u==-1) return;
    sz[u]=1;
    calc(l[u]);
    calc(r[u]);
    sz[u]+=sz[l[u]]+sz[r[u]];
}
bool check(int u,int v)
{
    if (u==-1&&v==-1) return true;
    if ((u!=v)&&(u==-1||v==-1)) return false;
    if (val[u]!=val[v]) return false;
    return check(l[u],r[v])&&check(r[u],l[v]);
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;++i) scanf ("%d",&val[i]);
    for (int i=1;i<=n;++i) scanf ("%d%d",&l[i],&r[i]);
    calc(1);
    for (int i=1;i<=n;++i) if (check(i,i)) ans=max(ans,sz[i]);
    printf ("%d\n",ans);
    return 0;
}