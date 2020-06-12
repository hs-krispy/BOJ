//
// Created by 0864h on 2020-06-12.
//
#include<iostream>
using namespace std;
int n, m, Max = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int mx[4][3] = {{0, 1, 0}, {-1, 0, 1}, {0, -1, 0}, {-1, 0, 1}};
int my[4][3] = {{-1, 0, 1}, {0, 1, 0}, {-1, 0, 1}, {0, -1, 0}};
int arr[501][501];
bool check[501][501];
void dfs(int x, int y, int dep, int sum)
{
    if(dep == 4)
    {
        if(Max < sum)
            Max = sum;
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 1 && ny >= 1 && nx <= n && ny <= m && !check[nx][ny])
        {
            sum += arr[nx][ny];
            check[nx][ny] = true;
            dfs(nx, ny, dep + 1, sum);
            check[nx][ny] = false;
            sum -= arr[nx][ny];
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            cin >> arr[i][j];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            check[i][j] = true;
            dfs(i, j, 1, arr[i][j]);
            check[i][j] = false;
            for(int k = 0; k < 4; k++)
            {
                int sum = arr[i][j];
                for(int l = 0; l < 3; l++)
                {
                    int nx = i + mx[k][l];
                    int ny = j + my[k][l];
                    if(nx >= 1 && ny >= 1 && nx <= n && ny <= m)
                        sum += arr[nx][ny];
                    else break;
                }
                if(Max < sum)
                    Max = sum;
            }
        }
    }
    cout << Max;
}
