//
// Created by 0864h on 2020-06-12.
//
#include<cstdio>
#include<queue>
#include<tuple>
using namespace std;
int arr[3][100001];
int dy[] = {1, -1};
int n, k;
int bfs(int a, int b)
{
    queue<tuple<int, int, int>> q;
    q.push({a, b, 1});
    arr[a][b] = 0;
    while(!q.empty())
    {
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();
        for(int j : dy)
        {
            int nx = x;
            int ny = y + j;
            if(ny > n)
                return 1;
            if(ny > z && ny <= n && arr[nx][ny] == 1)
            {
                q.push({nx, ny, z + 1});
                arr[nx][ny] = 0;
            }
        }
        int nx = 0;
        if(x == 1)
            nx = 2;
        if(x == 2)
            nx = 1;
        int ny = y + k;
        if(ny > n)
            return 1;
        if(ny > z && ny <= n && arr[nx][ny] == 1)
        {
            q.push({nx, ny, z + 1});
            arr[nx][ny] = 0;
        }
    }
    return 0;
}
int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= 2; i++)
    {
        for(int j = 1; j <= n; j++)
            scanf("%1d", &arr[i][j]);
    }
    printf("%d", bfs(1, 1));
}
