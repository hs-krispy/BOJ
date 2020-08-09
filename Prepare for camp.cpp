//
// Created by 0864h on 2020-08-09.
//
#include<iostream>
#include<climits>
using namespace std;
int N, L, R, X, p[16], count = 0;
bool check[16];
void find(int val, int min, int max, int idx, int c)
{
    int Min = min, Max = max;
    if(c == N && val >= L && val <= R && max - min >= X)
    {
        count++;
        return;
    }
    for(int i = idx; i <= N; i++)
    {
        if(!check[i])
        {
            if(Min > p[i])
                min = p[i];
            if(Max < p[i])
                max = p[i];
            check[i] = true;
            find(val + p[i], min, max, i + 1, c + 1);
            check[i] = false;
            find(val, Min, Max, i + 1, c + 1);
        }
    }
}
int main()
{
    cin >> N >> L >> R >> X;
    for(int i = 1; i <= N; i++)
        cin >> p[i];
    find(0, INT_MAX, 0, 1, 0);
    cout << count;
}
