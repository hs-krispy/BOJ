//
// Created by 0864h on 2020-03-31.
//
#include<iostream>
#include<set>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n,i;
    string name,check;
    cin>>n;
    set<string, greater<>> s;
    for(i=1;i<=n;i++)
    {
        cin>>name>>check;
        if(check=="enter") s.insert(name);
        else s.erase(name);
    }
    set<string>::iterator iter;
    for(iter=s.begin();iter!=s.end();iter++)
            cout<<*iter<<"\n";
}
