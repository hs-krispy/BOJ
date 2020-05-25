//
// Created by 0864h on 2020-01-23.
//
#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n, c = 1, Max = 0, idx = 0;
    vector<int> d(1001, 1);
    vector<int> num(1001);
    vector<int> ans(1001);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    if(n == 1) // 수열의 길이가 1일때
        cout << 1 << "\n" << num[1];
    else
    {
        for (int i = 2; i <= n; i++)
        {
            for(int j = 1;j <= i;j++)
            {
                if(num[i] > num[j])
                    d[i] = max(d[i], d[j] + 1);
            }
            if(Max < d[i])
            {
                Max = d[i];
                idx = i;
            }
        }
        ans[0] = num[idx];
        for(int i = idx - 1; i >= 1; i--)
        {
            if(num[idx] > num[i] && d[idx] - 1 == d[i])
            {
                ans[c++] = num[i];
                d[idx] = d[i];
                num[idx] = num[i];
            }
        }
        cout << Max <<"\n";
        for(int i = c - 1; i >= 0; i--)
            cout << ans[i]<<" ";
    }

}