//
// Created by 0864h on 2020-08-02.
//
#include<iostream>
#include<queue>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, M, arr[1001][1001], ans[1001][1001], group[1001][1001];
bool check[1001][1001], check2[1000001];
int Max = 0, c = 1;
int bfs(int a, int b)
{
    int count = 1;
    queue<pair<int, int>> q;
    queue<pair<int, int>> q2;
    q.push({a, b});
    check[a][b] = true;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 1 && ny >= 1 && nx <= N && ny <= M && arr[nx][ny] == 1 && !check[nx][ny])
            {
                group[nx][ny] = c;
                check[nx][ny] = true;
                q.push({nx, ny});
                q2.push({nx, ny});
                count++;
            }
        }
    }
    while(!q2.empty())
    {
        int x = q2.front().first;
        int y = q2.front().second;
        ans[x][y] = count;
        q2.pop();
    }
    c++;
    return count;
}
int main()
{
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
            cin >> arr[i][j];
    }
    int val = 0;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            if(arr[i][j] == 1)
            {
                if(!check[i][j])
                {
                    group[i][j] = c;
                    val = bfs(i, j);
                    ans[i][j] = val;
                }
            }
        }
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            if(arr[i][j] == 0)
            {
                val = 0;
                queue<int> q;
                for(int k = 0; k < 4; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x >= 1 && y >= 1 && x <= N && y <= M && arr[x][y] == 1 && !check2[group[x][y]])
                    {
                        check2[group[x][y]] = true;
                        q.push(group[x][y]);
                        val += ans[x][y];
                    }
                }
                while(!q.empty())
                {
                    check2[q.front()] = false;
                    q.pop();
                }
                if(Max < val)
                    Max = val;
            }
        }
    }
    cout << Max + 1;
}