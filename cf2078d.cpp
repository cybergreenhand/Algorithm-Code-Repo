#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=35;
int T,n;
char sg[2][N];
int a[2][N],nxt[2][N],nxta[2][N];
inline void precalc(int i,int t)
{
    if (sg[t][i]=='x')
    {
        nxt[t][i]=i;
        nxta[t][i]=a[t][i];
    }
    else 
    {
        nxt[t][i]=nxt[t][i+1];
        nxta[t][i]=nxta[t][i+1];
    }
}
inline ll pass(int id,ll sp,int t)
{
    if (sg[t][id]=='+') return a[t][id];
    else return sp*(a[t][id]-1);
}
inline ll Pass(int id,ll l,ll r)
{
    return pass(id,l,0)+pass(id,r,1);
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--)
    {
        cin>>n;
        for (int i=1;i<=n;++i) cin>>sg[0][i]>>a[0][i]>>sg[1][i]>>a[1][i];
        nxt[0][n+1]=nxt[1][n+1]=n+1;
        nxta[0][n+1]=nxta[1][n+1]=1;
        for (int i=n;i>=1;--i)
        {
            precalc(i,0);
            precalc(i,1);
        }
        // for (int i=1;i<=n;++i)
        // {
        //     cout<<i<<endl;
        //     cout<<nxt[0][i]<<" "<<nxta[0][i]<<endl;
        //     cout<<nxt[1][i]<<" "<<nxta[1][i]<<endl;
        // }
        ll L=1,R=1,New=0;
        for (int i=1;i<=n;++i)
        {
            int j=i;
            while (nxt[0][j]<=n&&nxt[0][j]==nxt[1][j]&&nxta[0][j]==nxta[1][j]) j=nxt[0][j]+1;
            if (nxt[0][j]<nxt[1][j]) L+=New;
            else if (nxt[1][j]<nxt[0][j]) R+=New;
            else 
            {
                if (nxta[0][j]>nxta[1][j]) L+=New;
                else R+=New;
            }
            New=Pass(i,L,R);
            // cout<<L<<" "<<R<<" "<<New<<endl;
        }
        cout<<L+R+New<<endl;
    }
    return 0;
}