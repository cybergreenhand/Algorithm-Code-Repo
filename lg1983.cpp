#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
const int N=1e3+5,M=1e6+5;
int n,m,cnt;
int id[N],in[N],h[M],to[M],nxt[M],ans[N];
bool vis[N];
bool a[N][N];
queue<int> q;
inline void add(int x,int y)
{
    // cout<<cnt<<endl;
    to[++cnt]=y;
    nxt[cnt]=h[x];
    h[x]=cnt;
    ++in[y];
}
inline void bfs()
{
    for (int i=1;i<=n;++i) 
    {
        if (!in[i]) 
        {
            ans[i]=1;
            q.push(i);
        }
    }
    while (q.size())
    {
        int t=q.front();
        q.pop();
        for (int i=h[t];i>0;i=nxt[i])
        {
            int j=to[i];
            --in[j];
            ans[j]=max(ans[j],ans[t]+1);
            if (!in[j]) q.push(j);
        }
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=m;++i)
    {
        memset(vis,false,sizeof (vis));
        int s;
        scanf ("%d",&s);
        for (int j=1;j<=s;++j) 
        {
            scanf ("%d",&id[j]);
            vis[id[j]]=true;
        }
        for (int j=id[1]+1;j<id[s];++j)
        {
            if (!vis[j])
            {
                for (int k=1;k<=s;++k)
                {
                    if (!a[j][id[k]]) 
                    {
                        a[j][id[k]]=true;
                        add(j,id[k]);
                    }
                }
            }
        }
    }
    bfs();
    int res=0;
    for (int i=1;i<=n;++i) res=max(res,ans[i]);
    printf ("%d\n",res);
    return 0;
}