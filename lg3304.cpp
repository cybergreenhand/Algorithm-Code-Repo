#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=4e5+5;
struct node{
	int x;
	ll val;
	friend bool operator <(node a, node b)
    {
		return a.val<b.val;
	}
};
int n,ans,tot;
int to[N],pre[N],last[N],fa[N];
ll v[N],d[N],f[N];
priority_queue<node> h;
void add(int a, int b, int c)
{
	to[++tot]=b;
	pre[tot]=last[a];
	last[a]=tot;
	v[tot]=c;
}
void dfs(int x,int father,ll deep)
{
	d[x]=deep;
	fa[x]=father;
	f[x]=0;
	for (int i=last[x];i;i=pre[i])
    {
        if (to[i]!=father) 
        {
			dfs(to[i],x,d[x]+v[i]);
			f[x]=max(f[x],f[to[i]]+v[i]);
		}
    }
}
void work(int x,int father,int deep)
{
	dfs(x,father,deep);
	while (true)
    {
		int y=0,cnt=0;
		for (int i=last[x];i;i=pre[i]) if (to[i]!=father&&f[x]==f[to[i]]+v[i]) y=to[i],cnt++;
		if (cnt==0||cnt>=2) break;
		father=x;
		x=y;
		ans++;
	}
}
int main()
{
	
	scanf ("%d",&n);
	for (int i=1;i<n;i++)
    {
		int a,b,c;
		scanf ("%d%d%d",&a,&b,&c); 
		add(a,b,c);
		add(b,a,c);
	}
	dfs(1,0,0);
	int now=0;
	for (int i=1;i<=n;i++) if (d[i]>d[now]) now=i;
	dfs(now,0,0);
	now=0;
	for (int i=1;i<=n;i++) if (d[i]>d[now]) now=i;
	ll L=d[now];
	while (d[fa[now]]*2>=L) now=fa[now];
	if (d[now]*2==L)
    {
		dfs(now,0,0);
		for (int i=last[now];i;i=pre[i]) h.push((node){to[i],v[i]+f[to[i]]});
		node a=h.top();
		h.pop();
		node b=h.top();
		h.pop();
		if (h.empty())
        {
			ans+=2;
			work(a.x,now,0);
			work(b.x,now,0);
		} 
        else
        {
			node c=h.top();
			if (b.val>c.val)
            {
				ans+=2;
				work(a.x,now,0);
				work(b.x,now,0);
			} 
            else
            {
				if (a.val>b.val)
                {
					ans++;
					work(a.x,now,0);
				}
			}
		}
	}
	else
    {
		ans++;
		work(now,fa[now],0);
		work(fa[now],now,0); 
	}
	printf ("%lld\n",L);
	printf ("%d\n",ans);
	return 0;
} 