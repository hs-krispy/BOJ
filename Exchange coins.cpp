//
// Created by 0864h on 2021-02-23.
//
#include<iostream>
#include<vector>
using namespace std;
vector<pair<int, int>> v;
int T, k, p, n, d[10001];
int main()
{
    cin >> T >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> p >> n;
        v.emplace_back(p, n);
    }
    d[0] = 1;
    for(int i = 0; i < k; i++)
    {
        for(int j = T; j >= 1; j--)
        {
            for(int K = 1; K <= v[i].second; K++)
            {
                if(j - v[i].first * K >= 0)
                    d[j] += d[j - v[i].first * K];
            }
        }
    }
    cout << d[T];
}

