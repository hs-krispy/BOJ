//
// Created by 0864h on 2020-08-18.
//
#include<cstdio>
#include<queue>
#include<climits>
#include <tuple>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int arr[1001][1001];
int ans[1001][1001][11];
int n, m, k, Min = INT_MAX;
void bfs(int a, int b)
{
    queue<tuple<int, int, int>> q;
    q.push({a, b, k});
    ans[a][b][k] = 1; // 1은 벽 부수기 사용가능한 경우
    while(!q.empty())
    {
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 1 && ny >= 1 && nx <= n && ny <= m)
            {
                if(arr[nx][ny] == 1 && z > 0 && ans[nx][ny][z - 1] == 0) // 벽이 있고 아직 벽을 부술 횟수가 남아있고 방문안했던 곳
                {
                    ans[nx][ny][z - 1] = ans[x][y][z] + 1;
                    q.push({nx, ny, z - 1});
                }
                else if(arr[nx][ny] == 0 && ans[nx][ny][z] == 0) // 벽이 없고 방문안했던 곳
                {
                    ans[nx][ny][z] = ans[x][y][z] + 1;
                    q.push({nx, ny, z});
                }
            }
        }
    }
    for(int i = 0; i <= k; i++)
    {
        if(ans[n][m][i] != 0 && Min > ans[n][m][i])
            Min = ans[n][m][i];
    }
}
int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }
    bfs(1, 1);
    if(Min == INT_MAX)
    {
        printf("-1");
        return 0;
    }
    printf("%d", Min);
}

