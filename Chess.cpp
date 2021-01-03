//
// Created by 0864h on 2020-09-30.
//
#include<iostream>
#include<vector>
using namespace std;
int n, m, q, k, p, count = 0;
int qx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int qy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int kx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int ky[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int check[1001][1001];
vector<pair<int, int>> v[2];
void queen(int x, int y, int dir)
{
    int nx = x + qx[dir];
    int ny = y + qy[dir];
    if(nx >= 1 && ny >= 1 && nx <= n && ny <= m && check[nx][ny] != -1)
    {
        if(check[nx][ny] == 0)
        {
            check[nx][ny] = 1;
            count++;
        }
        queen(nx, ny, dir);
    }
}
void knight(int x, int y)
{
    for(int i = 0; i < 8; i++)
    {
        int nx = x + kx[i];
        int ny = y + ky[i];
        if(nx >= 1 && ny >= 1 && nx <= n && ny <= m && check[nx][ny] != -1)
        {
            if(check[nx][ny] == 0)
            {
                check[nx][ny] = 1;
                count++;
            }
        }
    }
}
int main()
{
    int x, y;
    cin >> n >> m;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        cin >> x >> y;
        check[x][y] = -1;
        count++;
        v[0].emplace_back(x, y);
    }
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> x >> y;
        check[x][y] = -1;
        count++;
        v[1].emplace_back(x, y);
    }
    cin >> p;
    for(int i = 0; i < p; i++)
    {
        cin >> x >> y;
        check[x][y] = -1;
        count++;
    }
    for(int i = 0; i < v[0].size(); i++)
    {
        for(int j = 0; j < 8; j++)
            queen(v[0][i].first, v[0][i].second, j);
    }
    for(int i = 0; i < v[1].size(); i++)
    {
        for(int j = 0; j < 8; j++)
            knight(v[1][i].first, v[1][i].second);
    }
    cout << n * m - count;
}
