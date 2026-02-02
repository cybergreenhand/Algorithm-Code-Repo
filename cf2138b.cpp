#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int T,n,Q;
int a[N],pre[N],c[N],nxt[N],g[N][20];
inline void clear()
{
    for (int i=1;i<=n;++i) 
    {
        pre[i]=0;
        nxt[i]=0;
        g[i][0]=0;
    }
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--)
    {
        cin>>n>>Q;
        clear();
        int hh=1,tt=0;
        for (int i=1;i<=n;++i) 
        {
            cin>>a[i];
            while (hh<=tt&&a[c[tt]]<a[i]) --tt;
            if (hh<=tt) pre[i]=c[tt];
            c[++tt]=i;
        }
        hh=1,tt=0;
        for (int i=n;i>=1;--i)
        {
            while (hh<=tt&&a[c[tt]]>a[i]) --tt;
            if (hh<=tt) nxt[i]=c[tt];
            c[++tt]=i;
        }
        // for (int i=1;i<=n;++i) cout<<pre[i]<<" "<<nxt[i]<<endl;
        for (int i=2;i<n;++i) if (pre[i]&&nxt[i]) g[nxt[i]][0]=max(g[nxt[i]][0],pre[i]);
        // for (int i=1;i<=n;++i) cout<<g[i][0]<<" ";
        // cout<<endl;
        for (int j=1;(1<<j)<=n;++j)
        {
            for (int i=1;i+(1<<j)-1<=n;++i)
            {
                g[i][j]=max(g[i][j-1],g[i+(1<<j-1)][j-1]);
            }
        }
        for (int i=1;i<=Q;++i) 
        {
            int l,r;
            cin>>l>>r;
            int k=log2(r-l+1);
            if (max(g[l][k],g[r-(1<<k)+1][k])<l) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}