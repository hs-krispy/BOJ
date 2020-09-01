//
// Created by 0864h on 2020-09-01.
//
#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, 1, -1};
int N, M, space[51][51], ans[51][51], Max = 0;
vector<pair<int, int>> v;
int main()
{
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            cin >> space[i][j];
            ans[i][j] = INT_MAX;
            if(space[i][j] == 1)
            {
                v.emplace_back(i, j);
                ans[i][j] = 0;
            }
        }
    }
    queue<pair<int, int>> q;
    for(int i = 0; i < v.size(); i++)
    {
        q.push({v[i].first, v[i].second});
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0; i < 8; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 1 && ny >= 1 && nx <= N && ny <= M && space[nx][ny] == 0 && ans[nx][ny] > ans[x][y] + 1)
                {
                    ans[nx][ny] = ans[x][y] + 1;
                    q.push({nx, ny});

                }
            }
        }
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            if(Max < ans[i][j])
                Max = ans[i][j];
        }
    }
    cout << Max;
}
