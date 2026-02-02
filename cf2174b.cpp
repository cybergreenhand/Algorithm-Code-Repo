#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=365;
int T,n,m;
int a[N],p[M],f[M][M];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--)
    {
        cin>>n>>m;
        for (int i=1;i<=n;++i) cin>>a[i];
        memset(p,0x3f,sizeof (p));
        for (int i=1;i<=n;++i) p[a[i]]=min(p[a[i]],i);
        for (int i=m-1;i>=1;--i) p[i]=min(p[i],p[i+1]);
        memset(f,-0x3f,sizeof (f));
        f[0][0]=0;
        int ans=0;
        for (int mc=1;mc<=m;++mc)
        {
            if (p[mc]>n) continue;
            for (int uc=mc;uc<=m;++uc)
            {
                for (int lmc=0;lmc<mc;++lmc)
                {
                    f[uc][mc]=max(f[uc][mc],f[uc-mc][lmc]+(mc-lmc)*(n-p[mc]+1));
                    ans=max(ans,f[uc][mc]);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}