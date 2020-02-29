//
// Created by 0864h on 2020-03-01.
//
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main()
{
    int n,k,i,j,num[11],res=100000001,div;
    vector<int> ans(11);
    cin>>n>>k;
    for(i=1;i<=n;i++)
        cin>>num[i];
    for(i=n;i>=1;i--)
    {
        if(num[i]>k)
            continue;
        ans[i] = k/num[i];
        div = k%num[i];
        for(j=i-1;j>=1;j--)
        {
            if(div/num[j]>=1) {
                ans[i] += div / num[j];
                div %= num[j];
            }
            else continue;
        }
        res = min(ans[i], res);
    }
    cout<<res;
}
