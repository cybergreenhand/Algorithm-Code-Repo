#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
typedef pair<int,int> pii;
const int N=2e5+5;
int T,n,cnts;
int a[N];
vector<pii> ans;
vector<int> st;
struct Segment{
    int min,max;
}seg[N];
inline void clear()
{
    cnts=0;
    ans.clear();
    st.clear();
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while (T--)
    {
        clear();
        cin>>n;
        for (int i=1;i<=n;++i) cin>>a[i];
        for (int i=1;i<=n;++i)
        {
            int j=i;
            while (j<n&&a[j+1]>a[j]) ++j;
            ++cnts;
            seg[cnts].min=a[i];
            seg[cnts].max=a[j];
            // cout<<i<<" "<<j<<endl;
            for (int k=i+1;k<=j;++k) ans.push_back({a[i],a[k]});
            i=j;
        }
        for (int i=cnts;i>=1;--i)
        {
            if (!st.empty()&&seg[st.back()].max>seg[i].min)
            {
                int maxid=i;
                while (!st.empty()&&seg[st.back()].max>seg[i].min)
                {
                    if (seg[st.back()].max>seg[maxid].max) maxid=st.back();
                    ans.push_back({seg[i].min,seg[st.back()].max});
                    st.pop_back();
                }
                st.push_back(maxid);
            }
            else st.push_back(i);
        }
        // cout<<ans.size()<<endl;
        if (ans.size()==n-1)
        {
            cout<<"Yes"<<endl;
            // for (auto i:ans) cout<<i.fir<<" "<<i.sec<<endl;
        }
        else cout<<"No"<<endl;
    }
    return 0;
}