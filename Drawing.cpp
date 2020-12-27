//
// Created by 0864h on 2020-12-27.
//
#include <iostream>
#include <queue>
using namespace std;

int n, m, paper[501][501], Max = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool check[501][501];
queue<pair<int, int>> q;
void bfs(int a, int b)
{
    int count = 0;
    q.push({a, b});
    check[a][b] = true;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 1 && ny >= 1 && nx <= n && ny <= m && !check[nx][ny] && paper[nx][ny] == 1)
            {
                check[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        count++;
    }
    if(Max < count)
        Max = count;
}
int main()
{
    int count = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            cin >> paper[i][j];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(!check[i][j] && paper[i][j] == 1)
            {
                count++;
                bfs(i, j);
            }
        }
    }
    cout << count << "\n" << Max;
}
