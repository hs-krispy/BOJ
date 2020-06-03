//
// Created by 0864h on 2020-06-03.
//
#include<iostream>
#include<queue>
using namespace std;
bool arr[1001][1001], check[1001];
queue<int> q;
int n, m, count = 0;
void bfs(int s)
{
    q.push(s);
    check[s] = true;
    while(!q.empty())
    {
        int st = q.front();
        q.pop();
        for(int i = 1; i <= n; i++)
        {
            if(arr[st][i])
            {
                arr[st][i] = arr[i][st] = false;
                check[i] = true;
                q.push(i);
            }
        }
    }
    count++;
}
int main()
{
    int u, v;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        arr[u][v] = arr[v][u] = true;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(arr[i][j])
            {
                bfs(i);
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(!check[i])
            count++;
    }
    cout << count;
}
