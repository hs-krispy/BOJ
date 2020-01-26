//
// Created by 0864h on 2020-01-25.
//
#include<iostream>
using namespace std;
int main()
{
    int i,sum;
    char c[4];
    cin>>c;
    if(c[0] == 'c')
        sum = 26;
    if(c[0] == 'd')
        sum = 10;
    for(i=1;i<4;i++)
    {
        if(c[i]=='c')
        {
            if(c[i] == c[i-1])
            {
                sum *= 25;
            }
            else sum *= 26;
        }
        else if(c[i]=='d')
        {
            if(c[i]==c[i-1])
            {
                sum *= 9;
            }
            else sum *= 10;
        }
    }
    cout<<sum;
}
