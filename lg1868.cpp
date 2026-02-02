#include <bits/stdc++.h>
using namespace std;
const int N=1.5e5+5,M=3e6+5;
int n,maxr,ans;
struct Grass{
    int l,r;
}g[N];
int f[M];
vector<int> p[M];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;++i) 
    {
        scanf ("%d%d",&g[i].l,&g[i].r);
        p[g[i].r].push_back(i);
        maxr=max(maxr,g[i].r);
    }
    for (int i=1;i<=maxr;++i)
    {
        f[i]=f[i-1];
        if (!p[i].empty())
        {
            for (int j:p[i])
            {
                f[i]=max(f[i],f[g[j].l-1]+g[j].r-g[j].l+1);
            }
        }
    }
    printf ("%d\n",f[maxr]);
    return 0;
}