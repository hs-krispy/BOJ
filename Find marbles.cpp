//
// Created by 0864h on 2021-02-24.
//
#include<iostream>
#include<vector>
#include <cstring>

using namespace std;
int N, M, a, b, count = 0, ans = 0;
vector<int> h[100], l[100];
bool check[100];
void under_scale(int idx)
{
    for(int i = 0; i < l[idx].size(); i++)
    {
        if(!check[l[idx][i]])
        {
            check[l[idx][i]] = true;
            count++;
            under_scale(l[idx][i]);
        }
    }
}
void over_scale(int idx)
{
    for(int i = 0; i < h[idx].size(); i++)
    {
        if(!check[h[idx][i]])
        {
            check[h[idx][i]] = true;
            count++;
            over_scale(h[idx][i]);
        }
    }
}
int main()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> a >> b;
        l[a].push_back(b);
        h[b].push_back(a);
    }
    for(int i = 1; i <= N; i++)
    {
        count = 0;
        memset(check, false, sizeof(check));
        check[i] = true;
        under_scale(i);
        if(count > N / 2)
        {
            ans++;
            continue;
        }
        count = 0;
        memset(check, false, sizeof(check));
        check[i] = true;
        over_scale(i);
        if(count > N / 2)
            ans++;
    }
    cout << ans;
}
