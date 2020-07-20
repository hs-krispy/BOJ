//
// Created by 0864h on 2020-07-19.
//
#include<iostream>
#include<queue>
#include<tuple>
#include<vector>
using namespace std;
int Ux[] = {0, -1, 0, 1};
int Uy[] = {1, 0, -1, 0};
int Dx[] = {0, 1, 0, -1};
int Dy[] = {1, 0, -1, 0};
int R, C, T, count = 0, sum = 0;
vector< vector<int> > room(51, vector<int> (51));
vector< vector<int> > temproom(51, vector<int> (51));
vector<pair<int, int>> v;
queue<tuple<int, int, int>> q;
queue<pair<int, int>> uq;
queue<pair<int, int>> dq;
void spread();
void clean(int c)
{
    uq.push({v[0].first, v[0].second + 1});
    dq.push({v[1].first, v[1].second + 1});
    room[v[0].first][v[0].second + 1] = 0;
    room[v[1].first][v[1].second + 1] = 0;
    while (!uq.empty()) {
        int ux = uq.front().first, uy = uq.front().second;
        uq.pop();
        if (ux >= 1 && uy >= 1 && ux <= v[0].first && uy <= C) {
            if (ux == v[0].first && uy < C) {
                int nux = ux + Ux[0];
                int nuy = uy + Uy[0];
                uq.push({nux, nuy});
                room[nux][nuy] = temproom[ux][uy];
            }
            if (ux > 1 && uy == C) {
                int nux = ux + Ux[1];
                int nuy = uy + Uy[1];
                uq.push({nux, nuy});
                room[nux][nuy] = temproom[ux][uy];
            }
            if (ux == 1 && uy > 1) {
                int nux = ux + Ux[2];
                int nuy = uy + Uy[2];
                uq.push({nux, nuy});
                room[nux][nuy] = temproom[ux][uy];
            }
            if (ux < v[0].first - 1 && uy == 1) {
                int nux = ux + Ux[3];
                int nuy = uy + Uy[3];
                uq.push({nux, nuy});
                room[nux][nuy] = temproom[ux][uy];
            }
        }
    }
    while (!dq.empty()) {
            int dx = dq.front().first, dy = dq.front().second;
            dq.pop();
            if (dx >= v[1].first && dy >= 1 && dx <= R && dy <= C) {
                if (dx == v[1].first && dy < C) {
                    int ndx = dx + Dx[0];
                    int ndy = dy + Dy[0];
                    dq.push({ndx, ndy});
                    room[ndx][ndy] = temproom[dx][dy];
                }
                if (dx < R && dy == C) {
                    int ndx = dx + Dx[1];
                    int ndy = dy + Dy[1];
                    dq.push({ndx, ndy});
                    room[ndx][ndy] = temproom[dx][dy];
                }
                if (dx == R && dy > 1) {
                    int ndx = dx + Dx[2];
                    int ndy = dy + Dy[2];
                    dq.push({ndx, ndy});
                    room[ndx][ndy] = temproom[dx][dy];
                }
                if (dx > v[1].first + 1 && dy == 1) {
                    int ndx = dx + Dx[3];
                    int ndy = dy + Dy[3];
                    dq.push({ndx, ndy});
                    room[ndx][ndy] = temproom[dx][dy];
                }
            }
    }
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            if(room[i][j] >= 5)
                q.push({i, j, c});
        }
    }
    if(count < T)
    {
        temproom = room;
        count++;
        spread();
    }
}
void spread()
{
    if(count == T)
        return;
    while(!q.empty())
    {
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + Dx[i];
            int ny = y + Dy[i];
            int nz = z + 1;
            if(nx >= 1 && ny >= 1 && nx <= R && ny <= C && room[nx][ny] != -1 && nz <= T)
            {
                room[x][y] -= temproom[x][y] / 5;
                room[nx][ny] += temproom[x][y] / 5;
            }
        }
    }
    temproom = room;
    clean(count);
}
int main()
{
    cin >> R >> C >> T;
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            cin >> room[i][j];
            temproom[i][j] = room[i][j];
            if(room[i][j] == -1)
                v.emplace_back(i, j);
            if(room[i][j] >= 5)
                q.push({i, j, 0});
        }
    }
    spread();
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
            if(room[i][j] > 0)
                sum += room[i][j];
    }
    cout << sum;
}
