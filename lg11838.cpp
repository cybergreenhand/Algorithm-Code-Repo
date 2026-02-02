#include <bits/stdc++.h>
using namespace std; 
int T,n,k;
int a[105];
inline bool sol1(int l,int r) 
{
	for (int i=l+1;i<=r;++i) if (a[i]!=a[i-1]) return false;
	return true;
}
inline bool sol2 (int l,int r) 
{
	vector<pair<int,int>> b;
 	for (int i=l;i<=r;++i)
    {
        if (b.size()&&a[i]==a[i-1]) b.back().second++;
 		else b.push_back({a[i],1});
    }
    if (b.size()<=2||b.size()%2==0)
    {
        for (int i=0;i+2<(int)b.size();++i) if (b[i]!=b[i+2]) return false;
        return true;
	}
    return 0;
}
inline bool sol3(int l,int r) 
{
	for (int len=1;l+len-1<=r;++len) 
    {
        if ((r-l+1)%len==0) 
        {
			bool f=1;
			for (int i=l;i+len<=r;++i) f&=(a[i]==a[i+len]);
            if (!f) continue;
            for (int i=l;i<=l+len;++i) if ((sol1(l,i)&&sol2(i+1,l+len-1))||(sol2(l,i)&&sol1(i+1,l+len-1))) return true;
		}
    }
	return false;
}
int main() 
{
	cin>>T;
	while (T--) 
    {
		cin>>n>>k;
		for (int i=1;i<=n;++i) cin>>a[i];
		if (k==1) puts(sol1(1,n)?"YES":"NO");
		if (k==2) puts(sol2(1,n)?"YES":"NO");
		if (k==3) puts(sol3(1,n)?"YES":"NO");
	}
	return 0;
}