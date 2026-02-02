#include <bits/stdc++.h>
using namespace std;
const int N=15005;
int id,tim,run,fir,now=-1;
struct Program{
    int id,tim,run,fir;
    bool operator< (const Program &a) const{
        if (fir==a.fir) return tim>a.tim;
        else return fir<a.fir;
    }
};
priority_queue<Program> q;
int main()
{
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    while (scanf ("%d%d%d%d",&id,&tim,&run,&fir)!=EOF)
    {   
        if (now==-1) 
        {
            now=tim;
            q.push({id,tim,run,fir});
            continue;
        }
        Program t=q.top();
        if (t.run<=tim-now) 
        {
            while (q.size()>0)
            {
                if (t.run<=tim-now)
                {
                    q.pop();
                    now+=t.run;
                    printf ("%d %d\n",t.id,now);
                }
                else
                {
                    q.pop();
                    t.run-=(tim-now);
                    now=tim;
                    q.push(t);
                    break;
                }
                if (q.size()>0) t=q.top();
            }
            now=tim;
            q.push({id,tim,run,fir});
        }
        else
        {
            q.pop();
            t.run-=(tim-now);
            now=tim;
            q.push(t);
            q.push({id,tim,run,fir});
        }
    }
    while (q.size()>0)
    {
        Program t=q.top();
        q.pop();
        now+=t.run;
        printf ("%d %d\n",t.id,now);
    }
    return 0;
}