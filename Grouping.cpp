//
// Created by 0864h on 2020-04-06.
//
#include<iostream>
#include<algorithm>
using namespace std;
int  d[1001], num[1001];
int main()
{
    int i, j, n;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>num[i];
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=i;j++)
            d[i] = max(abs(num[i]-num[j])+d[j-1], d[i]);
    }
    cout<<d[n];
}
