#include <bits/stdc++.h>
using namespace std;
int T,n,L,R;
inline int query(int l,int r)
{
    int a,p;
    cout<<"1 "<<l<<" "<<r<<endl;
    cout.flush();
    cin>>p;
    cout<<"2 "<<l<<" "<<r<<endl;
    cout.flush();
    cin>>a;
    return a-p;
}
int main()
{
    cin>>T;
    while (T--)
    {
        cin>>n;
        cout<<"2 1 "<<n<<endl;
        cout.flush();
        int sa;
        cin>>sa;
        int l=1,r=n;
        while (l<r)
        {
            int mid=l+r>>1;
            int t=query(l,mid);
            if (t==mid-l+1) r=l;
            else if (t>0) r=mid;
            else l=mid+1;
        }
        L=l;
        R=l+sa-n*(n+1)/2-1;
        cout<<"! "<<L<<" "<<R<<endl;
        cout.flush();
    }
    return 0;
}