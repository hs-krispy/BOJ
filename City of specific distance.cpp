//
// Created by 0864h on 2021-01-09.
//
#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;
int N, M, K, X, A, B;
vector<int> v[300001];
vector<int> dis(300001, INT_MAX);
queue<int> q;
int main()
{
    cin >> N >> M >> K >> X;
    for(int i = 0; i < M; i++)
    {
        cin >> A >> B;
        v[A].push_back(B);
    }
    q.push(X);
    dis[X] = 0;
    while(!q.empty())
    {
        int s = q.front();
        q.pop();
        for(int i = 0; i < v[s].size(); i++)
        {
            if(dis[v[s][i]] > dis[s] + 1)
            {
                dis[v[s][i]] = dis[s] + 1;
                q.push(v[s][i]);
            }
        }
    }
    bool check = false;
    for(int i = 1; i <= N; i++)
    {
        if(dis[i] == K)
        {
            check = true;
            cout << i <<"\n";
        }
    }
    if(!check)
        cout << -1;
}
