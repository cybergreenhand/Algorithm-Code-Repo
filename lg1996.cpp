#include <bits/stdc++.h>
using namespace std;
int n,m;
int pre[105],nex[105];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;++i) 
    {
        if (i==1) pre[i]=n;
        else pre[i]=i-1;
        if (i==n) nex[i]=1;
        else nex[i]=i+1;
    }
    int cnt=0;
    for (int i=1;n>0;i=nex[i])
    {
        ++cnt;
        if (cnt==m) 
        {
            printf ("%d ",i);
            pre[nex[i]]=pre[i];
            nex[pre[i]]=nex[i];
            cnt=0;
            --n;
        }
    }
    return 0;
}