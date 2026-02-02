#include <bits/stdc++.h>
using namespace std;
int i;
int main()
{
    system("g++ rand.cpp -o rand");
    system("g++ test.cpp -o test");
    system("g++ c.cpp -o ans");
    while (true)
    {
        system ("rand.exe");
        system ("test.exe");
        system ("ans.exe");
        printf ("Test %d\n",++i);
        if (system("fc a.out b.out"))
        {
            printf ("Wrong on Test %d\n",i);
            system ("pause");
            break;
        }
    }
    return 0;
}