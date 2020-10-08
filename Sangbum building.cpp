//
// Created by 0864h on 2020-10-08.
//
#include<iostream>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;
int L, R, C;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int df[] = {-1, 1};
queue<pair<tuple<int, int, int>, int>> q;
char building[31][31][31];
bool check[31][31][31];
int main()
{
    while(true)
    {
        cin >> L >> R >> C;
        if(L == 0 && R == 0 && C == 0)
            break;
        bool escape = false;
        for(int i = 1; i <= L; i++)
        {
            for(int j = 1; j <= R; j++)
            {
                for(int k = 1; k <= C; k++)
                {
                    cin >> building[i][j][k];
                    if(building[i][j][k] == 'S')
                    {
                        q.push({{i, j, k}, {0}});
                        check[i][j][k] = true;
                    }
                }
            }
        }
        while(!q.empty())
        {
            int f, x, y, t;
            tie(f, x, y) = q.front().first;
            t = q.front().second;
            q.pop();
            for(int i = 0; i < 6; i++)
            {
                if(i < 4)
                {
                    int nf = f;
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    int nt = t + 1;
                    if(nx >= 1 && ny >= 1 && nx <= R && ny <= C && building[nf][nx][ny] != '#' && !check[nf][nx][ny])
                    {
                        check[nf][nx][ny] = true;
                        q.push({{nf, nx, ny}, nt});
                        if(building[nf][nx][ny] == 'E')
                        {
                            cout << "Escaped in " << nt <<" minute(s).\n";
                            escape = true;
                            break;
                        }
                    }
                }
                if(i >= 4)
                {
                    int nf = f + df[i - 4];
                    int nx = x;
                    int ny = y;
                    int nt = t + 1;
                    if(nf >= 1 && nf <= L && building[nf][nx][ny] != '#' && !check[nf][nx][ny])
                    {
                        check[nf][nx][ny] = true;
                        q.push({{nf, nx, ny}, nt});
                        if(building[nf][nx][ny] == 'E')
                        {
                            cout << "Escaped in " << nt <<" minute(s).\n";
                            escape = true;
                            break;
                        }
                    }
                }
            }
            if(escape)
                break;
        }
        if(!escape)
            cout << "Trapped!\n";
        while(!q.empty())
            q.pop();
        memset(check, false, sizeof(check));
    }
}
