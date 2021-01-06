//
// Created by 0864h on 2021-01-05.
//
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int N, M, A, B;
vector<int> v[10001];
int count[10001], Max = 0;
void bfs(int num, int size)
{
    vector<bool> check(size + 1, false);
    queue<int> q;
    q.push(num);
    check[num] = true;
    while(!q.empty())
    {
        int idx = q.front();
        q.pop();
        for(int i = 0; i < v[idx].size(); i++)
        {
            if(!check[v[idx][i]])
            {
                check[v[idx][i]] = true;
                count[num]++;
                q.push(v[idx][i]);
            }
        }
    }
}
int main()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> A >> B;
        v[B].push_back(A);
    }
    for(int i = 1; i <= N; i++)
    {
        if(v[i].size() > 0)
            bfs(i, N);
        if(Max < count[i])
            Max = count[i];
    }
    for(int i = 1; i <= N; i++)
    {
        if(Max == count[i])
            cout << i << " ";
    }
}

