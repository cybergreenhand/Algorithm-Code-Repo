#include <bits/stdc++.h>
using namespace std;
const int N=1050;
int n;
int sum[2][N];
char str[N],t[N<<1];
void build(int node,int l,int r)
{
    if (!(sum[0][r]-sum[0][l-1])) t[node]='I';
    else if (!(sum[1][r]-sum[1][l-1])) t[node]='B';
    else t[node]='F';
    if (l==r) return;
    int k=(r-l+1)>>1;
    build(node<<1,l,l+k-1);
    build((node<<1)+1,l+k,r);
}
void print(int node)
{
    if (node>(1<<n+1)-1) return;
    print(node<<1);
    print((node<<1)+1);
    printf ("%c",t[node]);
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%s",&n,str+1);
    for (int i=1;i<=(1<<n);++i) 
    {
        sum[0][i]=sum[0][i-1]+(str[i]=='0');
        sum[1][i]=sum[1][i-1]+(str[i]=='1');
    }
    build(1,1,(1<<n));
    print(1);
    return 0;
}