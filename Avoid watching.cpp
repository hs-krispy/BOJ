//
// Created by 0864h on 2020-11-30.
//
#include<iostream>
#include<vector>
using namespace std;
int N;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char arr[7][7];
bool check = false;
vector<pair<int, int>> v;
void watch(int x, int y, int idx)
{
    int nx = x + dx[idx];
    int ny = y + dy[idx];
    if(arr[nx][ny] == 'O')
        return;
    if(arr[nx][ny] == 'S')
    {
        check = true;
        return;
    }
    if(nx >= 1 && ny >= 1 && nx <= N && ny <= N && arr[nx][ny] != 'T')
    {
        watch(nx, ny, idx);
    }
}
void dfs(int count)
{
    if(count == 3)
    {
        for(int i = 0; i < v.size(); i++)
        {
            for(int j = 0; j < 4; j++)
            {
                watch(v[i].first, v[i].second, j);
                if(check)
                {
                    check = false;
                    return;
                }
            }
        }
        cout << "YES";
        exit(0);
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(arr[i][j] == 'X')
            {
                arr[i][j] = 'O';
                dfs(count + 1);
                arr[i][j] = 'X';
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
            cin >> arr[i][j];
            if(arr[i][j] == 'T')
                v.emplace_back(i, j);
        }
    }
    dfs(0);
    cout << "NO";
}
