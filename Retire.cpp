//
// Created by 0864h on 2020-07-29.
//
#include<iostream>
using namespace std;
int N, T[16], P[16], ans[16];
int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> T[i] >> P[i];
    for(int i = 1; i <= N; i++)
    {
        ans[i] = max(ans[i], ans[i - 1]);
        if(i + T[i] - 1 <= N)
            ans[i + T[i] - 1] = max(ans[i + T[i] - 1], ans[i - 1] + P[i]);
    }
    cout << ans[N];
}
