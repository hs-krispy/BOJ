//
// Created by 0864h on 2020-09-14.
//
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int T;
bool check[10000];
int main()
{
    cin >> T;
    int A, B;
    for(int i = 0; i < T; i++)
    {
        memset(check, false, sizeof(check));
        queue<pair<int, string>> q;
        cin >> A >> B;
        q.push({A, ""});
        check[A] = true;
        while(!q.empty())
        {
            int num = q.front().first;
            string s = q.front().second;
            if(num == B)
            {
                cout << s <<"\n";
                break;
            }
            q.pop();
            for(int j = 1; j <= 4; j++)
            {
                if(j == 1)
                {
                    int nnum = num * 2;
                    if(nnum > 9999)
                        nnum %= 10000;
                    if(!check[nnum])
                    {
                        check[nnum] = true;
                        q.push({nnum, s + 'D'});
                    }
                }
                if(j == 2)
                {
                    int nnum = num - 1;
                    if(num <= 0) nnum = 9999;
                    if(!check[nnum])
                    {
                        check[nnum] = true;
                        q.push({nnum, s + 'S'});
                    }
                }
                if(j == 3)
                {
                    int nnum = (num % 1000) * 10 + num / 1000;
                    if(!check[nnum])
                    {
                        check[nnum] = true;
                        q.push({nnum, s + 'L'});
                    }
                }
                if(j == 4)
                {
                    int nnum = (num % 10) * 1000 + (num / 10);
                    if(!check[nnum])
                    {
                        check[nnum] = true;
                        q.push({nnum, s + 'R'});
                    }
                }
            }
        }
    }
}
