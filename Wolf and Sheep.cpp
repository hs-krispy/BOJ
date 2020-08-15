//
// Created by 0864h on 2020-08-15.
//
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int R, C, ans = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char arr[501][501];
bool check[501][501], possible = true;
void bfs(int a, int b)
{
    check[a][b] = true;
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
            if(nx >= 1 && ny >= 1 && nx <= R && ny <= C && !check[nx][ny] && (arr[nx][ny] == '.' || arr[nx][ny] == 'S'))
            {
                if(arr[nx][ny] == '.')
                {
                    check[nx][ny] = true;
                    q.push({nx, ny});
                }
                if(arr[nx][ny] == 'S')
                {
                    if(arr[x][y] == 'W')
                    {
                        possible = false;
                        break;
                    }
                    arr[x][y] = 'D';
                }
            }
        }
        if(!possible)
            break;
    }
}
int main()
{
    cin >> R >> C;
    vector<pair<int, int>> v;
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 'W')
                v.emplace_back(i, j);
        }
    }
    for(int i = 0; i < v.size(); i++)
    {
        bfs(v[i].first, v[i].second);
        if(!possible)
        {
            cout << 0;
            return 0;
        }
    }
    cout << 1 << "\n";
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
            cout << arr[i][j];
        cout << "\n";
    }
}
