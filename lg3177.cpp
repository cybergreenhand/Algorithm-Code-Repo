#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e3+5;
int n,m,cnt;
int s[N],h[N],to[N<<1],nxt[N<<1];
ll f[N][N],w[N<<1];
inline void add(int a,int b,ll c)
{
    to[++cnt]=b;
    nxt[cnt]=h[a];
    w[cnt]=c;
    h[a]=cnt;
}
void dfs(int x,int fa)
{
	s[x]=1;
	for (int i=h[x];i;i=nxt[i])
	{
        int y=to[i];
		if (y==fa) continue;
		dfs(y,x);
		s[x]+=s[y];
		for (int j=max(m,s[x]);j>=0;j--)
        {
            for (int k=max(j-s[x]+s[y],0);k<=min(j,s[y]);k++)
            {
                f[x][j]=max(f[x][j],f[x][j-k]+f[y][k]+(k*(m-k)+(s[y]-k)*(n-m-s[y]+k))*w[i]);
            }
	    }
    }
			
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
	scanf ("%d%d",&n,&m);
	for (int i=1;i<n;i++)
	{
		int x,y;
        ll z;
		scanf("%d%d%lld",&x,&y,&z);
		add(x,y,z);
        add(y,x,z);
	}
	dfs(1,0);
	printf ("%lld\n",f[1][m]);
	return 0;
}