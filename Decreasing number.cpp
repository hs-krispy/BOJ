//
// Created by 0864h on 2021-01-23.
//
#include<iostream>
#include<map>
using namespace std;
int N;
map<long long, bool> check;
void number(string s, int cmp)
{
    if(s.length() == 10 || check.size() == 1000000)
        return;
    long long num = 0;
   for(int i = 0; i < 10; i++)
   {
       if(cmp > i)
       {
           num = stoll(s + to_string(i));
           if(!check[num])
           {
               check[num] = true;
               number(s + to_string(i), i);
           }
       }
       else break;
   }
}
int main()
{
    cin >> N;
    for(int i = 0; i < 10; i++)
    {
        check[i] = true;
    }
    for(int i = 1; i < 10; i++)
        number(to_string(i), i);
    map<long long, bool>::iterator it;
    int count = 1;
    for(it=check.begin(); it!=check.end(); it++)
    {
        if(count == N)
        {
            cout << it->first;
            return 0;
        }
        count++;
    }
    cout << -1;
}
