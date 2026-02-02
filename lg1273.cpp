#include <bits/stdc++.h>
using namespace std;
const int N=3e3+5;
int n,m,cnt;
int c[N],s[N],f[N][N],h[N],to[N],nxt[N],w[N];
inline void add(int a,int b,int c)
{
    to[++cnt]=b;
    nxt[cnt]=h[a];
    w[cnt]=c;
    h[a]=cnt;
}
void dfs(int x)
{
    f[x][0]=0;
    if (x>n-m) 
    {
        f[x][1]=c[x];
        s[x]=1;
        return;
    }
    for (int k=h[x];k;k=nxt[k])
    {
        int y=to[k];
        dfs(y);
        for (int i=s[x];i>=0;--i)
        {
            for (int j=s[y];j>=0;--j)
            {
                f[x][i+j]=max(f[x][i+j],f[x][i]+f[y][j]+w[k]);
            }
        }
        s[x]+=s[y];
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    memset(f,-0x3f,sizeof (f));
    for (int i=1;i<=n-m;++i)
    {
        int k;
        scanf ("%d",&k);
        for (int j=1;j<=k;++j)
        {
            int id;
            scanf ("%d",&id);
            scanf ("%d",&c[id]);
            add(i,id,-c[id]);
        }
    }
    for (int i=n-m+1;i<=n;++i) scanf ("%d",&c[i]);
    dfs(1);
    // for (int i=1;i<=n;++i)
    // {
    //     for (int j=0;j<=s[i];++j)
    //     {
    //         cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
    //     }
    // }
    for (int i=m;i>=0;--i)
    {
        if (f[1][i]>=0)
        {
            printf ("%d\n",i);
            break;
        }
    }
    return 0;
}