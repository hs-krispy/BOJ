//
// Created by 0864h on 2021-01-12.
//
#include<iostream>
using namespace std;
int D, K, d[31], A, B;
int main()
{
    cin >> D >> K;
    d[D] = K;
    for(int i = K / 2; i < K; i++)
    {
        d[D - 1] = i;
        for(int j = D; j >= 3; j--)
        {
            d[j - 2] = d[j] - d[j - 1];
            if(d[j - 1] < d[j - 2])
                break;
            if(j == 3)
            {
                A = d[j - 2];
                B = d[j - 1];
            }
        }
    }
    cout << A << "\n" << B;
}
