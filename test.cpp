#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
int v[N],p[N];
inline int check()
{
	cin>>n;
	for (int i=1;i<=n;++i) cin>>v[i]>>p[i];
	string ans;
	cin>>ans;
	if (ans=="NO") return 0;
	vector<int> pos;
	for (int i=1;i<=n;++i)
	{
		int x;
		cin>>x;
		pos.push_back(x);
	}
	for (int k=0;k+1<pos.size();++k) 
	{
		int i=pos[k],j=pos[k+1];
		if (v[i]!=v[j]&&p[i]!=p[j]) return 1;
	}
	for (int i=0;i+2<pos.size();++i)
	{
		int a=pos[i],b=pos[i+1],c=pos[i+2];
		if ((v[a]==v[b]&&v[b]==v[c])||(p[a]==p[b]&&p[b]==p[c])) return 2;
	}
	return 0;
}
int main()
{
	freopen("a.out","r",stdin);
	freopen("b.out","w",stdout);
	int T;
	cin>>T;
	int flag=0,type=0,falt=0;
	for (int i=1;i<=T;++i) if (type=check()) flag=i,falt=type;
	if (!flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl<<flag<<" "<<falt<<endl;
	return 0;
}