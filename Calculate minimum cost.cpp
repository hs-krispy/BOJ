//
// Created by 0864h on 2020-07-20.
//
#include<cstdio>
using namespace std;
int N, M, s, e, cost, city[1001][1001], dist[1001];
bool check[1001];
const int Max = 1000000000;
int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            city[i][j] = Max;
    }
    for(int i = 1; i <= M; i++)
    {
        scanf("%d %d %d", &s, &e, &cost);
        if(city[s][e] > cost)
            city[s][e] = cost;
    }
    scanf("%d %d", &s, &e);
    for(int i = 1; i <= N; i++)
        dist[i] = Max;
    dist[s] = 0;
    for(int i = 1; i <= N; i++)
    {
        int temp = Max + 1;
        int idx = 0;
        for(int j = 1; j <= N; j++)
        {
            if(!check[j] && temp > dist[j]) //가장 비용이 적은 정점으로
            {
                temp = dist[j];
                idx = j;
            }
        }
        check[idx] = true;
        for (int j = 1; j <= N; j++) { // 해당 정점과 연결되어있는 모든 정점의 비용 교체
            if (dist[j] > dist[idx] + city[idx][j]) {
                dist[j] = dist[idx] + city[idx][j];
            }
        }
    }
    printf("%d", dist[e]);
}
