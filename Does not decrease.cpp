//
// Created by 0864h on 2021-02-21.
//
#include<iostream>
using namespace std;
int T, n;
long long d[65][10];
int main()
{
    cin >> T;
    for(int i = 0; i <= 9; i++)
        d[1][i] = i + 1;
    // i번째 자리수에 j까지 올 수 있는 경우의 수
    for(int i = 2; i <= 64; i++)
    {
        d[i][0] = 1; // 0은 항상 0만 가능(1개)
        for(int j = 1; j <= 9; j++)
            d[i][j] = d[i - 1][j] + d[i][j - 1];
    }
    while(T--)
    {
        cin >> n;
        cout << d[n][9] << "\n";
    }
}
