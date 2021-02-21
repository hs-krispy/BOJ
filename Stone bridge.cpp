//
// Created by 0864h on 2021-02-21.
//
#include<iostream>
#include<queue>
using namespace std;
queue<pair<int, int>> q;
int A, B, N, M;
bool check[100001];
int main()
{
    cin >> A >> B >> N >> M;
    int dx[] = {-1, 1, -A, A, B, -B, A, B};
    q.push({N, 0});
    check[N] = true;
    while(!q.empty())
    {
        int x = q.front().first;
        int count = q.front().second;
        q.pop();
        for(int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ncount = count + 1;
            if(nx >= 0 && nx <= 100000 && !check[nx])
            {
                if(nx == M)
                {
                    cout << ncount;
                    return 0;
                }
                check[nx] = true;
                q.push({nx, ncount});
            }
        }
        for(int i = 6; i < 8; i++)
        {
            int nx = x * dx[i];
            int ncount = count + 1;
            if(nx >= 0 && nx <= 100000 && !check[nx])
            {
                if(nx == M)
                {
                    cout << ncount;
                    return 0;
                }
                check[nx] = true;
                q.push({nx, ncount});
            }
        }
    }
}
