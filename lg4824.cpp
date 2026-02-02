#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,tt;
int nxt[N],st[N],mat[N];
char s[N],t[N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>s+1>>t+1;
    n=strlen(s+1);
    m=strlen(t+1);
    for (int i=2,j=0;i<=m;++i)
    {
        while (j&&t[i]!=t[j+1]) j=nxt[j];
        if (t[i]==t[j+1]) ++j;
        nxt[i]=j;
    }
    for (int i=1,j=0;i<=n;++i)
    {
        while (j&&s[i]!=t[j+1]) j=nxt[j];
        if (s[i]==t[j+1]) ++j;
        mat[i]=j;
        st[++tt]=i;
        if (j==m)
        {
            tt-=m;
            j=mat[st[tt]];
        }
    }
    for (int i=1;i<=tt;++i) cout<<s[st[i]];
    return 0;
}