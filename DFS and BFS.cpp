//
// Created by 0864h on 2020-06-01.
//
#include<iostream>
#include<queue>
#include <cstring>
using namespace std;
int n, m, v, arr[1001][1001];
bool check[1001];
void dfs(int p)
{
    cout << p <<" ";
    for(int i = 1; i <= n; i++)
    {
        if(!check[i] && arr[p][i] == 1)
        {
            check[i] = true;
            dfs(i);
        }
    }
}
void bfs()
{
    queue<int> q;
    q.push(v);
    check[v] = true;
    while(!q.empty())
    {
        v = q.front();
        cout << v <<" ";
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if(!check[i] && arr[v][i] == 1)
            {
                q.push(i);
                check[i] = true;
            }
        }
    }
}
int main()
{
    cin >> n >> m >> v;
    int num1, num2;
    for(int i = 0; i < m; i++)
    {
        cin >> num1 >> num2;
        arr[num1][num2] = arr[num2][num1] = 1;
    }
    check[v] = true;
    dfs(v);
    cout << "\n";
    memset(check, false, sizeof(check));
    bfs();
}
