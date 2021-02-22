//
// Created by 0864h on 2021-02-22.
//
#include<iostream>
#include<vector>
#include<tuple>
#include <algorithm>

using namespace std;
int N, K, S, X, Y, arr[201][201];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<tuple<int, int, int>> v;
void bfs()
{
    int end = v.size();
    while(end--)
    {
        int num, x, y;
        tie(num, x, y) = v.front();
        v.erase(v.begin());
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 1 && ny >= 1 && nx <= N && ny <= N && arr[nx][ny] == 0)
            {
                arr[nx][ny] = num;
                v.emplace_back(num, nx, ny);
            }
        }
    }
    sort(v.begin(), v.end());
}
int main()
{
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] != 0)
                v.emplace_back(arr[i][j], i, j);
        }
    }
    sort(v.begin(), v.end());
    cin >> S >> X >> Y;
    int count = 0;
    while(count < S)
    {
        bfs();
        count++;
    }
    cout << arr[X][Y];
}
