//
// Created by 0864h on 2021-02-18.
//
#include<iostream>
using namespace std;
int T, N, c, M, coin[21], d[10001];
int main()
{
    cin >> T;
    d[0] = 1;
    while(T--)
    {
        cin >> N;
        for(int i = 1; i <= N; i++)
        {
            cin >> c;
            coin[i] = c;
        }
        cin >> M;
        for(int i = 1; i <= N; i++)
        {
            for(int j = coin[i]; j <= M; j++)
            {
                d[j] += d[j - coin[i]];
            }
        }
        cout << d[M] << "\n";
        for(int i = 1; i <= M; i++)
            d[i] = 0;
    }
}
