//
// Created by 0864h on 2020-08-04.
//
#include<iostream>
#include<queue>
using namespace std;
int N, M, x, y;
int dx[] = {1, 2, 3, 4, 5, 6};
int ls[100];
bool check[100];
int main()
{
    cin >> N >> M;
    for(int i = 0; i < N + M; i++)
    {
        cin >> x >> y;
        ls[x] = y;
    }
    queue<pair<int, int>> q;
    q.push({1, 0});
    check[1] = true;
    while(!q.empty())
    {
        int num = q.front().first;
        int count = q.front().second;
        if(num >= 94)
        {
            cout << count + 1;
            return 0;
        }
        q.pop();
        for(int i : dx)
        {
            int nnum = num + i;
            int ncount = count + 1;
            if(nnum >= 1 && nnum <= 100 && !check[nnum])
            {
                if(ls[nnum] != 0)
                    nnum = ls[nnum];
                check[nnum] = true;
                q.push({nnum, ncount});
            }
        }
    }
}
