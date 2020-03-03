//
// Created by 0864h on 2020-03-02.
//
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n, i;
    long long d[101];
    cin>>n;
    for(i=1;i<=6;i++)
        d[i] = i;
    for(i=7;i<=n;i++)
    {
        d[i] = max({2*d[i-3], 3*d[i-4], 4*d[i-5]});
    }
    cout<<d[n];
}
