#include <bits/stdc++.h>
using namespace std;
int n,m,T;
int f[2][55][2505][3];
string a[55];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    cin>>n>>m>>T;
    for (int i=1;i<=n;++i) cin>>a[i];
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            for (int k=1;k<=T;++k)
            {
                if (j==1)
                {
                    f[i&1][j][k][0]=max({f[i-1&1][m][k][0],f[i-1&1][m][k][1],f[i-1&1][m][k][2]});
                    int num=a[i][j-1]-'0';
                    f[i&1][j][k][1]=f[i-1&1][m][k-1][0]+(num==0);
                    f[i&1][j][k][2]=f[i-1&1][m][k-1][0]+(num==1);
                    if (k>1) 
                    {
                        f[i&1][j][k][1]=max({f[i&1][j][k][1],f[i-1&1][m][k-1][1]+(num==0),f[i-1&1][m][k-1][2]+(num==0)});
                        f[i&1][j][k][2]=max({f[i&1][j][k][2],f[i-1&1][m][k-1][1]+(num==1),f[i-1&1][m][k-1][2]+(num==1)});
                    }
                }
                else
                {
                    f[i&1][j][k][0]=max({f[i&1][j-1][k][0],f[i&1][j-1][k][1],f[i&1][j-1][k][2]});
                    int num=a[i][j-1]-'0';
                    f[i&1][j][k][1]=max(f[i&1][j-1][k-1][0]+(num==0),f[i&1][j-1][k][1]+(num==0));
                    f[i&1][j][k][2]=max(f[i&1][j-1][k-1][0]+(num==1),f[i&1][j-1][k][2]+(num==1));                        
                    if (k>1) 
                    {
                        f[i&1][j][k][1]=max(f[i&1][j][k][1],f[i&1][j-1][k-1][2]+(num==0));
                        f[i&1][j][k][2]=max(f[i&1][j][k][2],f[i&1][j-1][k-1][1]+(num==1));
                    }
                }
                // cout<<i<<" "<<j<<" "<<k<<" "<<endl;
                // cout<<f[i&1][j][k][0]<<" "<<f[i&1][j][k][1]<<" "<<f[i&1][j][k][2]<<endl<<endl;
            }
        }
        // for (int k=1;k<=T;++k)
        // {
        //     cout<<i<<" "<<k<<endl;
        //     cout<<f[i&1][m][k][0]<<" "<<f[i&1][m][k][1]<<" "<<f[i&1][m][k][2]<<endl;
        // }
    }
    cout<<max({f[n&1][m][T][0],f[n&1][m][T][1],f[n&1][m][T][2]})<<endl;
    return 0;
}