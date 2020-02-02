//
// Created by 0864h on 2020-02-02.
//
#include<iostream>
using namespace std;
long long d[201][201];
int main()
{
    int i,j,n,k,c;
    long long div=1000000000;
    cin>>n>>k;
    for(i=1;i<=k;i++)
    {
        d[0][i] = 1;//i개의 숫자를 골라 합이 0이 되는 겅우는 0만 i개(1개)
        d[1][i] = i;//i개의 숫자를 골라 합이 1이 되는 경우는 i개
    }
    for(i=1;i<=n;i++)
        d[i][1] = 1;//1개의 숫자를 골라 합이 i가 되는 경우는 1개
    c=k;
    for(i=2;i<=n;i++)
    {
        for(k=2;k<=c;k++)
        {
            for(j=0;j<=i;j++)
            {
                d[i][k] += d[j][k - 1];
                d[i][k] %= div;
            }
        }
    }
    cout<<d[n][c];
}
