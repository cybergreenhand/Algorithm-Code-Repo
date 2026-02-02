#include <bits/stdc++.h>
using namespace std;
int n;
char mid[10],last[10],w[300];
int p[30];
bool vis[300];
int build(int node,int now,int l,int r)
{
    w[node]=last[now];
    vis[node]=true;
    --now;
    if (l>=r||now<=0) return now;
    if (p[last[now]-'A']>p[w[node]-'A']&&r>=p[last[now]-'A']) now=build((node<<1)+1,now,p[w[node]-'A']+1,r);
    if (p[last[now-1]-'A']<p[w[node]-'A']&&l<=p[last[now]-'A']) now=build(node<<1,now,l,p[w[node]-'A']-1);
    return now;
}
void print(int node)
{
    if (!vis[node]) return;
    printf ("%c",w[node]);
    print(node<<1);
    print((node<<1)+1);
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%s%s",mid+1,last+1);
    n=strlen(last+1);
    for (int i=1;i<=n;++i) p[mid[i]-'A']=i;
    build(1,n,1,n);
    print(1);
    return 0;
}