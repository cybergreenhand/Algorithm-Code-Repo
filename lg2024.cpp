#include <bits/stdc++.h>
using namespace std;
const int N=150005,M=1e5+5;
int n,m,ans;
int fa[N];
int find(int x)
{
    if (x!=fa[x]) return fa[x]=find(fa[x]);
    return fa[x];
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;++i) 
    {
        fa[i]=i;
        fa[i+n]=i+n;
        fa[i+(n<<1)]=i+(n<<1);
    }
    for (int i=1;i<=m;++i)
    {
        int op,x,y;
        scanf ("%d%d%d",&op,&x,&y);
        if (x>n||y>n) 
        {
            ++ans;
            continue;
        }
        if (x==y) 
        {
            if (op==2) ++ans;
            continue;
        }
        int fx=find(x),fxn=find(x+n),fxnn=find(x+(n<<1));
        int fy=find(y),fyn=find(y+n),fynn=find(y+(n<<1));
        if (op==1)
        {
            if (fx==fyn||fxn==fynn||fynn==fx||fy==fxn||fyn==fxnn||fynn==fx) 
            {
                ++ans;
                continue;
            }
            fa[fx]=fy,fa[fxn]=fyn,fa[fxnn]=fynn;
        }   
        else
        {
            if (fx==fy||fx==fynn||fxn==fy||fxn==fyn||fxnn==fyn||fxnn==fynn)
            {
                ++ans;
                continue;
            }
            fa[fx]=fyn,fa[fxn]=fynn,fa[fxnn]=fy;
        }
    }
    printf ("%d\n",ans);
    return 0;
}