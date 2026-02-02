#include <bits/stdc++.h>
using namespace std;
const int N=32005;
int n,m,cnt,num;
int v[65],p[65],q[65],f[N],W[245],V[245];
vector<int> g[65],a[65];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=m;++i) 
    {
        scanf ("%d%d%d",&v[i],&p[i],&q[i]);
        if (q[i]) g[q[i]].push_back(i);
    }
    for (int i=1;i<=m;++i)
    {
        if (q[i]>0) continue;
        ++num;
        W[++cnt]=p[i]*v[i];
        V[cnt]=v[i];
        a[num].push_back(cnt);
        for (int j:g[i]) 
        {
            W[++cnt]=p[j]*v[j]+p[i]*v[i];
            V[cnt]=v[j]+v[i];
            a[num].push_back(cnt);
        }
        W[++cnt]=p[i]*v[i];
        V[cnt]=v[i];
        a[num].push_back(cnt);
        for (int j:g[i])
        {
            W[cnt]+=p[j]*v[j];
            V[cnt]+=v[j];
        }
    }
    for (int i=1;i<=num;++i)
    {
        for (int j=n;j>=0;--j)
        {
            for (int k:a[i])
            {
                if (j>=V[k]) f[j]=max(f[j],f[j-V[k]]+W[k]);
            }
        }
    }
    printf ("%d\n",f[n]);
    return 0;
}