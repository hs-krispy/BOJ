//
// Created by 0864h on 2020-10-01.
//
#include<iostream>
#include<climits>
using namespace std;
int N, grid[11][11];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int Min = INT_MAX, cost = 0;
bool check[11][11];
void cal(int count)
{
    if(count == 3)
    {
        if(Min > cost)
            Min = cost;
        return;
    }
    for(int i = 2; i <= N - 1; i++)
    {
        for(int j = 2; j <= N - 1; j++)
        {
            if(!check[i][j])
            {
                cost += grid[i][j];
                check[i][j] = true;
                bool c = true;
                for(int k = 0; k < 4; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(check[x][y])
                    {
                        c = false;
                        break;
                    }
                }
                if(c)
                {
                    for(int k = 0; k < 4; k++)
                    {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        cost += grid[x][y];
                        check[x][y] = true;
                    }
                    cal(count + 1);
                    for(int k = 0; k < 4; k++)
                    {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        cost -= grid[x][y];
                        check[x][y] = false;
                    }
                }
                check[i][j] = false;
                cost -= grid[i][j];
            }
        }
    }
}
int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> grid[i][j];
        }
    }
    cal(0);
    cout << Min;
}
