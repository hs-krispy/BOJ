//
// Created by 0864h on 2020-02-23.
//
#include<iostream>
#include<queue>
#include <cstring>
using namespace std;
int main() {
    bool check[10000];
    bool visit[10000];
    queue<pair<int, int>> q;
    queue<pair<int, int>> empty;
    int T, i, j, t, num1, num2, num = 0, count = 0, val;
    check[2] = true;
    for (i = 2; i <= 9999; i++) {
        for (j = i + i; j <= 9999; j += i)
            check[j] = true;//소수가 아닌 수 체크
    }
    cin >> T;
    for (t = 0; t < T; t++) {
        cin >> num1 >> num2;
        if (t >= 1) {
            q = empty;
            memset(visit, false, sizeof(visit));
        }
        q.push(make_pair(0, num1));
        if (num1 == num2)
            cout << 0 <<"\n";
        else {
            while (!q.empty()) {
                num1 = q.front().second;
                count = q.front().first + 1;
                q.pop();
                for (i = 0; i <= 9; i++) {
                    val = num1;
                    for (j = 1000; j >= 1; j /= 10) {
                        if (j == 1000)
                            num = num1 % j + j * i;
                        else
                            num = num1 - val / j * j + j * i;
                        if (num >= 1000 && check[num] == false && visit[num] == false) {
                            q.push(make_pair(count, num));
                            visit[num] = true;
                            if(num==num2)
                                goto res;
                        }
                        val %= j;
                    }
                }
            }
            res:
            cout << q.back().first << "\n";
            if(visit[num2]==false)
                cout << "Impossible"<<"\n";
        }
    }
}

