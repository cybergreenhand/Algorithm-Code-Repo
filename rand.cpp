#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("a.in","w",stdout);
    srand(time(0));
    int T=10;
    cout<<T<<endl;
    for (int i=1;i<=T;++i)
    {
        cout<<rand()<<" "<<rand()<<endl;
    }
    return 0;
}