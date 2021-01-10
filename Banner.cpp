//
// Created by 0864h on 2021-01-10.
//
#include<iostream>
#include<queue>
using namespace std;
int N, M, grid[251][251];
int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, -1, 1, 1};
bool check[251][251];
queue<pair<int, int>> q;
void bfs(int a, int b)
{
    check[a][b] = true;
    q.push({a, b});
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 1 && ny >= 1 && nx <= M && ny <= N && !check[nx][ny] && grid[nx][ny] == 1)
            {
                check[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}
int main()
{
    cin >> M >> N;
    int count = 0;
    for(int i = 1; i <= M; i++)
    {
        for(int j = 1; j <= N; j++)
            cin >> grid[i][j];
    }
    for(int i = 1; i <= M; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(!check[i][j] && grid[i][j] == 1)
            {
                count++;
                bfs(i, j);
            }
        }
    }
    cout << count;
}
