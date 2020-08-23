//
// Created by 0864h on 2020-02-08.
//
#include<iostream>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;
long long space[21][21];
int dx[] = {-1, 1 ,0, 0};
int dy[] = {0, 0, -1, 1};
bool check[21][21];
int n;
int bfs(int a, int b, int c, int d)
{
    int sec = 0;
    queue<pair<pair<int, int>, tuple<int, int, int>>> q;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    q.push({{a, b}, {c, d, 0}});
    check[a][b] = true;
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int size, eat, dis;
        tie(size, eat, dis) = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ndis = dis + 1;
            if(nx >= 1 && ny >= 1 && nx <= n && ny <= n && space[nx][ny] <= size && !check[nx][ny])
            {
                if(space[nx][ny] > 0 && space[nx][ny] < size)
                {
                    pq.push({ndis, nx, ny});
                }
                check[nx][ny] = true;
                q.push({{nx, ny}, {size, eat, ndis}});
            }
        }
        if(q.empty() && !pq.empty())
        {
            eat++;
            int f, s, t;
            tie(f, s, t) = pq.top();
            if(eat == size)
            {
                size++;
                eat = 0;
            }
            sec += f;
            q.push({{s, t}, {size, eat, 0}});
            while(!pq.empty())
                pq.pop();
            memset(check, false, sizeof(check));
            check[s][t] = true;
            space[s][t] = 0;
        }
    }
    return sec;
}
int main()
{
     cin >> n;
     for(int i = 1; i <= n; i++)
     {
         for(int j = 1; j <= n; j++)
             cin >> space[i][j];
     }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(space[i][j] == 9)
            {
                space[i][j] = 0;
                cout << bfs(i, j, 2, 0);
                return 0;
            }
        }
    }
}
