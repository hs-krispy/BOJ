//
// Created by 0864h on 2020-05-14.
//
#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int dx[] = {-1, 1, 0, 0};//상 하 좌 우
int dy[] = {0, 0, -1, 1};
char board[22][22];
int n, m, Min = INT_MAX;
void bfs(int x, int y, int x2, int y2, int count, vector<vector<bool>> check, vector<vector<bool>> check2)
{
    check[x][y] = true;
    check2[x2][y2] = true;
    for(int i = 0; i < 4; i++)
    {
        int nx, ny, nx2, ny2;
        nx = x + dx[i];
        ny = y + dy[i];
        nx2 = x2 + dx[i];
        ny2 = y2 + dy[i];
        if(board[nx][ny] == '#')
        {
            nx = x;
            ny = y;
        }
        if(board[nx2][ny2] == '#')
        {
            nx2 = x2;
            ny2 = y2;
        }
        if(count >= Min) // 현재 최소 이동횟수보다 카운트가 크거나 같으면 리턴
            return;
        if(nx == nx2 && ny == ny2) // 두 동전의 위치가 같으면 체크 X
            continue;
        if(check[nx][ny] && check2[nx2][ny2]) // 둘다 방문했었으면 체크 X
            continue;
        if(count < Min && (nx >= 1 && ny >= 1 && nx <= n && ny <= m && nx2 >= 1 && ny2 >= 1 && nx2 <= n && ny2 <= m))
        {
            bfs(nx, ny, nx2, ny2, count + 1, check, check2);
        }
        if(nx < 1 || ny < 1 || nx > n || ny > m)
        {
            if(nx2 >= 1 && ny2 >= 1 && nx2 <= n && ny2 <= m)
            {
                Min = count + 1;
                return;
            }
        }
        else if(nx2 < 1 || ny2 < 1 || nx2 > n || ny2 > m)
        {
            if(nx >= 1 && ny >= 1 && nx <= n && ny <= m)
            {
                Min = count + 1;
                return;
            }
        }
    }
}
int main()
{
    int a, b, c, d, C = 0;
    vector<vector<bool>> check(22, vector<bool> (22, false));
    vector<vector<bool>> check2(22, vector<bool> (22, false));
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 'o')
            {
                if(C == 1)
                {
                    c = i;
                    d = j;
                }
                else{
                    a = i;
                    b = j;
                    C++;
                }
            }
        }
    }
    bfs(a, b, c, d, 0, check, check2);
    if(Min >= 1 && Min <= 10)
        cout << Min;
    else cout << -1;
}
