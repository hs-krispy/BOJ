//
// Created by 0864h on 2020-10-31.
//
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<int> v[501];
int n, m, a, b;
queue<int> q;
bool check[501][501], check2[501];
int main()
{
    cin >> n >> m;
    int count = 0;
    for(int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    q.push(1);
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        for(int i = 0; i < v[f].size(); i++)
        {
            if(!check2[v[f][i]] && !check[f][v[f][i]] && !check[v[f][i]][f])
            {
                check[f][v[f][i]] = check[v[f][i]][f] = true;
                check2[v[f][i]] = true;
                count++;
                if(f == 1)
                    q.push(v[f][i]);
            }
        }
    }
    cout << count;
}