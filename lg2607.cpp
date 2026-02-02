#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;++i)
    {
        int fa;
        scanf ("%d",&fa);
        son[fa].push_back(i);
    }
    return 0;
}