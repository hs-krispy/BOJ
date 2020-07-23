//
// Created by 0864h on 2020-07-23.
//
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int V, E, K, startv, endv, W, dist[20001];
bool check[20001];
vector<pair<int, int>> v[20001];
int main()
{
    scanf("%d %d", &V, &E);
    scanf("%d", &K);
    for(int i = 1; i <= E; i++)
    {
        scanf("%d %d %d", &startv, &endv, &W);
        v[startv].emplace_back(endv, W);
    }
    for(int i = 1; i <= V; i++)
        dist[i] = 200001;
    dist[K] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, K});
    while(!pq.empty())
    {
        int vertex = pq.top().second; // 시작 정점
        pq.pop();
        if(!check[vertex]) {
            check[vertex] = true;
            for (int i = 0; i < v[vertex].size(); i++) {
                int nv = v[vertex][i].first; // 시작 정점에서 가중치가 가장 작은 정점
                if (dist[nv] > dist[vertex] + v[vertex][i].second) {
                    dist[nv] = dist[vertex] + v[vertex][i].second;
                    pq.push({-dist[nv], nv}); // 오름차순으로 정렬하기 위해 -붙힘
                }
            }
        }
    }
    for(int i = 1; i <= V; i++)
    {
        if(dist[i] == 200001)
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }
}

