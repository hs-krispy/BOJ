//
// Created by 0864h on 2020-05-30.
//
#include<cstdio>
#include<queue>
#include<climits>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m, arr[101][101], d[101][101];
void searching(int a, int b)
{
    queue<pair<int, int>> q;
    q.push({a, b});
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(arr[nx][ny] == 1 && nx >= 1 && ny >= 1 && nx <= n && ny <=  m)
            {
                if(d[nx][ny] > d[x][y] + 1)
                {
                    d[nx][ny] = d[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    printf("%d", d[n][m]);
}
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf("%1d", &arr[i][j]);
            d[i][j] = INT_MAX;
        }
    }
    d[1][1] = 1;
    searching(1, 1);
}
