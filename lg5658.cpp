#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n;
int fa[N];
ll ans;
char s[N];
ll f[N][2];
vector<int> son[N],l;
void dfs(int u,int cnt)
{
    int t;
    if (s[u]=='(') 
    {
        ++cnt;
        l.push_back(u);
    }
    else if (s[u]==')')
    {
        --cnt;
        if (cnt>=0) 
        {
            t=l.back();
            f[u][1]=1+f[fa[t]][1];
            l.pop_back();
        }
        else cnt=0;
    }
    for (int v:son[u])
    {
        f[v][0]+=f[u][0]+f[u][1];
        dfs(v,cnt);
    }
    if (s[u]=='(') l.pop_back();
    else l.push_back(t);
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%s",&n,s+1);
    for (int i=2;i<=n;++i) 
    {
        scanf ("%d",&fa[i]);
        son[fa[i]].push_back(i);
    }
    dfs(1,0);
    for (int i=1;i<=n;++i) ans^=(i*(f[i][0]+f[i][1]));
    printf ("%lld\n",ans);
    return 0;
}