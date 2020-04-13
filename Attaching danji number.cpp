//
// Created by 0864h on 2020-04-13.
//
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include <algorithm>
using namespace std;
int dx[] = {1, -1, 0, 0}; // 상 하 우 좌
int dy[] = {0, 0, 1, -1};
int d[25][25], c = 0, res[625];
bool check[25][25];
void bfs(int i, int j)
{
    int nx = 0, ny = 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    res[c]++;
    check[i][j] = true;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(i = 0; i < 4; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];
            if(!check[nx][ny] && d[nx][ny] == 1 && nx >= 0 && ny >= 0 && nx<25 && ny<25)
            {
                q.push({nx, ny});
                check[nx][ny] = true;
                res[c]++;
            }
        }
    }
    c++;
}
int main()
{
    int n, i, j;
    cin>>n;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            scanf("%1d", &d[i][j]);
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(!check[i][j] && d[i][j] == 1)
                bfs(i ,j);
        }
    }
    cout<<c<<"\n";
    sort(&res[0], &res[c]);
    for(i = 0; i < c; i++)
        cout<<res[i]<<"\n";
}
