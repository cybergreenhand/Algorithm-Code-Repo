#include <bits/stdc++.h>
using namespace std;
int n,ans,cnt;
int a[5][15];
bool f[15],g[30],h[15],d[15];
bool dfs(int lin)
{
    if (lin>n) 
    {
        ++ans;
        return true;
    }
    bool flag=false;
    for (int col=1;col<=n;++col)
    {
        if ((!f[col])&&(!g[col+lin])&&((col>=lin&&!h[col-lin])||(col<lin&&!d[lin-col])))
        {
            f[col]=true;
            g[col+lin]=true;
            if (col>=lin) h[col-lin]=true;
            else d[lin-col]=true;
            if (ans<3) a[ans+1][lin]=col;
            if (dfs(lin+1)) 
            {
                flag=true;
                if (ans<=3) a[ans][lin]=col;
            }
            f[col]=false;
            g[col+lin]=false;
            if (col>=lin) h[col-lin]=false;
            else d[lin-col]=false;
        }
    }
    return flag;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    dfs(1);
    for (int i=1;i<=3;++i)
    {
        for (int j=1;j<=n;++j)
        {
            if (a[i][j]==0) a[i][j]=a[i-1][j];
            printf ("%d ",a[i][j]);
        }
        printf ("\n");
    }
    printf ("%d\n",ans);
    return 0;
}