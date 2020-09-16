//
// Created by 0864h on 2020-09-16.
//
#include<iostream>
#include<vector>
using namespace std;
int N, num, count = 0;
bool check[101];
vector<int> v[101];
void dfs(int idx)
{
    for(int i = 0; i < v[idx].size(); i++)
    {
        if(!check[v[idx][i]])
        {
            check[v[idx][i]] = true;
            count++;
            dfs(v[idx][i]);
        }
    }
}
int main()
{
    int s, e;
    cin >> N >> num;
    for(int i = 0; i < num; i++)
    {
        cin >> s >> e;
        v[s].push_back(e);
        v[e].push_back(s);
    }
    check[1] = true;
    dfs(1);
    cout << count;
}
