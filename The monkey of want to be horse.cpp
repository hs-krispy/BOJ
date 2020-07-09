//
// Created by 0864h on 2020-07-05.
//
#include<iostream>
#include<queue>
#include<climits>
using namespace std;
int dx[] = {-1, 1, 0, 0, -1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {0, 0, -1, 1, -2, -1, 1, 2, 2, 1, -1, -2};
int grid[201][201], ans[201][201][31];
int k, w, h;
int main()
{
    int Min = INT_MAX;
    cin >> k >> w >> h;
    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            cin >> grid[i][j];
            for(int l = 0; l <= k; l++)
            {
                if(!(i == 1 && j == 1))
                    ans[i][j][l] = INT_MAX;
            }
        }
    }
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{1, 1}, {0, 0}});
    q.push({{1, 1}, {0, 0}});
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second.first;
        int c = q.front().second.second;
        if(x == h && y == w)
        {
            if(Min > z)
                Min = z;
        }
        q.pop();
        for(int i = 0; i < 12; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + 1;
            int nc = c;
            if(nx >= 1 && ny >= 1 && nx <= h && ny <= w && grid[nx][ny] == 0)
            {
                if(i < 4)
                {
                    if(nc <= k && ans[nx][ny][nc] > nz)
                    {
                        ans[nx][ny][nc] = nz;
                        q.push({{nx, ny}, {nz, nc}});
                    }
                }
                if(i >= 4)
                {
                    nc = c + 1;
                    if(nc <= k && ans[nx][ny][nc] > nz)
                    {
                        ans[nx][ny][nc] = nz;
                        q.push({{nx, ny}, {nz, nc}});
                    }
                }
            }
        }
    }
    if(Min == INT_MAX)
    {
        cout << -1;
        return 0;
    }
    cout << Min;
}
