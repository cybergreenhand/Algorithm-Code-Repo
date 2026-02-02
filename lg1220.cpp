#include <bits/stdc++.h>
using namespace std;
const int N=55;
int n,s;
int x[N],w[N],sumw[N],f[N][N][2];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&s);
    for (int i=1;i<=n;++i) scanf ("%d%d",&x[i],&w[i]);
    for (int i=1;i<=n;++i) sumw[i]=sumw[i-1]+w[i];
    memset(f,0x3f,sizeof (f));
    f[s][s][0]=f[s][s][1]=0;
    for (int len=2;len<=n;++len)
    {
        for (int l=1,r=l+len-1;r<=n;++l,++r)
        {
            int p=sumw[n]-sumw[r]+sumw[l];
            f[l][r][0]=min(f[l+1][r][0]+p*(x[l+1]-x[l]),f[l+1][r][1]+p*(x[r]-x[l]));
            p=sumw[n]-sumw[r-1]+sumw[l-1];
            f[l][r][1]=min(f[l][r-1][0]+p*(x[r]-x[l]),f[l][r-1][1]+p*(x[r]-x[r-1]));
        }
    }
    printf ("%d\n",min(f[1][n][0],f[1][n][1]));
    return 0;
}