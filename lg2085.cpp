#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5,eps=1e-5;
int n,m;
int a[N],b[N],c[N];
struct Num{
    ll num;
    int id,l,r;
    bool operator> (const Num &t) const{
        if (num==t.num) return a[id]<a[t.id];
        return num>t.num;
    }
};
priority_queue<Num,vector<Num>,greater<Num>> q;
inline ll f(int x,int id)
{
    return 1ll*a[id]*x*x+1ll*b[id]*x+c[id];
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n;++i) 
    {
        scanf ("%d%d%d",&a[i],&b[i],&c[i]);
        int x=-b[i]/(a[i]<<1);
        if (x<=0) x=1;
        else if (fabs(-1.0*b[i]/(a[i]<<1)-x)>0.5+eps) ++x;
        q.push({f(x,i),i,x,x});
    }
    for (int i=1;i<=m;++i)
    {
        Num t=q.top();
        q.pop();
        printf ("%d ",t.num);
        ll x=1e18,y=f(t.r+1,t.id);
        if (t.l>1) x=f(t.l-1,t.id);
        if (x<=y) q.push({x,t.id,t.l-1,t.r});
        else q.push({y,t.id,t.l,t.r+1});
        // cout<<x<<" "<<y<<endl;
    }
    return 0;
}