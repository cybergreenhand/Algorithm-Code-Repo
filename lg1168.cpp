#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int a[N];
priority_queue<int> q1;
priority_queue<int,vector<int>,greater<int>> q2;
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;++i) scanf ("%d",&a[i]);
    for (int i=1;(i<<1)-1<=n;++i)
    {
        if (q1.empty()) q1.push(a[(i<<1)-1]);
        else
        {
            int x=(i<<1)-2,y=(i<<1)-1;
            if (a[x]>q1.top()) q2.push(a[x]);
            else q1.push(a[x]);
            if (a[y]>q1.top()) q2.push(a[y]);
            else q1.push(a[y]);
            while (q2.size()>=q1.size())
            {
                q1.push(q2.top());
                q2.pop();
            }
            while (q1.size()>q2.size()+1)
            {
                q2.push(q1.top());
                q1.pop();
            }
        }
        printf ("%d\n",q1.top());
    }
    return 0;
}