//
// Created by 0864h on 2021-02-18.
//
#include<iostream>
using namespace std;
int N, M, num, seat[41], d[41];
int main()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> num;
        seat[num] = 1;
    }
    int ans = 1, count = 0;
    d[0] = d[1] = 1;
    for(int i = 2; i <= 40; i++)
        d[i] = d[i - 1] + d[i - 2];
    for(int i = 1; i <= N; i++)
    {
        count++;
        if(seat[i] == 1)
        {
            ans *= d[count - 1];
            count = 0;
        }
    }
    ans *= d[count];
    cout << ans;
}