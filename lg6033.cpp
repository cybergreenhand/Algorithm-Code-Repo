#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int n;
ll ans;
int num[N];
queue<ll> q1,q2;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9')
    {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int main() 
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
	n=read();
	for (int i=1;i<=n;++i) 
    {
		int a=read();
		++num[a];
	}
	for (int i=1;i<=1e5;++i) 
    {
		while (num[i]) 
        {
			--num[i];
			q1.push(i);
		}
	}
	for (int i=1;i<n;++i) 
    {
		ll x,y;
		if ((q1.size()&&q2.size()&&q1.front()<q2.front())||q2.empty()) 
        {
			x=q1.front();
			q1.pop();
		}
		else 
        {
			x=q2.front();
			q2.pop();
		}
		if ((q1.size()&&q2.size()&&q1.front()<q2.front())||q2.empty()) 
        {
			y=q1.front();
			q1.pop();
		}
		else 
        {
			y=q2.front();
			q2.pop();
		}
		ans+=(x+y);
		q2.push(x+y);
	} 
	printf ("%lld\n",ans);
	return 0;
}