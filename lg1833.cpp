#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e3+10;
int sa,sb,ea,eb,n,T;
int c[N],t[N],p[N],f[M],new_t[N],new_c[N];
char str[5];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d:",&sa);
    scanf ("%2s",str);
    for (int i=0;i<2;++i) sb=sb*10+(str[i]-'0');
    scanf ("%d:",&ea);
    scanf ("%2s",str);
    for (int i=0;i<2;++i) eb=eb*10+(str[i]-'0');
    T=60-sb+60*(ea-sa-1)+eb;
    scanf ("%d",&n);
    for (int i=1;i<=n;++i) scanf ("%d%d%d",&t[i],&c[i],&p[i]);
    for (int i=1;i<=n;++i)
    {
        if (!p[i])
        {
            for (int j=t[i];j<=T;++j)
            {
                f[j]=max(f[j],f[j-t[i]]+c[i]);
            }
        }
        else
        {
            int cnt=0;
            for (int j=1;j<=p[i];j<<=1)
            {
                ++cnt;
                new_t[cnt]=t[i]*j;
                new_c[cnt]=c[i]*j;
                p[i]-=j;
            }
            if (p[i]) 
            {
                ++cnt;
                new_t[cnt]=t[i]*p[i];
                new_c[cnt]=c[i]*p[i];
            }
            for (int j=1;j<=cnt;++j)
            {
                for (int k=T;k>=new_t[j];--k)
                {
                    f[k]=max(f[k],f[k-new_t[j]]+new_c[j]);
                }
            }
        }
    }
    printf ("%d\n",f[T]);
    return 0;
}