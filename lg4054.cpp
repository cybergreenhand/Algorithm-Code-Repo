#include <bits/stdc++.h>
using namespace std;
const int N=305,M=105;
int n,m,Q;
int a[N][N];
inline int lowbit(int x)
{
    return x&-x;
}
struct Tree{
    int t[N][N];
    inline void add(int x,int y,int k)
    {
        for (int i=x;i<=n;i+=lowbit(i))
        {
            for (int j=y;j<=m;j+=lowbit(j))
            {
                t[i][j]+=k;
                // cout<<i<<" "<<j<<" "<<t[i][j]<<endl;
            }
        }
    }
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
}tr[M];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            scanf ("%d",&a[i][j]);
            tr[a[i][j]].add(i,j,1);
        }
    }
    scanf ("%d",&Q);
    while (Q--)
    {
        int op;
        scanf ("%d",&op);
        if (op==1)
        {
            int x,y,c;
            scanf ("%d%d%d",&x,&y,&c);
            tr[a[x][y]].add(x,y,-1);
            a[x][y]=c;
            tr[c].add(x,y,1);
        }
        else
        {
            int x1,x2,y1,y2,c;
            scanf ("%d%d%d%d%d",&x1,&x2,&y1,&y2,&c);
            printf ("%d\n",tr[c].query(x2,y2)-tr[c].query(x1-1,y2)-tr[c].query(x2,y1-1)+tr[c].query(x1-1,y1-1));
        }
    }
    return 0;   
}