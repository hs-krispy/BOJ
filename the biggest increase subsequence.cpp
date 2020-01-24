//
// Created by 0864h on 2020-01-23.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int i, j, n;
    long long max = 0;
    vector<long long> num(1001);
    vector<long long> d(1001);
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> num[i];
        d[i] = num[i];
    }// 우선 d[i]에 초기값으로 i번째 수들을 넣어줌
    for (i = 2; i <= n; i++)
    {
        for(j=2;j<=i;j++)
        {
            if (num[i] > num[j - 1] && d[j-1] + num[i] > d[i])//첫번째수부터 i-1번째 수까지 i번째 수보다 작은수들의 합 중 가장 큰 수를 더해지게함
            {
                d[i] = d[j - 1] + num[i];
            }
        }
    }
    max = *max_element(d.begin(), d.end());
    cout<<max;
}