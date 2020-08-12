//
// Created by salmon11 on 2020-08-12.
//
#include<iostream>
#include<algorithm>
using namespace std;
int N;
long long d[1500001][3];
int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> d[i][1] >> d[i][2];
    for(int i = 1; i <= N; i++)
    {
        d[i][0] = max(d[i][0], d[i - 1][0]);
        if(i + d[i][1] - 1 <= N)
            d[i + d[i][1] - 1][0] = max(d[i + d[i][1] - 1][0], d[i - 1][0] + d[i][2]);
    }
    cout << d[N][0];
}
