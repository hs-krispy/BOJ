//
// Created by 0864h on 2020-05-09.
//
#include<iostream>
#include<queue>
using namespace std;
int dx[] = {-1, 1, 0, 0}; // 상하좌우
int dy[] = {0, 0, -1, 1};
char arr[101][101], arr2[101][101];
bool check[101][101], check2[101][101];
int BFS(int a, int b, char (*arr)[101], bool (*check)[101], int count)
{
    queue<pair<int, int>> q;
    q.push({a, b});
    check[a][b] = true;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(arr[x][y] == arr[nx][ny] && nx >= 1 && ny >= 1 && nx <= 100 && ny <= 100 && !check[nx][ny])
            {
                q.push({nx, ny});
                check[nx][ny] = true;
            }
        }
    }
    count++;
    return count;
}
int main()
{
    int n, count = 0, count2 = 0;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin>>arr[i][j];
            arr2[i][j] = arr[i][j];
            if(arr2[i][j] == 'G')
                arr2[i][j] = 'R';
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(!check[i][j])
                count = BFS(i, j, arr, check, count);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(!check2[i][j])
                count2 = BFS(i, j, arr2, check2, count2);
        }
    }
    cout<<count<<" "<<count2;
}