#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n;
char str[N];
int f[N][N];
inline int check(int s,int len,int last)
{
    int sum=1;
    for (int i=s+len;i+len-1<=last;i+=len)
    {
        bool flag=true;
        for (int j=i;j<i+len;++j)
        {
            int id=j-i+1;
            if (str[s+id-1]!=str[j])
            {
                flag=false;
                break;
            }
        }
        if (flag) ++sum;
        else break;
    }
    return sum;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>str+1;
    n=strlen(str+1);
    memset(f,0x3f,sizeof (f));
    for (int i=1;i<=n;++i) f[i][i]=1;
    for (int len=2;len<=n;++len)
    {
        for (int l=1,r=l+len-1;r<=n;++l,++r)
        {
            for (int fl=1;fl<=(len>>1);++fl)
            {   
                for (int s=l;s+(fl<<1)-1<=r;++s)
                {
                    int cnt=check(s,fl,r);
                    int t=0,num=0,tmp=cnt;
                    while (tmp)
                    {
                        ++num;
                        tmp/=10;
                    }
                    if (s>l) t+=f[l][s-1];
                    if (s+cnt*fl-1<r) t+=f[s+cnt*fl][r];
                    t+=min(cnt*min(fl,f[s][s+fl-1]),2+num+min(fl,f[s][s+fl-1]));
                    f[l][r]=min(f[l][r],t);
                }
            }
        }
    }
    cout<<f[1][n]<<endl;
    return 0;
}