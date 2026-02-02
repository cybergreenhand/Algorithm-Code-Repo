#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
char fir[30],last[30];
int p[30],fa[30];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%s%s",fir+1,last+1);
    n=strlen(fir+1);
    for (int i=1;i<=n;++i) p[last[i]-'a']=i;
    ll ans=1;
    for (int i=1;i<n;++i)
    {
        if (!fa[fir[i+1]-'a']) 
        {
            fa[fir[i+1]-'a']=fir[i]-'a';
            if (p[fir[i]-'a']-1>0) fa[last[p[fir[i]-'a']-1]-'a']=fir[i]-'a';
            if (fir[i+1]==last[p[fir[i]-'a']-1]) ans<<=1;
        }
    }
    printf ("%lld\n",ans);
    return 0;
}