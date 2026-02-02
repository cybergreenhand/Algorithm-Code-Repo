#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
const double eps=1e-8;
int n,m,cnt;
ll sum;
int fa[N],s[N],b[N],g[N][20];
bool vis[N];
vector<int> p[N];
struct Score{
    ll s;
    int num;
    bool operator< (const Score &t) const
    {
        double s1=s*1.0/num,s2=t.s*1.0/t.num;
        if (s1<s2+eps&&s1+eps>s2) return num<t.num;
        return s1<s2;
    }
}f[N];
int find(int x)
{
    if (x!=fa[x]) return fa[x]=find(fa[x]);
    return fa[x];
}
inline void merge(int x,int y)
{
    int fx=find(x),fy=find(y);
    if (fx!=fy)
    {
        --cnt;
        sum+=(s[fx]*s[fy]<<1);
        fa[fx]=fy;
        s[fy]+=s[fx];
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;++i) 
    {
        fa[i]=i;
        s[i]=1;
        scanf ("%d",&b[i]);
        p[b[i]].push_back(i);
    }
    sort(b+1,b+n+1);
    int now=b[1];
    for (int i=1;i<=n;now=b[i])
    {
        for (int j:p[now])
        {
            ++sum;
            ++cnt;
            vis[j]=true;
            if (vis[j-1]) merge(j-1,j);
            if (vis[j+1]) merge(j,j+1);
        }
        if ((f[cnt].num&&sum*1.0/now>f[cnt].s*1.0/f[cnt].num-eps)||!f[cnt].num) 
        {
            // cout<<"PRE IS "<<f[cnt].s<<" "<<f[cnt].num<<endl;
            // cout<<"NEW IS "<<sum<<" "<<now<<endl;
            f[cnt].s=sum;
            f[cnt].num=now;
        }
        while (b[i]==now) ++i;
    }
    // for (int i=1;i<=3;++i) cout<<f[i].s<<" "<<f[i].num<<endl;
    for (int i=1;i<=(n+1)>>1;++i) if (f[i].num) g[i][0]=i;
    for (int j=1;(1<<j)<=(n+1)>>1;++j)
    {
        for (int i=1;i+(1<<j)-1<=(n+1)>>1;++i)
        {
            if (g[i][j-1]) 
            {
                g[i][j]=g[i][j-1];
                if (g[i+(1<<j-1)][j-1]) 
                {
                    if (f[g[i][j-1]]<f[g[i+(1<<j-1)][j-1]])
                    {
                        g[i][j]=g[i+(1<<j-1)][j-1];
                    }
                }
            }
            else if (g[i+(1<<j-1)][j-1]) g[i][j]=g[i+(1<<j-1)][j-1];
        }
    }
    ll last=0;
    while (m--)
    {
        int a,b,x,y;
        scanf ("%d%d%d%d",&a,&b,&x,&y);
        int L=(a*last+x-1)%n+1,R=(b*last+y-1)%n+1;
        if (L>R) swap(L,R);
        Score ans={0,0};
        if (L<=(n+1)>>1)
        {
            int k=log2(min(R,(n+1)>>1)-L+1);
            if (g[L][k]) 
            {
                ans=f[g[L][k]];
                if (g[min(R,(n+1)>>1)-(1<<k)+1][k])
                {
                    if (ans<f[g[min(R,(n+1)>>1)-(1<<k)+1][k]]) ans=f[g[min(R,(n+1)>>1)-(1<<k)+1][k]];
                }
            }
            else if (g[min(R,(n+1)>>1)-(1<<k)+1][k]) ans=f[g[min(R,(n+1)>>1)-(1<<k)+1][k]];
        }
        if (!ans.num)
        {
            ans.s=-1;
            ans.num=-1;
        }
        printf ("%lld %d\n%d %d %lld\n",ans.s,ans.num,L,R,last);
        last=ans.s*ans.num%n;
    }
    return 0;
}