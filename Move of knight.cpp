//
// Created by salmon11 on 2020-07-13.
//
#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
using namespace std;
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int t, n;
int main()
{
    cin >> t;
    int sx, sy, ex, ey;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        int count = 0;
        vector< vector<int> > move(n, vector<int> (n));
        vector< vector<bool> > check(n, vector<bool> (n));
        cin >> sx >> sy >> ex >> ey;
        queue<tuple<int, int, int>> q;
        q.push({sx, sy, 0});
        check[sx][sy] = true;
        while(!q.empty())
        {
            int x, y, z;
            tie(x, y, z) = q.front();
            q.pop();
            for(int j = 0; j < 8; j++)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];
                int nz = z + 1;
                if(nx >= 0 && ny >= 0 && nx < n && ny < n && !check[nx][ny])
                {
                    check[nx][ny] = true;
                    q.push({nx, ny, nz});
                    if(nx == ex && ny == ey)
                    {
                        count = nz;
                        break;
                    }
                }
            }
        }
        cout << count << "\n";
    }
}
