#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
const int N=1e5+5;
int n,m,Q,U,V,T;
int a[N];
queue<pair<int,int>> q[3];
inline int calc(int i,int now)
{
    return q[i].front().fir+(now-q[i].front().sec-1)*Q;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d%d%d%d%d",&n,&m,&Q,&U,&V,&T);
    for (int i=1;i<=n;++i) scanf ("%d",&a[i]);
    sort(a+1,a+n+1);
    for (int i=n;i>=1;--i) q[0].push({a[i],0});
    for (int i=1;i<=m;++i)
    {
        // for (int j=0;j<3;++j) if (q[j].size()) cout<<q[j].front().fir+(i-q[j].front().sec-1)*Q<<" ";
        // cout<<endl;
        int maxi=0;
        if (q[0].empty()) maxi=1;
        for (int j=maxi+1;j<3;++j) 
        {
            if (q[j].size())
            {
                if (calc(j,i)>calc(maxi,i)) maxi=j;
            }
        }
        int l=q[maxi].front().fir,t=q[maxi].front().sec;
        q[maxi].pop();
        l+=(i-t-1)*Q;
        if (i%T==0) printf ("%d ",l);
        int b=1ll*l*U/V,c=l-b;
        if (b<c) swap(b,c);
        q[1].push({b,i});
        q[2].push({c,i});
    }
    printf ("\n");
    for (int i=1;i<=n+m;++i)
    {
        int maxi=0;
        while (q[maxi].empty()) ++maxi;
        for (int j=maxi+1;j<3;++j)
        {
            if (q[j].size())
            {
                if (calc(j,m+1)>calc(maxi,m+1)) maxi=j;
            }
        }
        if (i%T==0) printf ("%d ",calc(maxi,m+1));
        q[maxi].pop();
    }
    return 0;
}