//
// Created by 0864h on 2020-01-14.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int i, j, n;
    cin>>n;//구매하려는 카드의 갯수
    vector<int> p(n+1);
    vector<int> d(n+1);
    for(i=1;i<=n;i++)
    {
        cin>>p[i];//카드 i개가 포함된 카드팩의 가격
    }
    d[0]=0; d[1]=p[1];
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            d[i] = max(d[i], d[i - j] + p[j]);
        }
    }
    cout<<d[n];
}
