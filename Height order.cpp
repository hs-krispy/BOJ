//
// Created by 0864h on 2021-02-25.
//
#include<iostream>
#include<vector>
#include <cstring>

using namespace std;
int N, M, a, b, count = 0, ans = 0;
vector<int> small[501], tall[501];
bool check[501];
void s_height(int idx)
{
    for(int i = 0; i < small[idx].size(); i++)
    {
        if(!check[small[idx][i]])
        {
            check[small[idx][i]] = true;
            count++;
            s_height(small[idx][i]);
        }
    }
}
void t_height(int idx)
{
    for(int i = 0; i < tall[idx].size(); i++)
    {
        if(!check[tall[idx][i]])
        {
            check[tall[idx][i]] = true;
            count++;
            t_height(tall[idx][i]);
        }
    }
}
int main()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> a >> b;
        small[b].push_back(a);
        tall[a].push_back(b);
    }
    for(int i = 1; i <= N; i++)
    {
        int sum = 0;
        memset(check, false, sizeof(check));
        count = 0;
        check[i] = true;
        s_height(i);
        sum += count;
        memset(check, false, sizeof(check));
        count = 0;
        check[i] = true;
        t_height(i);
        sum += count;
        if(sum == N - 1)
            ans++;
    }
    cout << ans;
}
