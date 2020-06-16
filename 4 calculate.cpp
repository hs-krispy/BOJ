//
// Created by 0864h on 2020-06-11.
//
#include<iostream>
#include<queue>
#include<set>
using namespace std;
int s, t;
int main()
{
    cin >> s >> t;
    if(s == t)
    {
        cout << 0;
        return 0;
    }
    queue<pair<long long, string>> q;
    set<long long> set;
    q.push({s, ""});
    while(!q.empty())
    {
        long long c = q.front().first;
        string str = q.front().second;
        q.pop();
        long long nc = 0;
        string nstr = "";
        nc = c * c;
        if(nc >= 1 && nc <= t)
        {
            nstr = str + "*";
            if(nc == t)
            {
                cout << nstr;
                return 0;
            }
            if(set.count(nc) == 0)
            {
                set.insert(nc);
                q.push({nc, nstr});
            }
        }
        nc = c + c;
        if(nc >= 1 && nc <= t)
        {
            nstr = str + "+";
            if(nc == t)
            {
                cout << nstr;
                return 0;
            }
            if(set.count(nc) == 0)
            {
                set.insert(nc);
                q.push({nc, nstr});
            }
        }
        nc = c / c;
        if(nc >= 1 && nc <= t)
        {
            nstr = str + "/";
            if(nc == t)
            {
                cout << nstr;
                return 0;
            }
            if(set.count(nc) == 0)
            {
                set.insert(nc);
                q.push({nc, nstr});
            }
        }
    }
    cout << -1;
}
