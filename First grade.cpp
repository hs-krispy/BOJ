//
// Created by 0864h on 2020-03-02.
//
#include<iostream>
using namespace std;
long long d[100][21];
int main()
{
    int i,j,n, num[101];
    cin>>n;
    for(i=1; i<=n;i++)
    {
       cin>>num[i];
    }
    d[1][num[1]] = 1;
    for(i=2;i<=n-1;i++)
    {
        for(j=0;j<=20;j++)
        {
            if(j-num[i]>=0)
                d[i][j] += d[i-1][j-num[i]];//i번째 수까지 이용해서 j를 만드는 경우
            if(j+num[i]<=20)
                d[i][j] += d[i-1][j+num[i]];
        }
    }
    cout<<d[n-1][num[n]];
}
