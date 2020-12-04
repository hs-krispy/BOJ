//
// Created by 0864h on 2020-12-04.
//
#include<cstdio>
#include<queue>
#include <cstdlib>
using namespace std;
int N, M, grid[1001][1001];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int>> q;
bool check[1001][1001];
void bfs(int a, int b)
{
    q.push({a, b});
    check[a][b] = true;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x == N)
        {
            printf("YES");
            exit(0);
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 1 && ny >= 1 && nx <= N && ny <= M && !check[nx][ny] && grid[nx][ny] == 0)
            {
                check[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}
int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
            scanf("%1d", &grid[i][j]);
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            if(grid[i][j] == 0 && i == 1)
                bfs(i, j);
        }
    }
    printf("NO");
}
