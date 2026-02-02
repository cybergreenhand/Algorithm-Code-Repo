#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
char s1[N],s2[N];
int nxt[N];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>s1+1>>s2+1;
    n=strlen(s1+1),m=strlen(s2+1);
    for (int i=2,j=0;i<=m;++i)
    {
        while (j&&s2[i]!=s2[j+1]) j=nxt[j];
        if (s2[i]==s2[j+1]) ++j;
        nxt[i]=j;
    }
    for (int i=1,j=0;i<=n;++i)
    {
        while (j&&s1[i]!=s2[j+1]) j=nxt[j];
        if (s1[i]==s2[j+1]) ++j;
        if (j==m)
        {
            cout<<i-m+1<<endl;
            j=nxt[j];   
        }
    }
    for (int i=1;i<=m;++i) cout<<nxt[i]<<" "; 
    return 0;
}