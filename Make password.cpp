//
// Created by 0864h on 2020-03-11.
//
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
bool check(string &password)
{
    int m=0, j=0;
    for(char x : password)
    {
        if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u')
            m += 1;
        else j += 1;
    }
    return m>=1 && j>=2;
}// 자음 2개이상 모음 1개이상의 조건을 검사
void go(int n, vector<char> &al, string password, int i)
{
    if(password.length() == n) {
        if(check(password))
            cout << password << "\n";
        return;
    }
    if(i==al.size()) return; // i의 값이 입력받은 알파벳의 갯수보다 커질경우
    go(n, al, password+al[i], i+1);
    go(n, al, password, i+1);
}
int main()
{
    int l,c,i;
    cin>>l>>c;
    vector<char> pw(c);
    for(i=0;i<c;i++)
    {
        cin>>pw[i];
    }
    sort(pw.begin(), pw.end());
    go(l, pw, "", 0);
}
