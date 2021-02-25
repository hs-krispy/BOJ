//
// Created by 0864h on 2021-02-25.
//
#include<cstdio>
#include<queue>
using namespace std;
int n, room[51][51], change[51][51];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void bfs(int a, int b)
{
    queue<pair<int, int>> q;
    q.push({a, b});
    change[a][b] = 0;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 1 && ny >= 1 && nx <= n && ny <= n)
            {
                if(room[nx][ny] == 1 && change[nx][ny] > change[x][y])
                {
                    change[nx][ny] = change[x][y];
                    q.push({nx, ny});
                }
                else if(room[nx][ny] == 0 && change[nx][ny] > change[x][y] + 1)
                {
                    change[nx][ny] = change[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%1d", &room[i][j]);
            change[i][j] = 2501;
        }
    }
    bfs(1, 1);
    printf("%d", change[n][n]);
}
