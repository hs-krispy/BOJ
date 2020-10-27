//
// Created by 0864h on 2020-10-28.
//
#include<iostream>
using namespace std;
int n, size[1001], d[1001], Max = 0;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> size[i];
        d[i] = 1;
    }
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(size[i] > size[j])
                d[i] = max(d[i], d[j] + 1);
        }
        if(Max < d[i])
            Max = d[i];
    }
    cout << Max;
}
