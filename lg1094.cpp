#include <bits/stdc++.h>
using namespace std;
const int N=3e4+10;
int W,n,ans;
int p[N];
bool a[N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&W,&n);
    for (int i=1;i<=n;++i) scanf ("%d",&p[i]);
    sort(p+1,p+n+1);
    for (int i=1,j=n;i<j;)
    {
        while (p[i]+p[j]>W) --j;
        if (i<j) 
        {
            ++ans;
            a[i]=true;
            a[j]=true;
            ++i;
            --j;
        }
    }
    for (int i=1;i<=n;++i) if (!a[i]) ++ans;
    printf ("%d\n",ans);
    return 0;
}