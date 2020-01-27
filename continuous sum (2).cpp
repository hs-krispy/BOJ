//
// Created by 0864h on 2020-01-25.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int i,n,max;
    vector<int> d1(100001);
    vector<int> d2(100001);
    vector<int> num(100001);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>num[i];
        d1[i]=d2[i]=num[i];
    }
    for(i=2;i<=n;i++)
    {
        if(0<d1[i-1])
            d1[i] += d1[i-1];//i번째수를 마지막으로하는 최대 연속합
    }
    for(i=n-1;i>=1;i--)
    {
        if(0<d2[i+1])
            d2[i] += d2[i+1];//i번째수를 시작으로하는 최대 연속합
    }
    max = d1[1];
    for(i=2;i<=n;i++)
    {
        if(d1[i]>max)
            max = d1[i];
    }
    for(i=2;i<=n-1;i++)
    {
       if(max < d1[i-1]+d2[i+1])
           max = d1[i-1]+d2[i+1];
    }
    cout<<max;
}
