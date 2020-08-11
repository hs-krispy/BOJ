//
// Created by 0864h on 2020-08-11.
//
#include<iostream>
#include<climits>
using namespace std;
int N, d[1001], A[1001];
int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> A[i];
        d[i] = INT_MAX;
    }
    d[1] = 0;
    for(int i = 1; i <= N; i++)
    {
        for(int j = i + 1; j <= i + A[i]; j++)
        {
            if(d[i] != INT_MAX)
                d[j] = min(d[j], d[i] + 1);
        }
    }
    if(d[N] == INT_MAX)
    {
        cout << -1;
        return 0;
    }
    cout << d[N];
}
