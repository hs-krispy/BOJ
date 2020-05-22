#include<iostream>
#include<cstdio>
#include<climits>
#include<queue>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int arr[101][101];
int d[101][101];
int n, m, Max = INT_MAX;
void bfs(int a, int b)
{
    queue<pair<int, int>> q;
    q.push({a, b});
    d[a][b] = 0;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 1 && ny >= 1 && nx <= m && ny <= n)
            {
                if(arr[nx][ny] == 1)
                {
                    if(d[nx][ny] > d[x][y] + 1)
                    {
                        d[nx][ny] = d[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
                else
                {
                    if(d[nx][ny] > d[x][y])
                    {
                        d[nx][ny] = d[x][y];
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%1d", &arr[i][j]);
            d[i][j] = Max;
        }
    }
    bfs(1, 1);
    cout << d[m][n];
}
