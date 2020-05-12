//
// Created by 0864h on 2020-02-16.
//
#include<iostream>
using namespace std;
int d[1001][1001];
const int DIV = 1000000003;
int main()
{
    int n, k;
    cin>>n>>k;
    for(int i = 1; i <= n; i++)
        d[i][1] = i;
    d[4][2] = 2; d[4][3] = 0; d[4][4] = 0;
    for(int i = 5; i <= n; i++)
    {
        for(int j = 2; j <= i; j++)
        {
            if(i/2 < j)
                d[i][j] = 0;
            else {
                d[i][j] = d[i-1][j] + d[i-2][j-1];
                d[i][j] %= DIV;
            }
        }
    }
    cout<<d[n][k];
}
 