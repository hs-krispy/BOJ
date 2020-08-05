//
// Created by salmon11 on 2020-08-05.
//
#include<iostream>
#include<climits>
using namespace std;
int N, city[11][11], Min = INT_MAX;
bool check[11][11], ccheck[11];
void dfs(int cost, int c, int idx, int start)
{
    if(Min <= cost)
        return;
    if(c == N)
    {
        if(Min > cost)
            Min = cost;
        return;
    }
    for(int j = 1; j <= N; j++)
    {
        if(!check[idx][start] && c == N - 1)
        {
            if(city[idx][start] != 0)
                dfs(cost + city[idx][start], c + 1, idx, start);
            continue;
        }
        if(city[idx][j] != 0 && !check[idx][j] && !ccheck[j])
        {
            check[idx][j] = true;
            ccheck[idx] = true;
            if(c == 0)
                start = idx;
            dfs(cost + city[idx][j], c + 1, j, start);
            check[idx][j] = false;
            ccheck[idx] = false;
        }
    }
}
int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
            cin >> city[i][j];
    }
    for(int i = 1; i <= N; i++)
        dfs(0, 0, i, 0);
    cout << Min;
}
