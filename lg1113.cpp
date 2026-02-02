#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
const int N=1e4+5,M=1e6+5;
int n,m,cnt;
int to[M],len[N],h[M],ans[N],nxt[M],in[N];
queue<int> q;
inline void add(int x,int y)
{
    to[++cnt]=y;
    nxt[cnt]=h[x];
    h[x]=cnt;
    ++in[y];
}
inline void bfs()
{
    for (int i=1;i<=n;++i) 
    {
        if (in[i]==0) 
        {
            q.push(i);
            ans[i]=len[i];
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
            ans[j]=max(ans[j],ans[t]);
            if (in[j]==0) 
            {
                q.push(j);
                ans[j]+=len[j];
            }
        }
    }
}
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;++i)
    {
        int id;
        scanf ("%d%d",&id,&len[i]);
        while (true)
        {
            scanf ("%d",&id);
            if (id==0) break;
            add(i,id);
        }
    }
    bfs();
    int res=0;
    for (int i=1;i<=n;++i) res=max(res,ans[i]);
    printf ("%d\n",res);
    return 0;
}