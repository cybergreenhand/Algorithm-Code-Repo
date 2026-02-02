#include <bits/stdc++.h>
using namespace std;
const int N=5010;
int n,m,ans;
struct Milk{
    int p,a;
    bool operator< (const Milk &t) const{
        return p<t.p;
    }
}mk[N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=m;++i) scanf ("%d%d",&mk[i].p,&mk[i].a);
    sort(mk+1,mk+m+1);
    for (int i=1;i<=m&&n;++i) 
    {
        if (n>=mk[i].a)
        {
            n-=mk[i].a;
            ans+=mk[i].a*mk[i].p;
        }
        else 
        {
            ans+=n*mk[i].p;
            n=0;
        }
    }
    printf ("%d\n",ans);
    return 0;
}