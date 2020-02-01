//
// Created by 0864h on 2020-02-01.
//
#include<iostream>
#include<algorithm>
using namespace std;
unsigned int d[10001][2]={0};
int main()
{
    unsigned int i, n, num[10001];
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>num[i];
    }
    d[1][1] = num[1]; d[2][1] = num[1]+num[2];
    for(i=3;i<=n;i++)
    {
        d[i][2] = d[i-1][1];//i-1번째 인덱스까지의 최대값
        d[i][1] = num[i]+max(num[i-1]+max(d[i-3][1],d[i-3][2]), max(d[i-2][1],d[i-2][2]));//num[i]를 포함하는 i번째 인덱스까지 최대값
    }
    cout<<max(d[n][1],d[n][2]);
}
