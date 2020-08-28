//
// Created by 0864h on 2020-08-28.
//
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int V, E;
bool check[10001];
vector<pair<int, int>> v[10001];
int main()
{
    int a, b, c;
    cin >> V >> E;
    for(int i = 1; i <= E; i++)
    {
        cin >> a >> b >> c;
        v[a].emplace_back(b, c);
        v[b].emplace_back(a, c);
    }
    check[1] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for(int i = 0; i < v[1].size(); i++)
        pq.push({v[1][i].second, v[1][i].first});
    int sum = 0;
    while(!pq.empty())
    {
        int vertex = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(!check[vertex])
        {
            check[vertex] = true;
            sum += cost;
            for(int i = 0; i < v[vertex].size(); i++)
            {
                int cost = v[vertex][i].second;
                pq.push({cost, v[vertex][i].first});
            }
        }
    }
    cout << sum;
}
