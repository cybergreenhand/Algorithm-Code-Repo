#include <bits/stdc++.h>
using namespace std;
const int N=505;
int n,cnt;
int c[N];
priority_queue<int> b[N];
struct General{
    int a,b,w;
    bool operator< (const General &t) const{
        return w<t.w;
    }
}g[(N*N)>>1];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<n;++i)
    {
        for (int j=i+1;j<=n;++j)
        {
            int t;
            scanf ("%d",&t);
            b[i].push(t);
            b[j].push(t);
            g[++cnt].w=t;
            g[cnt].a=i;
            g[cnt].b=j;
        }
    }
    sort(g+1,g+cnt+1);
    printf ("1\n");
    for (int i=cnt;i;--i)
    {
        int x=g[i].a,y=g[i].b;
        if ((c[x]==0)&&(c[y]==0))
        {
            b[x].pop();
            b[y].pop();
            int X=b[x].top(),Y=b[y].top();
            if (X>Y) 
            {
                c[x]=1;
                c[y]=2;
            }
            else
            {
                c[x]=2;
                c[y]=1;
            }
        }
        else if ((c[x]==1)&&(c[y]==1))
        {
            printf ("%d\n",g[i].w);
            return 0;
        }
        else if (((c[x]==1)&&(c[y]==0))||((c[x]==0)&&(c[y]==1)))
        {
            printf ("%d\n",g[i].w);
            return 0;
        }
    }
    return 0;
}