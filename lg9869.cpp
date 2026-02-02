#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,C,T;
int fa[N<<1],sz[N<<1],fir[N],las[N];
struct Opt{
    char v;
    int i,j;
}op[N];
inline void clear()
{
    for (int i=1;i<=n;++i) 
    {
        fir[i]=0x3f3f3f3f;
        las[i]=-0x3f3f3f3f;
    }
    for (int i=1;i<=(n<<1)+3;++i)
    {
        fa[i]=i;
        sz[i]=1;
    }
}
int find(int x)
{
    if (x!=fa[x]) return fa[x]=find(fa[x]);
    return fa[x];
}
inline void merge(int x,int y)
{
    int fx=find(x),fy=find(y);
    if (fx!=fy)
    {
        if (fx>(n<<1))
        {
            fa[fy]=fx;
            sz[fx]+=sz[fy];
        }
        else
        {
            fa[fx]=fy;
            sz[fy]+=sz[fx];
        }
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>C>>T;
    while (T--)
    {
        cin>>n>>m;
        clear();
        for (int i=1;i<=m;++i) 
        {
            cin>>op[i].v;
            if (op[i].v=='+'||op[i].v=='-') cin>>op[i].i>>op[i].j;
            else cin>>op[i].i; 
            fir[op[i].i]=min(fir[op[i].i],i);
            las[op[i].i]=max(las[op[i].i],i);
        }
        for (int i=m;i>=1;--i)
        {
            if (i!=las[op[i].i]) continue;
            switch (op[i].v)
            {
                case 'T':
                    merge(op[i].i,(n<<1)+1);
                    merge(op[i].i+n,(n<<1)+2);
                    break;
                case 'F':
                    merge(op[i].i,(n<<1)+2);
                    merge(op[i].i+n,(n<<1)+1);
                    break;
                case 'U':
                    merge(op[i].i,(n<<1)+3);
                    merge(op[i].i+n,(n<<1)+3);
                    break;
                case '+':
                    if (fir[op[i].j]>i||i>las[op[i].j])
                    {
                        merge(op[i].i,op[i].j);
                        merge(op[i].i+n,op[i].j+n);
                        int a=find(op[i].i),b=find(op[i].i+n);
                        if (a==b) merge(a,(n<<1)+3);
                    } 
                    break;
                case '-':
                    if (fir[op[i].j]>i||i>las[op[i].j])
                    {
                        merge(op[i].i,op[i].j+n);
                        merge(op[i].i+n,op[i].j);
                        int a=find(op[i].i),b=find(op[i].i+n);
                        if (a==b) merge(a,(n<<1)+3);
                    } 
                    break;
                default:break;
            }
        }
        cout<<((sz[(n<<1)+3]-1)>>1)<<endl;
    }
    return 0;
}