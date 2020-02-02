//
// Created by 0864h on 2020-02-03.
//
#include <iostream>
using namespace std;
int main()
{
    int n,i,count=0;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        if (i >= 1 && i <= 99)
            count++;
        else if (i >= 100 && i <= 999)
        {
            if ((i / 100 - (i % 100) / 10) == ((i % 100) / 10 - i % 10))
                count++;
        }
    }
    cout<< count;
}