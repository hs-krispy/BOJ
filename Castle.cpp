//
// Created by 0864h on 2020-04-19.
//
#include<iostream>
#include<vector>
#include<queue>
#include <cstring>

using namespace std;
int arr[51][51], temp[51][51], sum[251];
bool check[51][51][5]; // 남, 동, 북, 서
bool check2[51][51];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int count = 0, c1 = 0, c2 = 0, areaMAX = 0;
queue<pair<int, int>> q;
int bfs(int i, int j)
{
    c1++;
    int size = 0;
    q.push({i, j});
    check2[i][j] = true;
    arr[i][j] = c1;
    while(!q.empty())
    {
        size++;
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!check2[nx][ny] && !check[x][y][i] && nx >= 1 && ny >= 1 && nx <= 50 && ny <= 50)
            {
                q.push({nx, ny});
                check2[nx][ny] = true;
                arr[nx][ny] = c1;
            }
        }
    }
    sum[c1] = size;
    return size;
}
void SUM(int i, int j)
{
    c2++;
    q.push({i, j});
    check2[i][j] = true;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!check2[nx][ny] && !check[x][y][i] && nx >= 1 && ny >= 1 && nx <= 50 && ny <= 50)
            {
                q.push({nx, ny});
                check2[nx][ny] = true;
            }
            for(int k = 1; k <= c1; k++)
            {
                if(!check2[nx][ny] && check[x][y][i] && arr[nx][ny] == k && c2 != k && areaMAX < sum[c2] + sum[k] && nx >= 1 && ny >= 1 && nx <= 50 && ny <= 50)
                    areaMAX = sum[c2] + sum[k];
            }
        }
    }
}
int main()
{
    int n, m, area = 0, Max = 0, l;
    cin>>n>>m;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin>>arr[i][j];
            temp[i][j] = arr[i][j];
            for(int k = 8, l = 0; temp[i][j] > 0; k /= 2, l++)
            {
                if(temp[i][j] >= k)
                {
                    temp[i][j] -= k;
                    check[i][j][l] = true;
                }
            }
        }
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(!check2[i][j])
            {
                count++;
                area = bfs(i, j);
                if(Max < area)
                    Max = area;
            }
        }
    }
    memset(check2, false, sizeof(check2));
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(!check2[i][j])
                SUM(i, j);
        }
    }
    cout<<count<<"\n"<<Max<<"\n"<<areaMAX;
}
