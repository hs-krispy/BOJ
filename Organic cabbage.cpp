//
// Created by 0864h on 2020-10-15.
//
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int T, M, N, K;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int field[50][50], X, Y;
bool check[50][50];
void bfs(int a, int b)
{
    queue<pair<int, int>> q;
    check[a][b] = true;
    q.push({a, b});
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx <= M - 1 && ny <= N - 1 && field[nx][ny] == 1 && !check[nx][ny])
            {
                check[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}
int main()
{
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        vector<pair<int, int>> v;
        int count = 0;
        scanf("%d %d %d", &M, &N, &K);
        for(int j = 0; j < K; j++)
        {
            scanf("%d %d", &X, &Y);
            v.emplace_back(X, Y);
            field[X][Y] = 1;
        }
        for(int j = 0; j < v.size(); j++)
        {
            int x = v[j].first;
            int y = v[j].second;
            if(field[x][y] == 1 && !check[x][y])
            {
                count++;
                bfs(x, y);
            }
        }
        printf("%d\n", count);
        memset(field, 0, sizeof(field));
        memset(check, false, sizeof(check));
    }
}
