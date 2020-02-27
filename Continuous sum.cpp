//
// Created by 0864h on 2020-02-28.
//
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> d(100001,-1);
int main()
{
    int i,n,ans=0;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>d[i];
    for(i=2;i<=n;i++)
    {
        d[i] = max(d[i], d[i]+d[i-1]);
    }
    ans = *max_element(&d[1], &d[n+1]);
    cout<<ans;
}