#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m,dp1[200005],dp2[200005],b[200005],ans=-1;
vector<pair<int,int> > v1[200005],v2[200005];
signed main()
{
	freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		ans=1e18;
		for(int i=1;i<=n;i++)
		{
			v1[i].clear();
			v2[i].clear();
			dp1[i]=0;
			dp2[i]=1e18;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>b[i];
		}
		for(int i=1;i<=m;i++)
		{
			int x,y,w;
			cin>>x>>y>>w;
			v1[x].push_back({y,w});
			v2[y].push_back({x,w});
		}
		dp1[1]=b[1];
		dp2[n]=0;
		for(int x=n;x>=1;x--)
		{
			for(int j=0;j<v2[x].size();j++)
			{
				int y=v2[x][j].first;
				dp2[y]=min(dp2[y],max(dp2[x],v2[x][j].second));
			}
		}
		for(int x=1;x<n;x++)
		{
			if(dp1[x]>=dp2[x])
			{
				ans=min(ans,dp2[x]);
				continue;
			}
			for(int j=0;j<v1[x].size();j++)
			{
				int y=v1[x][j].first;
				if(dp1[x]>=v1[x][j].second)
				{
					dp1[y]=max(dp1[y],dp1[x]+b[y]);
				}
			}
		}
		if(ans==1e18)
		{
			cout<<-1<<'\n';
			continue;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
