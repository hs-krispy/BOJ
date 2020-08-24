//
// Created by 0864h on 2020-08-24.
//
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<string, int> m;
vector<pair<int, string>> v;
int K, L;
int main()
{
    string num;
    cin >> K >> L;
    for(int i = 1; i <= L; i++)
    {
        cin >> num;
        m[num] = i;
    }
    for(auto & it : m)
        v.emplace_back(it.second, it.first);
    sort(v.begin(), v.end());
    if(v.size() >= K)
    {
        for(int i = 0; i < K; i++)
            cout << v[i].second << "\n";
    }
    else
    {
        for(int i = 0; i < v.size(); i++)
            cout << v[i].second << "\n";
    }
}
