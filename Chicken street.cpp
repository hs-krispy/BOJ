//
// Created by 0864h on 2020-06-17.
//
#include<iostream>
#include<vector>
#include<tuple>
#include<climits>
using namespace std;
int n, m, map[51][51], check[51][51], Min = INT_MAX;
void dfs(int x, int y, int c, vector<tuple<int, int, int>> v)
{
    int sum = 0;
    int vx, vy, vz;
    for(int i = 0; i < v.size(); i++)
    {
        tie(vx, vy, vz) = v[i];
        if(vz > abs(vx - x) + abs(vy - y))
        {
            vz = abs(vx - x) + abs(vy - y);
            v[i] = tie(vx, vy, vz);
        }
        sum += vz;
    }
    if(Min > sum)
        Min = sum;
    if(c == m)
        return;
    for(int i = x; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(map[i][j] == 2 && !check[i][j])
            {
                check[i][j] = true;
                dfs(i, j, c + 1, v);
                check[i][j] = false;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    vector<tuple<int, int, int>> v;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 1)
                v.emplace_back(i, j, INT_MAX);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(map[i][j] == 2)
            {
                check[i][j] = true;
                dfs(i, j, 1, v);
//                int x, y, z;
//                for(int k = 0; k < v.size(); k++)
//                {
//                    tie(x, y, z) = v[k];
//                    z = INT_MAX;
//                    v[k] = tie(x, y, z);
//                }
            }
        }
    }
    cout << Min;
}
