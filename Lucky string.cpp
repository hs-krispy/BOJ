//
// Created by 0864h on 2021-02-17.
//
#include<iostream>
#include<algorithm>
using namespace std;
string S;
int main() {
    cin >> S;
    int count = 0;
    sort(S.begin(), S.end());
    do {
        bool check = true;
        for(int i = 0; i < S.length() - 1; i++)
        {
            if(S[i] == S[i + 1])
            {
                check = false;
                break;
            }
        }
        if(check)
            count++;
    } while (next_permutation(S.begin(), S.end()));
    cout << count;
}
