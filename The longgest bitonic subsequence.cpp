//
// Created by 0864h on 2020-05-29.
//
#include<iostream>
#include<vector>
using namespace std;
vector< vector<int> > d(1001, vector<int> (2, 1));
int main()
{
    int n, num[1001];
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> num[i];
    for(int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (num[i] > num[j])
                d[i][0] = max(d[i][0], d[j][0] + 1);
        }
    }
    int Max = d[n][0] + d[n][1] - 1;
    for(int i = n - 1; i >= 1; i--)
    {
        for(int j = n; j > i; j--)
        {
            if(num[i] > num[j])
                d[i][1] = max(d[i][1], d[j][1] + 1);
        }
        if(Max < d[i][0] + d[i][1] - 1)
            Max = d[i][0] + d[i][1] - 1;
    }
    cout << Max;
}
