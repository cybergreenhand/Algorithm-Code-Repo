#include <bits/stdc++.h>
using namespace std;
const int N=355;
int n,m,card;
int s[N],cnt[5],f[41][41][41][41],last[N];
int dfs(int now,int a,int b,int c,int d)
{
    if (f[a][b][c][d]>0) return f[a][b][c][d];
    // if (a>0&&now>1) f[now]=max(f[now],dfs(now-1,a-1,b,c,d));
    // if (b>0&&now>2) f[now]=max(f[now],dfs(now-2,a,b-1,c,d));
    // if (c>0&&now>3) f[now]=max(f[now],dfs(now-3,a,b,c-1,d));
    // if (d>0&&now>4) f[now]=max(f[now],dfs(now-4,a,b,c,d-1));
    if (a>0&&now>1)
    {
        int t=dfs(now-1,a-1,b,c,d);
        if (t>f[a][b][c][d]) 
        {
            last[now]=now-1;
            f[a][b][c][d]=t;
        }
    }
    if (b>0&&now>2)
    {
        int t=dfs(now-2,a,b-1,c,d);
        if (t>f[a][b][c][d]) 
        {
            last[now]=now-2;
            f[a][b][c][d]=t;
        }
    }
    if (c>0&&now>3)
    {
        int t=dfs(now-3,a,b,c-1,d);
        if (t>f[a][b][c][d]) 
        {
            last[now]=now-3;
            f[a][b][c][d]=t;
        }
    }
    if (d>0&&now>4)
    {
        int t=dfs(now-4,a,b,c,d-1);
        if (t>f[a][b][c][d]) 
        {
            last[now]=now-4;
            f[a][b][c][d]=t;
        }
    }
    f[a][b][c][d]+=s[now];
    return f[a][b][c][d];
}

int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;++i) scanf ("%d",&s[i]);
    for (int i=1;i<=m;++i) 
    {
        scanf ("%d",&card);
        ++cnt[card];
    }
    memset(f,-0x3f,sizeof(f));
    f[0][0][0][0]=s[1];
    printf ("%d\n",dfs(n,cnt[1],cnt[2],cnt[3],cnt[4]));
    // for (int i=n;i>=1;i=last[i]) printf ("%d -> ",i);
    return 0;
}