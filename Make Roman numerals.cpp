//
// Created by 0864h on 2020-08-13.
//
#include<iostream>
using namespace std;
int N, count = 0, val[5] = {0, 1, 5, 10, 50};
bool check[1001];
void cal(int c, int idx, int sum)
{
    if(c == N)
    {
        if(!check[sum])
        {
            count++;
            check[sum] = true;
        }
        return;
    }
    for(int i = idx; i <= 4; i++)
        cal(c + 1, i, sum + val[i]);
}
int main()
{
    cin >> N;
    cal(0, 1, 0);
    cout << count;
}
