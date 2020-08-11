//
// Created by 0864h on 2020-08-11.
//
#include<iostream>
#include<climits>
using namespace std;
int N, d[1001];
char b[1001];
int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> b[i];
        d[i] = INT_MAX;
    }
    d[1] = 1;
    for(int i = 1; i <= N; i++)
    {
        for(int j = i; j <= N; j++)
        {
            if(d[i] != INT_MAX)
            {
                if(b[i] == 'B' && b[j] == 'O')
                {
                    d[j] = min(d[j], d[i] + (j - i) * (j - i));
                }
                if(b[i] == 'O' && b[j] == 'J')
                {
                    d[j] = min(d[j], d[i] + (j - i) * (j - i));
                }
                if(b[i] == 'J' && b[j] == 'B')
                {
                    d[j] = min(d[j], d[i] + (j - i) * (j - i));
                }
            }
        }
    }
    if(d[N] == INT_MAX)
    {
        cout << -1;
        return 0;
    }
    cout << d[N] - 1;
}
