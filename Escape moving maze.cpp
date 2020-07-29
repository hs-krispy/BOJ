//
// Created by salmon11 on 2020-07-29.
//
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
char maze[9][9];
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1, 0};
int main()
{
    vector<pair<int, int>> v;
    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            cin >> maze[i][j];
            if(maze[i][j] == '#')
                v.emplace_back(i, j);
        }
    }
    if(v.empty())
    {
        cout << 1;
        return 0;
    }
    queue<tuple<int, int, int>> q;
    q.push({8, 1, 0});
    int time = 0;
    while(!q.empty())
    {
        int x, y, z;
        tie(x, y, z)  = q.front();
        q.pop();
        if(time < z)
        {
            time = z;
            for(int i = 0; i < v.size(); i++)
            {
                if(v[i].first <= 8)
                {
                    maze[v[i].first][v[i].second] = '.';
                    v[i].first += 1;
                    if(v[i].first <= 8)
                        maze[v[i].first][v[i].second] = '#';
                }
            }
            for(int i = 0; i < v.size(); i++)
            {
                if(v[i].first <= 8)
                {
                    maze[v[i].first][v[i].second] = '#';
                }
            }
        }
        if(maze[x][y] == '#')
            continue;
        if((v[0].first > x) || (x == 1 && y == 8))
        {
            cout << 1;
            return 0;
        }
        for(int i = 0; i < 9; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + 1;
            if(nx >= 1 && ny >= 1 && nx <= 8 && ny <= 8 && maze[nx][ny] != '#')
                q.push({nx, ny, nz});
        }
    }
    cout << 0;
}
