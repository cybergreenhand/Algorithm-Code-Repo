#include <bits/stdc++.h>
using namespace std;
const int N=505;
int n,m;
int h[N][N];
int gx[]={1,-1,0,0},gy[]={0,0,1,-1};
bool vis[N][N];
struct Water{
    int l,r;
    bool operator< (const Water &t) const
    {
        if (l==t.l) return r<t.r;
        return l<t.l;
    }
}a[N][N],b[N];
void dfs(int x,int y)
{
    if (vis[x][y]) return;
    vis[x][y]=true;
    if (x==n) a[x][y].l=a[x][y].r=y;
    for (int i=0;i<4;++i)
    {
        int xx=x+gx[i],yy=y+gy[i];
        if (xx<1||xx>n||yy<1||yy>m||h[xx][yy]>=h[x][y]) continue;
        dfs(xx,yy);
        a[x][y].l=min(a[x][y].l,a[xx][yy].l);
        a[x][y].r=max(a[x][y].r,a[xx][yy].r);
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            scanf ("%d",&h[i][j]);
            a[i][j].l=0x3f3f3f3f;
            a[i][j].r=-0x3f3f3f3f;
        }
    }
    for (int i=1;i<=m;++i) if (!vis[1][i]) dfs(1,i);
    // for (int i=1;i<=m;++i) cout<<a[1][i].l<<" "<<a[1][i].r<<endl;
    int nw=0;
    for (int i=1;i<=m;++i) if (!vis[n][i]) ++nw;
    if (nw) printf ("0\n%d\n",nw);
    else
    {
        for (int i=1;i<=m;++i) b[i]=a[1][i];
        sort(b+1,b+m+1);
        int now=1,far,ans=1;
        while (now<=m&&b[now].l==1&&far<m) 
        {
            far=b[now].r;
            ++now;
        }
        while (far<m)
        {
            ++ans;
            int l=now,r=m;
            while (l<r)
            {
                int mid=l+r+1>>1;
                if (b[mid].l<=far+1) l=mid;
                else r=mid-1;
            }
            far=b[l].r;
        }
        printf ("1\n%d\n",ans);
    }
    return 0;
}