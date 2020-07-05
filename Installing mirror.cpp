//
// Created by 0864h on 2020-06-22.
//
#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char house[51][51];
int n, ans[51][51][4], Min = INT_MAX;
int main() {
    cin >> n;
    int cx = 0, cy = 0, cx2 = 0, cy2 = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf(" %1c", &house[i][j]);
            ans[i][j][0] = ans[i][j][1] = ans[i][j][2] = ans[i][j][3] = INT_MAX;
            if (house[i][j] == '#') {
                if (cx == 0 && cy == 0) {
                    ans[i][j][0] = ans[i][j][1] = ans[i][j][2] = ans[i][j][3] = 0;
                    cx = i;
                    cy = j;
                } else {
                    cx2 = i;
                    cy2 = j;
                }
            }
        }
    }
    queue<pair<pair<int, int>, pair<int, int>>> q;
    for (int i = 0; i < 4; i++) {
        q.push({{cx, cy}, {i, 0}});
    }
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second.first;
        int c = q.front().second.second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nc = c;
            if (nx >= 1 && ny >= 1 && nx <= n && ny <= n && house[nx][ny] != '*') {
                if (z == i && nx == cx2 && ny == cy2 && ans[cx2][cy2][i] > c)
                {
                    ans[cx2][cy2][i] = c;
                    if(Min > ans[cx2][cy2][i])
                        Min = ans[cx2][cy2][i];
                }
                else if(house[x][y] == '!' && z != i && nx == cx2 && ny == cy2 && ans[cx2][cy2][i] > c + 1)
                {
                    ans[cx2][cy2][i] = c + 1;
                    if(Min > ans[cx2][cy2][i])
                        Min = ans[cx2][cy2][i];
                }
                if (z == i && ans[nx][ny][i] > nc && Min > nc) {
                    ans[nx][ny][i] = nc;
                    q.push({{nx, ny}, {i, c}});
                }
                if (house[x][y] == '!' && z != i && ans[nx][ny][i] > nc && Min > nc) {
                    nc++;
                    ans[nx][ny][i] = nc;
                    q.push({{nx, ny}, {i, nc}});
                }
            }
        }
    }
    printf("%d", Min);
}

