#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=1e3+10;
int n,ans;
struct Resident{
    int s,a;
    bool operator< (const Resident &t) const{
        if (a!=t.a) return a<t.a;
        else return s<t.s;
    }
}r[N];
vector<Resident> a[M];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;++i) scanf ("%d",&r[i].s);
    for (int i=1;i<=n;++i) scanf ("%d",&r[i].a);
    sort(r+1,r+n+1);
    int now=r[1].a,cnt=1;
    for (int i=1;i<=n;)
    {
        while (i<=n&&now==r[i].a) a[cnt].push_back(r[i++]);
        now=r[i].a;
        ++cnt;
    }
    --cnt;
    now=0;
    for (int i=1;i<=n;++i)
    {
        int mx=0,id=0;
        Resident res;
        for (int j=1;j<=cnt;++j)
        {
            if (a[j].empty()) continue;
            if ((max(0,a[j].back().s-now)<<1)+a[j].back().a>mx)
            {
                mx=(max(0,a[j].back().s-now)<<1)+a[j].back().a;
                res=a[j].back();
                id=j;
            }
        }
        a[id].pop_back();
        // else cout<<"ID IS "<<id<<endl;
        ans+=mx;
        now=max(now,res.s);
        // cout<<res.s<<" "<<res.a<<endl;
        printf ("%d\n",ans);
    }
    return 0;   
}