//
// Created by 0864h on 2020-09-26.
//
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int N, area[101][101];
bool check[101][101];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int>> q;
void bfs(int a, int b, int height)
{
    check[a][b] = true;
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
            if(nx >= 1 && ny >= 1 && nx <= N && ny <= N && area[nx][ny] > height && !check[nx][ny])
            {
                q.push({nx, ny});
                check[nx][ny] = true;
            }
        }
    }
}
int main()
{
    int Max = 0, ans = 1;
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> area[i][j];
            if(Max < area[i][j])
                Max = area[i][j];
        }
    }
    for(int i = 1; i < Max; i++)
    {
        int count = 0;
        memset(check, false, sizeof(check));
        for(int j = 1; j <= N; j++)
        {
            for(int k = 1; k <= N; k++)
            {
                if(!check[j][k] && area[j][k] > i)
                {
                    bfs(j, k, i);
                    count++;
                }
            }
        }
        if(ans < count)
            ans = count;
    }
    cout << ans;
}
