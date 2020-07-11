//
// Created by 0864h on 2020-07-11.
//
#include<iostream>
using namespace std;
int main()
{
    int N, S, M, V[101], Max = -1;
    bool d[101][1001];
    cin >> N >> S >> M;
    for(int i = 1; i <= N; i++)
        cin >> V[i];
    d[0][S] = true;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j <= M; j++)
        {
            if(d[i][j])
            {
                if(j - V[i + 1] >= 0)
                    d[i + 1][j - V[i + 1]] = true;
                if(j + V[i + 1] <= M)
                    d[i + 1][j + V[i + 1]] = true;
            }
        }
    }
    for(int i = 0; i <= M; i++)
        if(d[N][i]) Max = i;
    cout << Max;
}
