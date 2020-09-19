//
// Created by 0864h on 2020-09-19.
//
#include<iostream>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int M, N, H, box[101][101][101], ans[101][101][101], Max = 0, count = 0, check = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dz[] = {-1, 1};
queue<tuple<int, int, int>> q;
int main()
{
    cin >> M >> N >> H;
    for(int k = 1; k <= H; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= M; j++)
            {
                cin >> box[i][j][k];
                if(box[i][j][k] == 0)
                {
                    count++;
                    ans[i][j][k] = INT_MAX;
                }
                if(box[i][j][k] == 1)
                {
                    q.push({i, j, k});
                }
            }
        }
    }
    if(count == 0)
    {
        cout << 0;
        return 0;
    }
    while(!q.empty())
    {
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();
        for(int i = 0; i < 6; i++)
        {
            if(i < 4)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 1 && ny >= 1 && nx <= N && ny <= M && box[nx][ny][z] != -1 && ans[nx][ny][z] > ans[x][y][z] + 1)
                {
                    q.push({nx, ny, z});
                    ans[nx][ny][z] = ans[x][y][z] + 1;
                    if(Max < ans[nx][ny][z])
                        Max = ans[nx][ny][z];
                }
            }
            if(i >= 4)
            {
                int nz = z + dz[i - 4];
                if(nz >= 1 && nz <= H && box[x][y][nz] != -1 && ans[x][y][nz] > ans[x][y][z] + 1)
                {
                    q.push({x, y, nz});
                    ans[x][y][nz] = ans[x][y][z] + 1;
                    if(Max < ans[x][y][nz])
                        Max = ans[x][y][nz];
                }
            }
        }
    }
    for(int k = 1; k <= H; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= M; j++)
            {
                if(ans[i][j][k] == INT_MAX)
                {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << Max << "\n";
}