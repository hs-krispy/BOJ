//
// Created by 0864h on 2020-01-22.
//
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,i,j,c;
    long long sum=0;
    vector< vector<long long> > d;
    d.assign(1001, vector<long long>(10));
    cin>>n;
    for(i=0;i<=9;i++)
        d[1][i]=1;//한자리 숫자이고 0부터9까지인경우
    for(i=2;i<=n;i++)
    {
        for(j=0;j<=9;j++)
        {
            for(c=0;c<=j;c++)
            {
                d[i][j] += d[i-1][c];
                d[i][j] %= 10007;
            }
        }
    }
    for(j=0;j<=9;j++)
    {
        sum += d[n][j];
        sum %= 10007;
    }
    cout<<sum;
}
