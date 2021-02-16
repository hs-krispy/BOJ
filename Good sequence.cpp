//
// Created by 0864h on 2021-02-16.
//
#include<iostream>
#include<map>
using namespace std;
int N;
map<string, bool> seq;
void make_seq(string s, int check)
{
    if(s.length() == N)
    {
        cout << s;
        exit(0);
    }
    for(int i = 1; i <= 3; i++)
    {
        bool skip = false;
        if(i != check && !seq[s + to_string(i)])
        {
            string new_s = s + to_string(i);
            for(int j = 2; j <= 40; j++)
            {
                int div = new_s.length() / j;
                if(div >= 2)
                {
                    if(new_s.substr(new_s.length() - 2 * div, div) == new_s.substr(new_s.length() - div))
                    {
                        skip = true;
                        break;
                    }
                }
                else break;
            }
            if(skip)
                continue;
            seq[new_s] = true;
            make_seq(new_s, i);
        }
    }
}
int main()
{
    cin >> N;
    for(int i = 1; i <= 3; i++)
    {
        seq.insert({to_string(i), true});
        make_seq(to_string(i), i);
    }
}
