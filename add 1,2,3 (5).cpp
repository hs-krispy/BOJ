//
// Created by 0864h on 2020-01-16.
//
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector< vector<long long> > d;//2차원 벡터 선언
    d.assign(100001, vector<long long>(4, 0));//벡터로 2차원 배열만들기 assign 앞에 인자는 행, 뒤에인자는 열 + 초기화값
    int i,n,val;
    long long div = 1000000009;
    cin>>n;//테스트 케이스의 수
    for(i=1;i<=100000;i++)
    {
        if(i-1>=0) {
            if (i == 1) {
                d[i][1] = 1;
            }
            else
                d[i][1] = d[i - 1][2] + d[i - 1][3];//정수 i에서 1을 뺀 수 중 끝자리가 2, 3인 경우의 합(중복X)
        }
        if(i-2>=0) {
            if (i == 2) {
                d[i][2] = 1;
            }
            else
                d[i][2] = d[i - 2][1] + d[i - 2][3];//정수 i에서 2를 뺀 수 중 끝자리가 1, 3인 경우의 합(중복X)
        }
        if(i-3>=0) {
            if (i == 3) {
                d[i][3] = 1;
            }
            else
                d[i][3] = d[i - 3][1] + d[i - 3][2];//정수 i에서 3을 뺀 수 중 끝자리가 1, 2인 경우의 합(중복X)
        }
        d[i][1] %= div;
        d[i][2] %= div;
        d[i][3] %= div;
    }
    for(i=0;i<n;i++)
    {
        cin>>val;
        cout<<(d[val][1]+d[val][2]+d[val][3])%div<<"\n";
    }
}
