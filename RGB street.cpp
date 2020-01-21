//
// Created by 0864h on 2020-01-19.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int i,n,price=0;
    vector< vector<int> > d;
    d.assign(1001, vector<int>(4,0));
    cin>>n; //집의 수
    vector< vector<int> > v;
    v.assign(1001, vector<int>(4,0));
    for(i=1;i<=n;i++)
    {
        cin>>v[i][1]>>v[i][2]>>v[i][3];
    }
    d[1][1]=v[1][1];d[1][2]=v[1][2];d[1][3]=v[1][3];//첫 번째집을 지을때 빨강, 초록, 파랑으로 집을 짓는 비용
    for(i=2;i<=n;i++)
    {
        d[i][1] = min(d[i-1][2], d[i-1][3])  + v[i][1];//i개의 집을 지을때 마지막집을 빨강으로 하는경우
        d[i][2] = min(d[i-1][1], d[i-1][3])  + v[i][2];//i개의 집을 지을때 마지막집을 초록으로 하는경우
        d[i][3] = min(d[i-1][1], d[i-1][2])  + v[i][3];//i개의 집을 지을때 마지막집을 파랑으로 하는경우
     }
    price = min({d[n][1],d[n][2],d[n][3]});
    cout<<price;
}
 
