#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+5,M=205,mod=1e9+7;
int n,m,T;
string A,B;
ll f[2][M][M][2];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m>>T;
    cin>>A>>B;
    A=" "+A;
    B=" "+B;
    f[0][0][0][0]=1;
    for (int i=1;i<=n;++i)
    {
        memset(f[i&1],0,sizeof (f[i&1]));
        for (int j=0;j<=min(m,i);++j)
        {
            for (int k=0;k<=T;++k)
            {
                // cout<<i<<" "<<j<<" "<<k<<endl;
                if (A[i]==B[j]&&k>0)
                {
                    f[i&1][j][k][1]=(f[i&1][j][k][1]+f[(i-1)&1][j-1][k-1][0]+f[(i-1)&1][j-1][k-1][1])%mod;
                    // cout<<"FUCK 1"<<endl;
                }
                if (i>1&&j>1&&k>0&&A[i-1]==B[j-1]&&A[i]==B[j]) 
                {
                    f[i&1][j][k][1]=(f[i&1][j][k][1]+f[(i-1)&1][j-1][k][1])%mod;
                    // cout<<"FUCK 2"<<endl;
                }
                f[i&1][j][k][0]=(f[i&1][j][k][0]+f[(i-1)&1][j][k][0]+f[(i-1)&1][j][k][1])%mod;
                // cout<<f[i&1][j][k][0]<<" "<<f[i&1][j][k][1]<<endl;
            }
        }    
    }
    cout<<(f[n&1][m][T][0]+f[n&1][m][T][1])%mod<<endl;
    return 0;
}