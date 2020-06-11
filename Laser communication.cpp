//
// Created by 0864h on 2020-06-09.
//
#include<iostream>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char map[101][101];
int w, h, ans[101][101];
int main()
{
    cin >> w >> h;
    int cx = 0, cy = 0, cx2 = 0, cy2 = 0;
    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            cin >> map[i][j];
            ans[i][j] = INT_MAX;
            if(map[i][j] == 'C')
            {
                if(cx == 0 && cy == 0)
                {
                    ans[i][j] = 0;
                    cx = i;
                    cy = j;
                }
                else{
                    cx2 = i;
                    cy2 = j;
                }
            }
        }
    }
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{cx, cy}, {-1, 0}});
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second.first;
        int c = q.front().second.second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nc = c;
            if(nx >= 1 && ny >= 1 && nx <= h && ny <= w && map[nx][ny] != '*')
            {
                if(z != i)
                    nc = c + 1;
                if(ans[nx][ny] >= nc)
                {
                    ans[nx][ny] = nc;
                    q.push({{nx, ny}, {i, nc}});
                }
            }
        }
    }
    cout << ans[cx2][cy2] - 1;
}
