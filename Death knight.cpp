//
// Created by 0864h on 2020-07-15.
//
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};
bool check[200][200];
int n;
int main()
{
    cin >> n;
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int count = 0;
    queue<tuple<int, int, int>> q;
    q.push({r1, c1, 0});
    check[r1][c1] = true;
    while(!q.empty())
    {
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();
        for(int j = 0; j < 6; j++)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];
            int nz = z + 1;
            if(nx >= 0 && ny >= 0 && nx < n && ny < n && !check[nx][ny])
            {
                check[nx][ny] = true;
                q.push({nx, ny, nz});
                if(nx == r2 && ny == c2)
                {
                    count = nz;
                    break;
                }
            }
        }
    }
    if(count == 0)
    {
        cout << -1;
        return 0;
    }
    cout << count << "\n";
}
