//
// Created by 0864h on 2020-05-30.
//
#include<cstdio>
#include<iostream>
#include<queue>
#include<tuple>
#include<climits>
#include <cstring>
using namespace std;
char arr[51][51];
bool check[51][51];
int r, c, d[51][51], water[51][51];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void move(int a, int b)
{
    queue<pair<int, int>> q;
    q.push({a, b});
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(arr[nx][ny] == '.' && nx >= 1 && ny >= 1 && nx <= r && ny <= c)
            {
                if(d[nx][ny] > d[x][y] + 1)
                {
                    d[nx][ny] = d[x][y] + 1;
                    if(d[nx][ny] >= water[nx][ny])
                        d[nx][ny] = INT_MAX - 1;
                    else
                        q.push({nx, ny});
                }
            }
            if(arr[nx][ny] == 'D')
            {
                cout << d[x][y] + 1;
                return;
            }
        }
    }
    cout << "KAKTUS";
}
void watermove(int a, int b)
{
    queue<tuple<int, int, int>> q;
    q.push({a, b, 0});
    int x, y, z;
    check[a][b] = true;
    while(!q.empty())
    {
        tie(x, y, z) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(arr[nx][ny] =='.' && !check[nx][ny] && nx >= 1 && ny >= 1 && nx <= r && ny <= c)
            {
                check[nx][ny] = true;
                q.push({nx, ny, z + 1});
                water[nx][ny] = min(water[nx][ny], z + 1);
            }
        }
    }
}
int main()
{
    scanf("%d %d", &r, &c);
    int x = 0, y = 0;
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            cin >> arr[i][j];
            d[i][j] = water[i][j] = INT_MAX;
            if(arr[i][j] == 'S')
            {
                d[i][j] = 0;
                x = i;
                y = j;
            }
        }
    }
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            if(arr[i][j] == '*')
            {
                watermove(i, j);
                memset(check, false, sizeof(check));
            }
        }
    }
    move(x, y);
}
