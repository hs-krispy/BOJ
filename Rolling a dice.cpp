//
// Created by 0864h on 2020-07-02.
//
#include<iostream>
using namespace std;
int map[20][20], dice[7], order[1000];
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};
int n, m, x, y, k;
int main()
{
    cin >> n >> m >> x >> y >> k;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> map[i][j];
    }
    for(int i = 0; i < k; i++)
        cin >> order[i];
    for(int i = 0; i < k; i++)
    {
        x += dx[order[i]];
        y += dy[order[i]];
        if(x >= 0 && y >= 0 && x < n && y < m)
        {
            if(order[i] == 1)
            {
                int temp = dice[1];
                dice[1] = dice[3];
                dice[3] = dice[6];
                dice[6] = dice[4];
                dice[4] = temp;
            }
            if(order[i] == 2)
            {
                int temp = dice[1];
                dice[1] = dice[4];
                dice[4] = dice[6];
                dice[6] = dice[3];
                dice[3] = temp;
            }
            if(order[i] == 3)
            {
                int temp = dice[1];
                dice[1] = dice[2];
                dice[2] = dice[6];
                dice[6] = dice[5];
                dice[5] = temp;
            }
            if(order[i] == 4)
            {
                int temp = dice[1];
                dice[1] = dice[5];
                dice[5] = dice[6];
                dice[6] = dice[2];
                dice[2] = temp;
            }
            if(map[x][y] == 0)
                map[x][y] = dice[1];
            else if(map[x][y] != 0)
            {
                dice[1] = map[x][y];
                map[x][y] = 0;
            }
            cout << dice[6];
            if(i < k - 1)
                cout << "\n";
        } else{
            x -= dx[order[i]];
            y -= dy[order[i]];
        }
    }
}