//
// Created by 0864h on 2020-06-14.
//
#include<iostream>
using namespace std;
char arr[21][21];
bool check[21][21], upper[27];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int r, c, Max = 0;
void dfs(int x, int y, int count)
{
    bool move = false;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 1 && ny >= 1 && nx <= r && ny <= c && !check[nx][ny] && !upper[arr[nx][ny] - 64])
        {
            move = true;
            check[nx][ny] = true;
            upper[arr[nx][ny] - 64] = true;
            dfs(nx, ny, count + 1);
            check[nx][ny] = false;
            upper[arr[nx][ny] - 64] = false;
        }
    }
    if(!move)
    {
        if(Max < count)
            Max = count;
    }
}
int main()
{
    cin >> r >> c;
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
            cin >> arr[i][j];
    }
    check[1][1] = true;
    upper[arr[1][1] - 64] = true;
    dfs(1, 1, 1);
    cout << Max;
}
