//
// Created by 0864h on 2020-05-25.
//
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m, arr[1001][1001], count = 0, ans = 0;
queue<tuple<int, int, int>> q;
void bfs()
{
    int check = 0;
    int x, y, z = 0;
    while(!q.empty())
    {
        tie(x, y, z) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (arr[nx][ny] == 0 && nx >= 1 && ny >= 1 && nx <= m && ny <= n)
            {
                q.push({nx, ny, z + 1});
                arr[nx][ny] = 1;
                check++;
            }
        }
    }
    ans = z;
    if(count != check)
        ans = -1;
}
int main()
{
    bool all = false;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 0)
            {
                all = true;
                count++;
            }
            else if(arr[i][j] == 1)
                q.push({i, j, 0});
        }
    }
    if(!all)
        cout << 0;
    else
    {
        bfs();
        cout << ans;
    }
}
