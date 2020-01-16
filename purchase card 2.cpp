//
// Created by 0864h on 2020-01-14.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int i, j, n, temp;
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
        temp=p[i];//처음 비교값에 한번에 카드를 사는 가격을 넣어둠
        for(j=1;j<=i;j++)
        {
            if(temp >= d[i-j]+p[j])//카드를 사는 가격이 한번에 카드를 사는 가격보다 작거나 같은 경우
            {
                d[i] = d[i - j] + p[j];
                temp = d[i];
            }
        }
    }
    cout<<d[n];
} 
