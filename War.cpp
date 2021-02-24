//
// Created by 0864h on 2021-02-25.
//
#include<iostream>
#include<queue>
using namespace std;
int N, M, ans[2];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char bg[101][101];
bool check[101][101];
queue<pair<int, int>> q;
int bfs(int a, int b, char c)
{
    int count = 0;
    q.push({a, b});
    check[a][b] = true;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        count++;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 1 && ny >= 1 && nx <= M && ny <= N && !check[nx][ny] && bg[nx][ny] == c)
            {
                check[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return count;
}
int main()
{
    cin >> N >> M;
    int count;
    for(int i = 1; i <= M; i++)
    {
        for(int j = 1; j <= N; j++)
            cin >> bg[i][j];
    }
    for(int i = 1; i <= M; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(!check[i][j] && bg[i][j] == 'W')
            {
                count = bfs(i, j, 'W');
                ans[0] += count * count;
            }
            if(!check[i][j] && bg[i][j] == 'B')
            {
                count = bfs(i, j, 'B');
                ans[1] += count * count;
            }
        }
    }
    cout << ans[0] << " " << ans[1];
}
