#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],tr[N];
inline int lowbit(int x)
{
    return x&-x;
}
inline void add(int x,int k)
{
    while (x<=n)
    {
        tr[x]+=k;
        x+=lowbit(x);
    }
}
inline int query(int x)
{
    int sum=0;
    while (x)
    {
        sum+=tr[x];
        x-=lowbit(x);
    }   
    return sum;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;++i) scanf ("%d",&a[i]);
    for (int i=1;i<=n;++i) add(i,a[i]-a[i-1]);
    while (m--)
    {
        int op;
        scanf ("%d",&op);
        if (op==1)
        {
            int x,y,k;
            scanf ("%d%d%d",&x,&y,&k);
            add(x,k);
            add(y+1,-k);
        }
        else
        {
            int x;
            scanf ("%d",&x);
            printf ("%d\n",query(x));
        }
    }
    return 0;
}