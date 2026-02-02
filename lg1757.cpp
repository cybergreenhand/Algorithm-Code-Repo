#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5,M=105;
int n,m,cnt;
int v[N],w[N],c[N],f[N];
vector<int> g[M];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&m,&n);
    for (int i=1;i<=n;++i)
    {
        scanf ("%d%d%d",&v[i],&w[i],&c[i]);
        if (!g[c[i]].size()) ++cnt;
        g[c[i]].push_back(i);
    }
    for (int i=1;i<=cnt;++i)
    {
        for (int j=m;j>=0;--j)
        {
            for (int k:g[i])
            {
                if (j>=v[k]) f[j]=max(f[j],f[j-v[k]]+w[k]);
            }
        }
    }
    printf ("%d\n",f[m]);
    return 0;
}