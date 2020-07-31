//
// Created by 0864h on 2020-07-31.
//
#include<iostream>
using namespace std;
int N, M, num[10001], ans = 0;
void cal(int c, int sum)
{
    if(sum == M)
    {
        ans++;
        return;
    }
    if(sum > M || c > N)
        return;
    cal(c + 1, sum + num[c]);
}
int main()
{
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        cin >> num[i];
    for(int i = 1; i <= N; i++)
        cal(i, 0);
    cout << ans;
}
