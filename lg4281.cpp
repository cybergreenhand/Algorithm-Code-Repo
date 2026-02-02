#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll ans=0;
int fa[N][25],lg[N],deep[N],t;
struct node
{
	int from;
	int to;
	int next;
}ed[N<<1];
int v[N<<1],tot=0;
void add(int x,int y)
{
	ed[++tot].from=x;
	ed[tot].to=y;
	ed[tot].next=v[x];
	v[x]=tot;
}
int lca(int x,int y)
{
	if(deep[x]<deep[y])			//假设x深度大于y
		swap(x,y);
	while(deep[x]>deep[y])		//x,y调整到同一深度	
	{
		x=fa[x][lg[deep[x]-deep[y]]-1];
	}
	if(x==y)
		return x;
	for(int k=lg[deep[x]];k>=0;k--)		//x,y一起向上跳
	{
	    if(fa[x][k]!=fa[y][k])
	    {
	    	x=fa[x][k];
			y=fa[y][k];
	    }
	}
    return fa[x][0];
	
}
void dfs(int x,int fath)				
{
	deep[x]=deep[fath]+1;					//处理深度
	fa[x][0]=fath;
	for(int i=1;(1<<i)<=deep[x];i++)
	{
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	for(int i=v[x];i;i=ed[i].next)
		if(ed[i].to!=fath)
			dfs(ed[i].to,x);
}
int n,m;
int a,b,c;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)								//常数优化 
		lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	for(int i=1;i<=m;i++)
	{
		ans=0;
		scanf("%d%d%d",&a,&b,&c);
		int t1=lca(a,b);					//三者分别求LCA
		int t2=lca(a,c);
		int t3=lca(b,c);
		if(t1==t2)
			t=t3;
		else if(t1==t3)
			t=t2;
		else if(t2==t3)
			t=t1;
        //差分
		ans=deep[a]+deep[b]+deep[c]-deep[t1]-deep[t2]-deep[t3];		
		printf("%d %lld\n",t,ans);
	}
	return 0;
} 
