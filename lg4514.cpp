#include <bits/stdc++.h>
using namespace std;
const int N=2050;
int n,m;
char op;
inline int lowbit(int x)
{
    return x&-x;
}
struct Tree{
    int t[N][N];
    inline int query(int x,int y)
    {
        int sum=0;
        for (int i=x;i;i-=lowbit(i))
        {
            for (int j=y;j;j-=lowbit(j))
            {
                sum+=t[i][j];
            }
        }
        return sum;
    }
}tr[4];
inline void add(int x,int y,int k)
{
    for (int i=x;i<=n;i+=lowbit(i))
    {
        for (int j=y;j<=m;j+=lowbit(j))
        {
            tr[0].t[i][j]+=k;
            tr[1].t[i][j]+=k*x;
            tr[2].t[i][j]+=k*y;
            tr[3].t[i][j]+=k*x*y;
        }
    }
}
inline void add(int x1,int y1,int x2,int y2,int k)
{
    add(x1,y1,k);
    add(x1,y2+1,-k);
    add(x2+1,y1,-k);
    add(x2+1,y2+1,k);
}
inline int query(int x,int y)
{
    return (x*y+x+y+1)*tr[0].query(x,y)-(y+1)*tr[1].query(x,y)-(x+1)*tr[2].query(x,y)+tr[3].query(x,y);
}
inline int query(int x1,int y1,int x2,int y2)
{
    return query(x2,y2)-query(x1-1,y2)-query(x2,y1-1)+query(x1-1,y1-1);
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("X %d %d\n",&n,&m);
    while (scanf ("%c",&op)!=EOF)
    {
        int a,b,c,d;
        if (op=='L')
        {
            int k;
            scanf ("%d%d%d%d%d\n",&a,&b,&c,&d,&k);
            add(a,b,c,d,k);
        }
        else
        {
            scanf ("%d%d%d%d\n",&a,&b,&c,&d);
            printf ("%d\n",query(a,b,c,d));
        }
    }
    return 0;
}