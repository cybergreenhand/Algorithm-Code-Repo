#include <bits/stdc++.h>
using namespace std;
const int N=2e4+10;
int n;
int a[N][20];
string str[N];
string divide(int num)
{
    if (str[num].length()>0) return str[num];
    int cnt=0,t=num;
    for (int i=0;t;++i) 
    {
        if (t&1) a[num][++cnt]=i;
        t>>=1;
    }
    if (a[num][cnt]>1) str[num]="2("+divide(a[num][cnt--])+")";
    else str[num]=divide(1<<a[num][cnt--]);
    while (cnt)
    {
        str[num]+="+";
        if (a[num][cnt]>1) str[num]=str[num]+"2("+divide(a[num][cnt--])+")";
        else str[num]+=divide(1<<a[num][cnt--]);
    }
    return str[num];
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    cin>>n;
    str[1]="2(0)";
    str[2]="2";
    cout<<divide(n)<<endl;
    return 0;
}