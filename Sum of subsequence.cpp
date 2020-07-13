//
// Created by 0864h on 2020-07-12.
//
#include<iostream>
using namespace std;
int N, S[21];
bool check[2000001];
void cal(int i, int c) // 부분수열의 합으로 나올 수 있는 모든 경우를 조사
{
    if(i == N + 1)
    {
        check[c] = true;
        return;
    }
    cal(i + 1, c + S[i]);
    cal(i + 1, c);
}
int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> S[i];
    cal(1, 0);
    for(int i = 1; ; i++)
    {
        if(!check[i])
        {
            cout << i;
            return 0;
        }
    }
}
