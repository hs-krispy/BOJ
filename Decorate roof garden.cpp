//
// Created by 0864h on 2020-10-03.
//
#include<iostream>
#include<stack>
using namespace std;
int N, height;
long long count = 0;
int main()
{
    cin >> N;
    stack<int> s;
    for(int i = 1; i <= N; i++)
    {
        cin >> height;
        while(!s.empty() && s.top() <= height)
            s.pop();
        count += s.size(); // 남아있는 건물들은 그 건물을 볼 수 있는 건물
        s.push(height);
    }
    cout << count;
}
