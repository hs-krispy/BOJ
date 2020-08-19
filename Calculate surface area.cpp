//
// Created by 0864h on 2020-08-20.
//
#include<iostream>
using namespace std;
int N, M, square[101][101];
int main()
{
    int surface = 0;
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
            cin >> square[i][j];
    }
    surface += N * M * 2;
    for(int i = 1; i <= N; i++)
    {
        surface += square[i][1];
        for(int j = 2; j <= M; j++)
        {
            surface += abs(square[i][j - 1] - square[i][j]);
        }
        surface += square[i][M];
    }
    for(int i = 1; i <= M; i++)
    {
        surface += square[1][i];
        for(int j = 2; j <= N; j++)
        {
            surface += abs(square[j - 1][i] - square[j][i]);
        }
        surface += square[N][i];
    }
    cout << surface;
}
