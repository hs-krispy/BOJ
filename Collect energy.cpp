//
// Created by 0864h on 2020-05-03.
//
#include<iostream>
#include <cstring>
using namespace std;
int Max = 0;
void calc(int n, int * w, int energy)
{
    int res = 0, arr[11], c;
    memset(arr, 0, sizeof(arr));
    if(n == 2)
    {
        if(Max < energy)
            Max = energy;
        return;
    }
    for(int i = 2; i <= n - 1; i++)
    {
        res = w[i-1] * w[i+1];
        energy += res;
        c = 1;
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
                continue;
            arr[c++] = w[j];
        }
        calc(n - 1, arr, energy);
        energy -= res;
    }
}
int main()
{
    int n, w[11];
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>w[i];
    calc(n, w, 0);
    cout<<Max;
}
