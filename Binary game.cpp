//
// Created by 0864h on 2020-02-27.
//
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int i,c1=0,c2=0;
    string a,b;
    cin>>a>>b;
    for(i=0;i<a.length();i++)
        if(a[i]=='1')
            c1++;
    for(i=0;i<b.length();i++)
        if(b[i]=='1')
            c2++;
    if((c1%2==0&&c1<c2)||(c1%2==1&&c1+1<c2))
        cout<<"DEFEAT";
    else
        cout<<"VICTORY";
}
