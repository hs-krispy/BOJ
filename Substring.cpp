//
// Created by salmon11 on 2020-08-21.
//
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string p, s;
    char P[1000001], S[1000001], *ans;
    cin >> P >> S;
    ans = strstr(P, S);
    if(ans)
    {
        cout << 1;
        return 0;
    }
    cout << 0;
}
