#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct node{
	int x,val;
}b[N];
int t,n,m,k;
int a[N];
bool cmp(node x,node y)
{
	return x.val>y.val;
}
bool cmp2(node x,node y)
{
	return x.val<y.val;
}
void solve()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for (int i=1;i<=m;i++) scanf("%lld",&a[i]);
	for (int i=1,y,z;i<=n;i++)
	{
		scanf("%lld%lld%lld",&b[i].x,&y,&z);
		b[i].val=z-y;
		k-=y;
	}
	sort(b+1,b+n+1,cmp);
	multiset<int> ms;
	for (int i=1;i<=m;i++) ms.insert(a[i]);
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		auto it=ms.lower_bound(b[i].x);
		if (it==ms.end()) continue;
		b[i].val=2e9;
		ans++;
		ms.erase(it);
	}
	sort(b+1,b+n+1,cmp2);
	for (int i=1;i<=n;i++)
	{
		if (b[i].val<2e9&&k>=b[i].val)
		{
			ans++;
			k-=b[i].val;
		}
		else break;
	}
	printf("%lld\n",ans);
}
signed main()
{
	scanf("%lld",&t);
	while (t--) solve();
	return 0;
}