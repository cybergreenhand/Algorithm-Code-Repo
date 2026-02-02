#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int pre[N],nex[N];
bool d[N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    nex[0]=1;
    for (int i=2;i<=n;++i)
    {
        int k,p;
        scanf ("%d%d",&k,&p);
        if (p==0)
        {
            nex[i]=k;
            pre[i]=pre[k];
            nex[pre[i]]=i;
            pre[k]=i;
        }
        else
        {
            pre[i]=k;
            nex[i]=nex[k];
            pre[nex[k]]=i;
            nex[k]=i;
        }
    }
    scanf ("%d",&m);
    for (int i=1;i<=m;++i)
    {
        int x;
        scanf ("%d",&x);
        if (d[x]) continue;
        d[x]=true;
        pre[nex[x]]=pre[x];
        nex[pre[x]]=nex[x];
    }
    for (int i=nex[0];i;i=nex[i]) printf ("%d ",i);
    return 0;
}