//
// Created by 0864h on 2020-01-21.
//
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int i,j,n,sum=0;
    vector< vector<long long> > d;
    d.assign(100001, vector<long long>(3));
    cin>>n;
    d[1][0]=1;d[1][1]=1;d[1][2]=1;//첫번째줄 우리에 배치안하는 경우, 1-1, 1-2에 배치하는경우
    for(i=2;i<=n;i++)
    {
        d[i][0] = d[i-1][0]+d[i-1][1]+d[i-1][2];
        d[i][0] %= 9901;
        d[i][1] = d[i-1][0]+d[i-1][2];
        d[i][1] %= 9901;
        d[i][2] = d[i-1][0]+d[i-1][1];
        d[i][2] %= 9901;
    }
    sum = (d[n][0]+d[n][1]+d[n][2])%9901;
    cout<<sum;
}
