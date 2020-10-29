//
// Created by 0864h on 2020-10-29.
//
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
vector<int> v[20001];
bool check[20001];
int val[20001];
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int Max = 0;
    queue<pair<int, int>> q;
    for(int i = 0; i < edge.size(); i++)
    {
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    check[1] = true;
    q.push({1, 0});
    while(!q.empty())
    {
        int node = q.front().first;
        int dis = q.front().second;
        q.pop();
        for(int i = 0; i < v[node].size(); i++)
        {
            if(!check[v[node][i]])
            {
                check[v[node][i]] = true;
                q.push({v[node][i], dis + 1});
                if(Max < dis + 1)
                    Max = dis + 1;
                val[v[node][i]] = dis + 1;
            }
        }
    }
    for(int i = 1; i <= n; i++)
        if(Max == val[i])
            answer++;
    return answer;
}

