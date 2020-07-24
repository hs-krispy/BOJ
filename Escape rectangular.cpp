//
// Created by 0864h on 2020-07-24.
//
#include<cstdio>
#include<queue>
#include<climits>
#include<tuple>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, M, H, W, Sr, Sc, Fr, Fc;
int grid[1001][1001];
bool check[1001][1001];
int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
            scanf("%d", &grid[i][j]);
    }
    scanf("%d %d %d %d %d %d", &H, &W, &Sr, &Sc, &Fr, &Fc);
    queue<tuple<int, int, int>> q;
    q.push({Sr, Sc, 0});
    check[Sr][Sc] = true;
    while(!q.empty())
    {
        int sx, sy, c;
        tie(sx, sy, c) = q.front();
        q.pop();
        if(sx == Fr && sy == Fc)
        {
            printf("%d", c);
            return 0;
        }
        for(int i = 0; i < 4; i++)
        {
            int nsx = sx + dx[i];
            int nsy = sy + dy[i];
            int nc = c + 1;
            bool CHECK = false;
            if(nsx >= 1 && nsy >= 1 && nsx <= N && nsy <= M && !check[nsx][nsy])
            {
                if(i == 0 && nsy + W <= M + 1)
                {
                    for(int j = nsy; j < nsy + W; j++)
                    {
                        if(grid[nsx][j] == 1)
                        {
                            CHECK = true;
                            break;
                        }
                    }
                    if(!CHECK)
                    {
                        check[nsx][nsy] = true;
                        q.push({nsx, nsy, nc});
                    }
                }
                if(i == 1 && nsy + W <= M + 1 && nsx + H <= N + 1)
                {
                    for(int j = nsy; j < nsy + W; j++)
                    {
                        if(grid[nsx + H - 1][j] == 1)
                        {
                            CHECK = true;
                            break;
                        }
                    }
                    if(!CHECK)
                    {
                        check[nsx][nsy] = true;
                        q.push({nsx, nsy, nc});
                    }
                }
                if(i == 2 && nsx + H <= N + 1)
                {
                    for(int j = nsx; j < nsx + H; j++)
                    {
                        if(grid[j][nsy] == 1)
                        {
                            CHECK = true;
                            break;
                        }
                    }
                    if(!CHECK)
                    {
                        check[nsx][nsy] = true;
                        q.push({nsx, nsy, nc});
                    }
                }
                if(i == 3 && nsx + H <= N + 1 && nsy + W <= M + 1)
                {
                    for(int j = nsx; j < nsx + H; j++)
                    {
                        if(grid[j][nsy + W - 1] == 1)
                        {
                            CHECK = true;
                            break;
                        }
                    }
                    if(!CHECK)
                    {
                        check[nsx][nsy] = true;
                        q.push({nsx, nsy, nc});
                    }
                }
            }
        }
    }
    printf("-1");
}
