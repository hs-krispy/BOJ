//
// Created by 0864h on 2020-07-26.
//
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int N, S[21][21], Min = INT_MAX, e = 0;
bool check[21];
vector<int> v, v2, init;
void team(int num, int c)
{
    if(c == e)
    {
        int team1 = 0, team2 = 0;
        v = v2 = init;
        for(int i = 1; i <= N; i++)
        {
            if(check[i])
                v.push_back(i);
            if(!check[i])
                v2.push_back(i);
        }
        for(int i = 0; i < N - 1; i++)
        {
            for(int j = 0; j < N - 1; j++)
            {
                if(i < v.size() && j < v.size())
                {
                    if(i == j) continue;
                    team1 += S[v[i]][v[j]];
                }
                if(i < v2.size() && j < v2.size())
                {
                    if(i == j) continue;
                    team2 += S[v2[i]][v2[j]];
                }
            }
        }
        if(Min > abs(team1 - team2))
            Min = abs(team1 - team2);
        return;
    }
    for(int i = num + 1; i <= N; i++)
    {
        if(c == 0 && i > 1)
            return;
        check[i] = true;
        team(i, c + 1);
        check[i] = false;
    }
}
int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
            cin >> S[i][j];
    }
    for(int i = 1; i <= N - 1; i++)
    {
        e = i;
        team(0, 0);
    }
    cout << Min;
}
