//
// Created by 0864h on 2020-09-29.
//
#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int n, m, ans = 0, check[10];
void cal(int count)
{
    if(count == n)
    {
        bool check2 = true;
        for(int i = 0; i < v.size(); i++)
        {
            if(check[v[i]] - 1 < 1)
                check2 = false;
        }
        if(check2)
           ans++;
        return;
    }
    for(int i = 0; i <= 9; i++)
    {
        if(check[i] > 0)
            check[i] += 1;
        cal(count + 1);
        check[i] -= 1;
    }
}
int main()
{
    int num;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> num;
        check[num] = 1;
        v.push_back(num);
    }
    cal(0);
    cout << ans;
}
