#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=105;
string str;
char s1[N],s2[N];
string s3[N],s4[N];
int t1,t2,t3,t4;
inline int get(char c)
{
    switch (c)
    {
        case '(': return 0;
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 3;
        default: return -1;
    }
}
inline ll ksm(int a,int b)
{
    ll r=1;
    while (b)
    {
        if (b&1) r*=a;
        a=1ll*a*a;
        b>>=1;
    }
    return r;
}
inline ll calc(int x,int y,char c)
{
    switch (c)
    {
        case '+': return x+y;
        case '-': return x-y;
        case '*': return 1ll*x*y;
        case '/': return x/y;
        case '^': return ksm(x,y);
        default: return -1;
    }
}
inline bool check(string c)
{
    if (c!="+"&&c!="-"&&c!="*"&&c!="/"&&c!="^") return true;
    else return false;
}
inline int trans1(string c)
{
    int sum=0,len=c.length();
    if (c[0]=='-') for (int i=1;i<len;++i) sum=sum*10+c[i]-'0';
    else for (int i=0;i<len;++i) sum=sum*10+c[i]-'0';
    if (c[0]=='-') sum=-sum;
    return sum;
}
inline string trans2(int x)
{
    if (x==0) return "0";
    string sum;
    bool flag;
    if (x>0) flag=true;
    else 
    {
        flag=false;
        x=-x;
    }
    while (x)
    {
        char a='0'+x%10;
        sum+=a;
        x/=10;
    }
    if (!flag) sum+='-';
    reverse(sum.begin(),sum.end());
    return sum;
}
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>str;
    for (char a:str)
    {
        if (isdigit(a)) s1[++t1]=a;
        else
        {
            if (a=='(') s2[++t2]=a;
            else if (a==')')
            {
                while (s2[t2]!='(') s1[++t1]=s2[t2--];
                --t2;
            }
            else
            {
                int x=get(a);
                if (s2[t2]=='^'&&a=='^') s2[++t2]=a;
                else
                {
                    while (t2>0&&get(s2[t2])>=x) s1[++t1]=s2[t2--];
                    s2[++t2]=a;
                }
            }
        }
    }
    while (t2>0) s1[++t1]=s2[t2--];
    t3=t1;
    for (int i=1;i<=t1;++i) 
    {
        cout<<s1[i]<<" ";
        s3[i].push_back(s1[i]);
    }
    cout<<endl;
    while (t3>1)
    {
        for (int i=1;i<=t3;++i)
        {
            if (check(s3[i])) continue;
            for (int j=1;j<=i-3;++j) s4[++t4]=s3[j];
            s4[++t4]=trans2(calc(trans1(s3[i-2]),trans1(s3[i-1]),s3[i][0]));
            for (int j=i+1;j<=t3;++j) s4[++t4]=s3[j];
            t3=t4;
            break;
        }
        for (int i=1;i<=t3;++i) s3[i]=s4[i];
        for (int i=1;i<=t3;++i) cout<<s3[i]<<" ";
        cout<<endl;
        t4=0;
    }
    return 0;
}