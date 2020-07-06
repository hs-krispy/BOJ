//
// Created by 0864h on 2020-07-07.
//
#include<iostream>
using namespace std;
int GCD(int a, int b)
{
    int c;
    while(b > 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    int t, n, num[101];
    cin >> t;BOJBOH
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        long long sum = 0;
        for(int j = 1; j <= n; j++)
        {
            cin >> num[j];
        }
        for(int j = 1; j <= n; j++)
        {
            for(int k = j + 1; k <= n; k++)
                sum += GCD(num[j], num[k]);
        }
        cout << sum << "\n";
    }
}
