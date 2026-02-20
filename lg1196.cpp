#include <bits/stdc++.h>
using namespace std;
const int N=3e4+5;
int T;
int fa[N],d[N],sz[N];
int find(int x)
{
    if (x!=fa[x])
    {
        int t=fa[x];
        fa[x]=find(fa[x]);
        d[x]+=d[t]-1;
    }
    return fa[x];
}
inline void merge(int x,int y)
{
    int fx=find(x),fy=find(y);
    if (fx==fy) return;
    fa[fx]=fy;
    d[fx]+=sz[fy];
    sz[fy]+=sz[fx];
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    for (int i=1;i<=30000;++i) 
    {
        fa[i]=i;
        d[i]=1;
        sz[i]=1;
    }
    cin>>T;
    while (T--)
    {
        char opt;
        int x,y;
        cin>>opt>>x>>y;
        if (opt=='M') merge(x,y);
        else if (opt=='C')
        {
            if (find(x)==find(y)) cout<<abs(d[x]-d[y])-1<<endl;
            else cout<<"-1"<<endl;
        }
    }
    return 0;
}