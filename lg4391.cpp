#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n;
char str[N];
int nxt[N];
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
    cout<<n-nxt[n]<<endl;
    return 0;
}