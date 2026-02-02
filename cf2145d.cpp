#include<bits/stdc++.h>
using namespace std;
int T,n,k,tot,a[35],flag;
inline int V(int x) 
{
    return x*(x+1)/2;
}
void dfs(int cnt,int sum,int val,int lst)
{
    if (val>k||sum>n) return;
    if (val==k&&sum!=n) return;
    if (sum==n&&val!=k) return;
    if (flag) return;
    if (val==k) 
    {
        tot=cnt,flag=1;
        return;
    }
    for (int i=lst;i>=1;--i)
    {
        if (val+V(i)>k) continue;
        if (sum+i>n) continue;
        a[cnt+1]=i;
        dfs(cnt+1,sum+i,val+V(i),i);
        if (flag) return;
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    cin>>T;
    while (T--)
    {
        cin>>n>>k;
        k=V(n)-k;
        flag=0;
        dfs(0,0,0,n);
        if (!flag) 
        {
            cout<<0<<endl;
            continue;
        }
        int v1=1,v2=n;
        for (int i=1;i<=tot;++i)
        {
            for (int j=1;j<a[i];++j) cout<<(v1++)<<' ';
            cout<<(v2--)<<' ';
        }
        cout<<endl;
    }
}
