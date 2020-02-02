//
// Created by 0864h on 2020-02-02.
//
#include<iostream>
#include<algorithm>
using namespace std;
int d[100001][4];
int main()
{
    int i,n,ans1,ans2;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>d[i][1]>>d[i][2]>>d[i][3];
    }
    for(i=2;i<=n;i++)
    {
        d[i][1] += max(d[i-1][1], d[i-1][2]);
        d[i][2] += max({d[i-1][1], d[i-1][2], d[i-1][3]});
        d[i][3] += max(d[i-1][2], d[i-1][3]);
    }
    ans1 = max ( max(d[n][1],d[n][2]),d[n][3] );
    for(i=n;i>=2;i--)
    {
        d[i][1] -= max(d[i-1][1], d[i-1][2]);
        d[i][2] -= max({d[i-1][1], d[i-1][2], d[i-1][3]});
        d[i][3] -= max(d[i-1][2], d[i-1][3]);
    }
    for(i=2;i<=n;i++)
    {
        d[i][1] += min(d[i-1][1], d[i-1][2]);
        d[i][2] += min({d[i-1][1], d[i-1][2], d[i-1][3]});
        d[i][3] += min(d[i-1][2], d[i-1][3]);
    }
    ans2 = min( min(d[n][1],d[n][2]), d[n][3] );
    cout<<ans1<<" "<<ans2;
}
