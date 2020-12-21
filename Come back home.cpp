//
// Created by 0864h on 2020-12-22.
//
#include<iostream>
using namespace std;

int R, C, K, ans = 0;
char map[6][6];
bool check[6][6];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void go(int x, int y, int count)
{
    if(x == 1 && y == C)
    {
        if(count == K)
            ans++;
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 1 && ny >= 1 && nx <= R && ny <= C && !check[nx][ny] && map[nx][ny] != 'T')
        {
            check[nx][ny] = true;
            go(nx, ny, count + 1);
            check[nx][ny] = false;
        }
    }
}
int main()
{
    cin >> R >> C >> K;
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
            cin >> map[i][j];
    }
    check[R][1] = true;
    go(R, 1, 1);
    cout << ans;
}
