#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int tr[N];
inline int lowbit(int x)
{
    return x&-x;
}
inline void add(int x,int y)
{
    while (x<=n)
    {
        tr[x]+=y;
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
    for (int i=1;i<=n;++i)
    {
        int a;
        scanf ("%d",&a);
        add(i,a);
    }
    while (m--)
    {
        int op,x,y;
        scanf ("%d%d%d",&op,&x,&y);
        if (op==1) add(x,y);
        else printf ("%d\n",query(y)-query(x-1));
    }
    return 0;
}