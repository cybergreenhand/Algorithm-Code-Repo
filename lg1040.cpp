#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int rt[35][35];
ll f[35][35];
ll dfs(int l,int r)
{
    if (f[l][r]) return f[l][r];
    if (l>r) return 1;
    for (int i=l;i<=r;++i) 
    {
        ll t=dfs(l,i-1)*dfs(i+1,r)+f[i][i];
        if (t>f[l][r])
        {
            f[l][r]=t;
            rt[l][r]=i;
        }
    }
    return f[l][r];
}
void print(int l,int r)
{
    if (l>r) return;
    printf ("%d ",rt[l][r]);
    print(l,rt[l][r]-1);
    print(rt[l][r]+1,r);
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;++i) 
    {
        scanf ("%lld",&f[i][i]);
        rt[i][i]=i;
    }
    printf ("%lld\n",dfs(1,n));
    print(1,n);
    return 0;
}