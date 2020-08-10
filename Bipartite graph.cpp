//
// Created by 0864h on 2020-06-03.
//
#include<iostream>
#include<vector>
using namespace std;
int check[20001];
bool verify;
int V, E;
vector<int> v[20001];
void dfs(int idx, int val)
{
    for(int i = 0; i < v[idx].size(); i++)
    {
        if(check[v[idx][i]] == val)
        {
            verify = false;
            return;
        }
        if(check[v[idx][i]] == 0) // 확인안한 정점만
        {
            check[v[idx][i]] = 3 - val;
            dfs(v[idx][i], check[v[idx][i]]);
        }
    }
}
int main()
{
    int T, v1, v2;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        verify = true;
        if(i > 0) // v 초기화
        {
            for(int j = 1; j <= V; j++)
            {
                v[j].clear();
                check[j] = 0;
            }
        }
        cin >> V >> E;
        for(int j = 1; j <= E; j++)
        {
            cin >> v1 >> v2;
            v[v1].push_back(v2);
            v[v2].push_back(v1);
        }
        for(int i = 1; i <= V; i++)
        {
            if(check[i] == 0)
            {
                check[i] = 1;
                dfs(i, 1);
            }
        }
        if(verify)
            cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}
