//
// Created by 0864h on 2020-08-13.
//
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
int N, house[17][17], count = 0;
int dx[] = {0, 1, 1};
int dy[] = {1, 1, 0};
int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
            cin >> house[i][j];
    }
    queue<tuple<int, int, int>> q;
    q.push({1, 2, 1});
    while(!q.empty())
    {
        int x, y, z;
        tie(x, y, z) = q.front();
        if(x == N && y == N)
            count++;
        q.pop();
        for(int i = 0; i < 3; i++)
        {
            if(z == 1 && i == 2) continue;
            if(z == 3 && i == 0) continue;
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx <= N && ny <= N && house[nx][ny] == 0)
            {
                if(i == 1 && !(house[nx - 1][ny] == 0 && house[nx][ny - 1] == 0))
                    continue;
                q.push({nx, ny, i + 1});
            }
        }
    }
    cout << count;
}
