//
// Created by salmon11 on 2020-07-27.
//
#include<iostream>
#include<queue>
#include<tuple>
#include<vector>
#include<climits>
using namespace std;
int map[51][51];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, M, ans = INT_MAX, Min = 0, count = 0, countv = 0;
queue<tuple<int, int, int>> q;
vector< vector<int> > check(51, vector<int>(51, INT_MAX));
vector< vector<int> > temp(51, vector<int>(51, INT_MAX));
vector<pair<int, int>> v;
vector<int> v2;
void spread(int a, int b)
{
    q.push({a, b, 0});
    check[a][b] = 0;
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
            if(nx >= 1 && ny >= 1 && nx <= N && ny <= N && map[nx][ny] != 1 && check[nx][ny] > nz)
            {
                check[nx][ny] = nz;
                q.push({nx, ny, nz});
            }
        }
    }
}
void virus(int idx, int c)
{
    if(c == M)
    {
        check = temp;
        Min = 0;
        countv = 0;
        for(int i = 0; i < v2.size(); i++)
            spread(v[v2[i]].first, v[v2[i]].second);
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(check[i][j] != INT_MAX)
                    countv++;
                if(check[i][j] != INT_MAX && map[i][j] != 2 && Min < check[i][j])
                    Min = check[i][j];
            }
        }
        if(countv == count && ans > Min)
            ans = Min;
        return;
    }
    for(int i = idx + 1; i < v.size(); i++)
    {
        v2.push_back(i);
        virus(i, c + 1);
        v2.pop_back();
    }
}
int main()
{
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> map[i][j];
            if(map[i][j] != 1)
                count++;
            if(map[i][j] == 2)
                v.emplace_back(i, j);
        }
    }
    virus(-1, 0);
    if(ans == INT_MAX)
    {
        cout << -1;
        return 0;
    }
    cout << ans;
}
