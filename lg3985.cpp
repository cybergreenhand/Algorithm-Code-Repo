#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,W,ans,mn=1e9;
int v[N],p[N],cnt[5];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&W);
    for (int i=1;i<=n;++i) 
    {
        scanf ("%d%d",&v[i],&p[i]);
        mn=min(mn,v[i]);
    }
    for (int i=1;i<=n;++i) ++cnt[v[i]-mn];
    int f[2][cnt[0]+5][cnt[1]+5][cnt[2]+5][cnt[3]+5];
    memset(f,0,sizeof (f));
    memset(cnt,0,sizeof (cnt));
    for (int i=1;i<=n;++i)
    {
        ++cnt[v[i]-mn];
        for (int a=0;a<=cnt[0];++a)
        {
            for (int b=0;b<=cnt[1];++b)
            {
                for (int c=0;c<=cnt[2];++c)
                {
                    for (int d=0;d<=cnt[3];++d)
                    {
                        if (v[i]-mn==0)
                        {
                            if (1ll*mn*(a+b+c+d)+b+c*2+d*3<=W) 
                            {
                                f[i&1][a][b][c][d]=f[(i-1)&1][a][b][c][d];
                                if (a>0) f[i&1][a][b][c][d]=max(f[i&1][a][b][c][d],f[(i-1)&1][a-1][b][c][d]+p[i]);
                            }
                        }
                        if (v[i]-mn==1)
                        {
                            if (1ll*mn*(a+b+c+d)+b+c*2+d*3<=W) 
                            {
                                f[i&1][a][b][c][d]=f[(i-1)&1][a][b][c][d];
                                if (b>0) f[i&1][a][b][c][d]=max(f[i&1][a][b][c][d],f[(i-1)&1][a][b-1][c][d]+p[i]);
                            }
                        }
                        if (v[i]-mn==2)
                        {
                            if (1ll*mn*(a+b+c+d)+b+c*2+d*3<=W) 
                            {
                                f[i&1][a][b][c][d]=f[(i-1)&1][a][b][c][d];
                                if (c>0) f[i&1][a][b][c][d]=max(f[i&1][a][b][c][d],f[(i-1)&1][a][b][c-1][d]+p[i]);
                            }
                        }
                        if (v[i]-mn==3)
                        {
                            if (1ll*mn*(a+b+c+d)+b+c*2+d*3<=W) 
                            {
                                f[i&1][a][b][c][d]=f[(i-1)&1][a][b][c][d];
                                if (d>0) f[i&1][a][b][c][d]=max(f[i&1][a][b][c][d],f[(i-1)&1][a][b][c][d-1]+p[i]);
                            }
                        }
                    }
                }
            }
        }
    }
    for (int a=0;a<=cnt[0];++a)
    {
        for (int b=0;b<=cnt[1];++b)
        {
            for (int c=0;c<=cnt[2];++c)
            {
                for (int d=0;d<=cnt[3];++d)
                {
                    if (1ll*mn*(a+b+c+d)+b+c*2+d*3<=W) ans=max(ans,f[n&1][a][b][c][d]);
                }
            }
        }
    }
    printf ("%d\n",ans);
    return 0;
}