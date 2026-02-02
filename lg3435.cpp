#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
int n;
ll ans;
char str[N];
int nxt[N];
int find(int x)
{
    if (nxt[x]==0) return x;
    return nxt[x]=find(nxt[x]);
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>str+1;
    for (int i=2,j=0;i<=n;++i)
    {
        while (j&&str[i]!=str[j+1]) j=nxt[j];
        if (str[i]==str[j+1]) ++j;
        nxt[i]=j;
    }
    for (int i=2;i<=n;++i)
    {
        int j=find(i);
        ans+=i-j;
    }
    cout<<ans<<endl;
    return 0;
}