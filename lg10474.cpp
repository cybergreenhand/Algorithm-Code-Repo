#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pii;
const int P=1331,mod1=9999991,mod2=999917,N=1e6+5,M=1e3+5;
int m,n,A,B,Q;
int id1[M],id2[M];
ll t1[M],t2[M];
string str,c;
ll pw1[N],pw2[N],a[M][M],b[M][M];
set<pii> ans;
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>m>>n>>A>>B;
    pw1[0]=pw2[0]=1;
    for (int i=1;i<=A;++i)
    {
        for (int j=1;j<=B;++j)
        {
            pw1[(i-1)*B+j]=pw1[(i-1)*B+j-1]*P%mod1;
            pw2[(i-1)*B+j]=pw2[(i-1)*B+j-1]*P%mod2;
        }
    }
    for (int i=1;i<=m;++i) 
    {
        cin>>str;
        str=" "+str;
        for (int j=1;j<=n;++j)
        {
            a[i][j]=(a[i][j-1]*P%mod1+str[j]-'0')%mod1;
            b[i][j]=(b[i][j-1]*P%mod2+str[j]-'0')%mod2;
        }
    }
    cin>>Q;
    for (int i=1;i<=Q;++i)
    {
        ll sum1=0,sum2=0;
        for (int j=1;j<=A;++j)
        {
            cin>>c;
            c=" "+c;
            for (int k=1;k<=B;++k) 
            {
                sum1=(sum1*P%mod1+c[k]-'0')%mod1;
                sum2=(sum2*P%mod2+c[k]-'0')%mod2;
            }
        }
        id1[i]=sum1;
        id2[i]=sum2;
    }
    for (int i=1;i+B-1<=n;++i)
    {
        ll sum1=0,sum2=0;
        for (int j=1;j<=A;++j)
        {
            sum1=sum1*pw1[B]%mod1;
            sum2=sum2*pw2[B]%mod2;
            t1[j]=(a[j][i+B-1]-a[j][i-1]*pw1[B]%mod1+mod1)%mod1;
            t2[j]=(b[j][i+B-1]-b[j][i-1]*pw2[B]%mod2+mod2)%mod2;
            sum1=(sum1+t1[j])%mod1;
            sum2=(sum2+t2[j])%mod2;
        }
        ans.insert({sum1,sum2});
        for (int j=A+1;j<=m;++j)
        {
            ll cut1=t1[j-A]*pw1[B*(A-1)]%mod1,cut2=t2[j-A]*pw2[B*(A-1)]%mod2;
            sum1=(sum1-cut1+mod1)%mod1;
            sum2=(sum2-cut2+mod2)%mod2;
            sum1=sum1*pw1[B]%mod1;
            sum2=sum2*pw2[B]%mod2;
            t1[j]=(a[j][i+B-1]-a[j][i-1]*pw1[B]%mod1+mod1)%mod1;
            t2[j]=(b[j][i+B-1]-b[j][i-1]*pw2[B]%mod2+mod2)%mod2;
            sum1=(sum1+t1[j])%mod1;
            sum2=(sum2+t2[j])%mod2;
            ans.insert({sum1,sum2});
        }
    }
    for (int i=1;i<=Q;++i) 
    {
        auto it=ans.find({id1[i],id2[i]});
        if (it!=ans.end()) cout<<"1"<<endl;
        else cout<<"0"<<endl;
    }
    return 0;
}