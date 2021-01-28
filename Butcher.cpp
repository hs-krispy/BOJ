//
// Created by 0864h on 2021-01-27.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int N, M;
vector<pair<int, int>> v;
bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if(a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}
int main()
{
    long long cost, amount, sum = 0, sum_cost = 0, sum_amount = 0, Min_cost = INT_MAX;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        cin >> amount >> cost;
        v.emplace_back(cost, amount);
        sum += amount;
    }
    if(sum < M)
    {
        cout << -1;
        return 0;
    }
    sort(v.begin(), v.end(), compare); // 가격 오름차순, 무게 내림차순 정렬
    if(v[0].second >= M)
    {
        cout << v[0].first;
        return 0;
    }
    for(int i = 0; i < v.size(); i++)
    {
        if(i == 0 || v[i - 1].first < v[i].first)
            sum_cost = v[i].first;
        else
            sum_cost += v[i].first;
        sum_amount += v[i].second;
        if(sum_amount >= M)
        {
            if(Min_cost > sum_cost)
                Min_cost = sum_cost;
        }
    }
    cout << Min_cost;
}
