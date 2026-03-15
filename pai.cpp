#include <bits/stdc++.h>
using namespace std;
int i;
int main()
{
    system("g++ rand.cpp -o rand");
    system("g++ cf2110e.cpp -o ans");
    system("g++ test.cpp -o test");
    while (true)
    {
        system ("rand.exe");
        system ("ans.exe");
        system ("test.exe");
        printf ("Test %d\n",++i);
        if (system("fc c.out b.out"))
        {
            printf ("Wrong on Test %d\n",i);
            system ("pause");
            break;
        }
    }
    return 0;
}