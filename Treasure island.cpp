//
// Created by 0864h on 2020-09-30.
//
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;
int n, m, Max = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<tuple<int, int, int>> q;
vector<pair<int, int>> v;
char map[51][51];
bool check[51][51];
void move(int a, int b)
{
    q.push({a, b, 0});
    check[a][b] = true;
    while(!q.empty())
    {
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + 1;
            if(nx >= 1 && ny >= 1 && nx <= n && ny <= m && !check[nx][ny] && map[nx][ny] == 'L')
            {
                check[nx][ny] = true;
                q.push({nx, ny, nz});
                if(Max < nz)
                    Max = nz;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 'L')
                v.emplace_back(i, j);
        }
    }
    for(int i = 0; i < v.size(); i++)
    {
        move(v[i].first, v[i].second);
        memset(check, false, sizeof(check));
    }
    cout << Max;
}
