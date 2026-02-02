#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=1e6+5,M=6e4+5,E=3e4;
int n,m;
ll a[2][N+M];
inline void jump(int l,int r,int d)
{
    a[0][l]+=d;
    a[0][r+1]-=d;
    a[1][l+1]+=d;
    a[1][((l+r)>>1)+1]-=(d<<1);
    a[1][r+1]+=d;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
    {
        int v,x;
        scanf ("%d%d",&v,&x);
        jump (x-v+1+E,x+v-1+E,-1);
        jump (x-3*v+1+E,x-v-1+E,1);
        jump (x+v+1+E,x+3*v-1+E,1);
    }
    for (int i=1;i<=m+E;++i)
    {
        a[1][i]+=a[1][i-1];
        a[0][i]+=(a[0][i-1]+a[1][i]);
    }
    for (int i=1+E;i<=m+E;++i) printf ("%lld ",a[0][i]);
    return 0;
}