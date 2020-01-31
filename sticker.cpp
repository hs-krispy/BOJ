//
// Created by 0864h on 2020-01-29.
//
#include<iostream>
#include<algorithm>
using namespace std;
int num[3][100001]={0};
int main()
{
    int t,test, n, i, k;
    cin >> test;
    for (t = 0; t < test; t++)
    {
        cin >> n;
        for (k = 1; k <= n; k++)
        {
            cin >> num[1][k];
        }
        for (k = 1; k <= n; k++)
        {
            cin >> num[2][k];
        }
        int d[3][100001] = {0};
        d[1][1] = num[1][1]; d[2][1] = num[2][1]; d[1][2] = d[2][1]+num[1][2]; d[2][2] = d[1][1]+num[2][2];
        for(i=3;i<=n;i++)
        {
            d[1][i] = num[1][i] + max(d[2][i-1], d[2][i-2]);
            d[2][i] = num[2][i] + max(d[1][i-1], d[1][i-2]);
        }
        cout<<max(d[1][n], d[2][n])<<"\n";
    }
    return 0;
}
