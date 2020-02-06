//
// Created by 0864h on 2020-02-04.
//
#include<iostream>
#include<algorithm>
using namespace std;
int w[101],v[101],d[100001];
int main()
{
    int i,j,n,k;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin >> w[i] >> v[i];//i번째 물건의 무게와 가치입력
    }
    for(i=1;i<=n;i++)
    {
        for(j=k;j>=1;j--)
        {
            if(j-w[i]>=0)
            {
                d[j] = max(d[j], d[j-w[i]]+v[i]);//무게가 j일때 가치의 최대값
            }
        }
    }
    cout<<d[k];
}
