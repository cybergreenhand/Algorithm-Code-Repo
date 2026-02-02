#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,s,idx;
int fa[N][20];
int dep[N],lg[N],h[N],to[N<<1],nxt[N<<1];
inline void add(int u,int v)
{
	to[++idx]=v;
	nxt[idx]=h[u];
	h[u]=idx;
}
inline void dfs(int now,int fath)
{
	dep[now]=dep[fath]+1;
	fa[now][0]=fath;
	for (int i=1;i<=lg[dep[now]];i++) fa[now][i]=fa[fa[now][i-1]][i-1];
	for (int i=h[now];i;i=nxt[i])
	{
		if (to[i]==fath) continue; 
        dfs(to[i],now);
	}
	return;
}
inline int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	while (dep[x]>dep[y]) x=fa[x][lg[dep[x]-dep[y]]-1];
	if (x==y) return x;
	for (int i=lg[dep[x]]-1;i>=0;i--)
	{
		if (fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
	scanf ("%d%d%d",&n,&m,&s);
	for (int i=1;i<n;++i)
	{
		int x,y;
		scanf ("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for (int i=1;i<=n;++i) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	dfs(s,0);
	while (m--)
	{
		int x,y;
		scanf ("%d%d",&x,&y);
		printf ("%d\n",lca(x,y));
	}
	return 0;
}