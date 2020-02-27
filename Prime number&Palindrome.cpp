//
// Created by 0864h on 2020-02-28.
//
#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool pn[1100001];
int main()
{
    int num,i,j;
    string str1;
    stack<char> s, empty;
    cin>>num;
    if(num==1)
        cout<<2;
    else {
        for (i = 2; i <= 550000; i++) {
            for (j = i + i; j <= 1100000; j += i)
                pn[j] = true;//소수가 아닌수 true 로
        }
        for (i = num; i <= 1100000; i++) {
            if (pn[i] == false) {
                str1 = to_string(i);
                for (j = 0; j < str1.length(); j++) {
                    s.push(str1[j]);
                }
                for (j = 0; j < str1.length(); j++) {
                    if (str1[j] == s.top()) {
                        s.pop();
                    } else
                        break;
                }
                if (s.empty()) {
                    cout << i;
                    break;
                }
                s = empty;
            } else
                continue;
        }
    }
}