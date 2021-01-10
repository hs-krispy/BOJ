//
// Created by 0864h on 2021-01-10.
//
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
bool check[101], num_check[101];
vector<int> v[101], result, ans;
void choose(int start, int next)
{
    if(!result.empty() && start == next)
    {
        for(int i = 0; i < result.size(); i++)
        {
            num_check[result[i]] = true;
            ans.push_back(result[i]);
        }
        return;
    }
    if(!check[v[next][0]])
    {
        check[v[next][0]] = true;
        result.push_back(v[next][0]);
        choose(start, v[next][0]);
        check[v[next][0]] = false;
        result.pop_back();
    }
}
int main()
{
    cin >> N;
    int num;
    for(int i = 1; i <= N; i++)
    {
        cin >> num;
        v[i].push_back(num);
    }
    for(int i = 1; i <= N; i++)
    {
        if(!num_check[i])
            choose(i, i);
    }
    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << "\n";
}
