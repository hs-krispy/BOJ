//
// Created by 0864h on 2020-07-02.
//
#include<iostream>
using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int arr[51][51];
int n, m, r, c, d, count = 0;
int main()
{
    cin >> n >> m >> r >> c >> d;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    int x = r, y = c, dir = d;
    while(true)
    {
        if(x >= 0 && y >= 0 && x < n && y < m)
        {
            if(arr[x][y] == 0)
            {
                arr[x][y] = 2;
                count++;
            }
            if (arr[x + 1][y] != 0 && arr[x - 1][y] != 0 && arr[x][y - 1] != 0 && arr[x][y + 1] != 0) {
                if (arr[x - dx[dir]][y - dy[dir]] == 1)
                    break;
                else {
                    x -= dx[dir];
                    y -= dy[dir];
                }
            } else {
                dir = (dir + 3) % 4;
                if (arr[x + dx[dir]][y + dy[dir]] == 0) {
                    x += dx[dir];
                    y += dy[dir];
                }
            }
        }
    }
    cout << count;
}
