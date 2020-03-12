//
// Created by 0864h on 2020-03-10.
//
#include<iostream>
using namespace std;
int count = 0;
void gm(long long num, int a, int b)
{
    if (num>b)
        return;
    else if (num>=a && num<=b)
        count++;
    gm(num*10 + 4, a, b);
    gm(num*10 + 7, a, b);
}
int main()
{
    int a,b;
    cin>>a>>b;
    gm(0, a, b);
    cout<<count;
}
