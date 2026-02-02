#include <bits/stdc++.h>
using namespace std;
int m,S,T,maxl;
int f[2][20];
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d%d%d",&m,&S,&T);
    int t=0,s=0;
    while (m>10&&t<T&&s<S)
    {
        m-=10;
        s+=60;
        ++t;
    }
    if (t==T&&s<S) 
    {
        printf ("No\n%d\n",s);
        return 0;
    }
    else if (s>=S)
    {
        printf ("Yes\n%d\n",t);
        return 0;
    }
    memset(f,-0x3f,sizeof (f));
    f[t&1][m]=s;
    for (int i=t+1;i<=T;++i)
    {
        for (int j=0;j<=15;++j)
        {
            f[i&1][j]=max(f[i&1][j],f[i-1&1][j]+17);
            if (j>=4) f[i&1][j]=max(f[i&1][j],f[i-1&1][j-4]);
            if (j+10<=15) f[i&1][j]=max(f[i&1][j],f[i-1&1][j+10]+60);
            if (f[i&1][j]>=S)
            {
                printf ("Yes\n%d\n",i);
                return 0;
            }
            maxl=max(maxl,f[i&1][j]);
        }   
    }
    printf ("No\n%d\n",maxl);
    return 0;
}