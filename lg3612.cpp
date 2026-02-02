#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
string str;
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    cin>>str>>n;
    int len=str.length(),cnt=0;
    while (1ll*len*(1ll<<cnt)<n) ++cnt;
    --cnt;
    // cout<<cnt<<endl;
    while (n>len&&cnt>=0)
    {
        // cout<<n<<endl;
        if (n>1ll*len*(1ll<<cnt)) n=n-(1ll*len*(1ll<<cnt)+1);
        if (n==0) n=1ll*len*(1ll<<cnt);
        --cnt;
    }
    // cout<<n<<endl;
    cout<<str[n-1]<<endl;
    return 0;
}