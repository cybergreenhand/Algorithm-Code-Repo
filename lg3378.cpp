#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,len;
int tr[N];
inline void push(int x)
{
    tr[++len]=x;
    for (int i=len;i>1;i>>=1) 
    {
        if (tr[i]<tr[i>>1]) swap(tr[i],tr[i>>1]);
        else break;
    }
}
inline void pop()
{
    tr[1]=tr[len--];
    for (int i=1;i<<1<=len;)
    {
        int son=i<<1;
        if (son<len&&tr[son]>tr[son+1]) ++son;
        if (tr[son]<tr[i]) swap(tr[son],tr[i]);
        else break;
        i=son;
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;++i)
    {
        int op;
        scanf ("%d",&op);
        if (op==1)
        {
            int x;
            scanf ("%d",&x);
            push(x);
        }
        else if (op==2) printf ("%d\n",tr[1]);
        else pop();
    }
    return 0;
}