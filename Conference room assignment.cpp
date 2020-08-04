//
// Created by 0864h on 2020-08-04.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> v;
int N, ans = 1, s, e;
int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> s >> e;
        v.emplace_back(e, s);
    }
    sort(v.begin(), v.end());
    int temp = v[0].first;
    for(int i = 1; i < N; i++)
    {
        s = v[i].second;
        e = v[i].first;
        if(s >= temp)
        {
            ans++;
            temp = e;
        }
    }
    cout << ans;
}

