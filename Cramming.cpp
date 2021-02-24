//
// Created by 0864h on 2021-02-24.
//
#include <iostream>
using namespace std;
int N, T, K[101], S[101], d[10001];
int main()
{
    cin >> N >> T;
    for(int i = 1; i <= N; i++)
        cin >> K[i] >> S[i];
    for(int i = 1; i <= N; i++)
    {
        for(int j = T; j >= K[i]; j--)
            d[j] = max(d[j], S[i] + d[j - K[i]]);
    }
    cout << d[T];
}
