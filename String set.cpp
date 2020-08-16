//
// Created by 0864h on 2020-08-16.
//
#include<iostream>
#include<map>
using namespace std;
int N, M;
int main()
{
    cin >> N >> M;
    int ans = 0;
    string s;
    map<string, int> m;
    for(int i = 1; i <= N; i++)
    {
        cin >> s;
        m.insert({s, 1});
    }
    for(int i = 1; i <= M; i++)
    {
        cin >> s;
        if(m[s])
            ans += 1;
    }
    cout << ans;
}
