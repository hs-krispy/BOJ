//
// Created by 0864h on 2021-01-26.
//
#include<iostream>
#include<algorithm>
using namespace std;
int N, rk[500001];
int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> rk[i];
    sort(&rk[0], &rk[N + 1]);
    long long Min = 0;
    for(int i = 1; i <= N; i++)
    {
        Min += abs(i - rk[i]);
    }
    cout << Min;
}
