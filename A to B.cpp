//
// Created by 0864h on 2020-08-13.
//
#include<iostream>
#include<climits>
using namespace std;
int A, B, Min = INT_MAX;
void cal(long long val, int count)
{
    if(val >= B)
    {
        if(val == B && Min > count)
            Min = count;
        return;
    }
    cal(val * 2, count + 1);
    cal(val * 10 + 1, count + 1);
}
int main()
{
    cin >> A >> B;
    cal(A, 1);
    if(A == B)
    {
        cout << 0;
        return 0;
    }
    if(Min == INT_MAX)
    {
        cout << -1;
        return 0;
    }
    cout << Min;
}
