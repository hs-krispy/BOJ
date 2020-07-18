//
// Created by 0864h on 2020-07-18.
//
#include<iostream>
using namespace std;
int N, S, num[21], ans = 0;
void cal(int i, int c)
{
    if(i == N + 1 && c == S)
    {
        ans++;
        return;
    }
    if(i == N + 1) return;
    cal(i + 1, c + num[i]);
    cal(i + 1, c);
}
int main()
{
    cin >> N >> S;
    for(int i = 1; i <= N; i++)
        cin >> num[i];
    cal(1, 0);
    if(S == 0)
        ans--;
    cout << ans;
}

