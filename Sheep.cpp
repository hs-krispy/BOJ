//
// Created by 0864h on 2020-06-11.
//
#include<iostream>
#include<queue>
using namespace std;
int r, c;
int wolf = 0;
int sheep = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char arr[251][251];
bool check[251][251];
void bfs(int a, int b)
{
    queue<pair<int, int>> q;
    q.push({a, b});
    check[a][b] = true;
    int w = 0;
    int s = 1;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 1 && ny >= 1 && nx <= r && ny <= c && !check[nx][ny] && arr[nx][ny] != '#')
            {
                if(arr[nx][ny] == 'v')
                    w++;
                if(arr[nx][ny] == 'o')
                    s++;
                check[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    if(w >= s)
        sheep -= s;
    else wolf -= w;
}
int main()
{
    cin >> r >> c;
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 'o')
                sheep++;
            if(arr[i][j] == 'v')
                wolf++;
        }
    }
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            if(!check[i][j] && arr[i][j] == 'o')
                bfs(i, j);
        }
    }
    cout << sheep << " " << wolf << "\n";
}
