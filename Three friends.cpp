//
// Created by salmon11 on 2020-08-07.
//
#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;
int N, M, A, B, count[4001], Min = INT_MAX;
bool rel[4001][4001], check[4001];
vector<int> v;
void cal(int idx, int c, int s)
{
    if(c == 3)
    {
        int sum = 0;
        for(int i = 0; i < v.size(); i++)
        {
            for(int j = 0; j < v.size(); j++)
            {
                if(i == j) continue;
                if(!rel[v[i]][v[j]])
                    return;
            }
        }
        for(int i = 0; i < v.size(); i++)
            sum += count[v[i]] - 2;
        if(Min > sum)
            Min = sum;
        return;
    }
    for(int i = s; i <= N; i++)
    {
        if(rel[idx][i] && !check[i])
        {
            check[i] = true;
            v.push_back(i);
            cal(idx, c + 1, i + 1);
            v.pop_back();
            check[i] = false;
        }
    }
}
int main()
{
    cin >> N >> M;
    for(int i = 1; i <= M; i++)
    {
        cin >> A >> B;
        rel[A][B] = rel[B][A] = true;
        count[A]++;
        count[B]++;
    }
    for(int i = 1; i < N; i++)
    {
        v.push_back(i);
        cal(i, 1, i + 1);
        v.pop_back();
    }
    if(Min == INT_MAX)
    {
        cout << -1;
        return 0;
    }
    cout << Min;
}
