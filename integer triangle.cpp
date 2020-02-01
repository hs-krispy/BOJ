//
// Created by 0864h on 2020-02-01.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector< vector<int> > d(501, vector<int>(501,0));
int main()
{
    int i, j, n, ans;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            cin>>d[i][j];
        }
    }
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=i;j++)
            d[i][j] += max(d[i-1][j-1], d[i-1][j]);
    }
    ans = *max_element(&d[n][1], &d[n][n+1]);
    cout<<ans;
}
