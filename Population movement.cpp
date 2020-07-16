//
// Created by salmon11 on 2020-07-16.
//
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int N, L, R, A[51][51];
bool check[51][51][4], check2[51][51];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void bfs(int a, int b)
{
    queue<pair<int, int>> q;
    queue<pair<int, int>> res;
    q.push({a, b});
    res.push({a, b});
    check2[a][b] = true;
    int sum = A[a][b], count = 1;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 1 && ny >= 1 && nx <= N && ny <= N)
            {
                if(check[x][y][i] && !check2[nx][ny])
                {
                    sum += A[nx][ny];
                    count++;
                    check2[nx][ny] = true;
                    q.push({nx, ny});
                    res.push({nx, ny});
                }
            }
        }
    }
    while(!res.empty())
    {
        int x = res.front().first;
        int y = res.front().second;
        res.pop();
        A[x][y] = sum / count;
    }
}
void border(int ans)
{
    bool c = false;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni >= 1 && nj >= 1 && ni <= N && nj <= N)
                {
                    if(abs(A[i][j] - A[ni][nj]) >= L && abs(A[i][j] - A[ni][nj]) <= R)
                    {
                        check[i][j][k] = true;
                        c = true;
                    }
                }
            }
        }
    }
    if(!c)
    {
        cout << ans;
        return;
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(!check2[i][j])
                bfs(i, j);
        }
    }
    memset(check2, false, sizeof(check2));
    memset(check, false, sizeof(check));
    border(ans + 1);
}
int main()
{
    cin >> N >> L >> R;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
            cin >> A[i][j];
    }
    border(0);
}
