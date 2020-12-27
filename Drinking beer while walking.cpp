//
// Created by 0864h on 2020-12-27.
//
#include <iostream>
#include <queue>
#include<vector>
#include<cstring>
using namespace std;
int t, n;
bool check[102];
vector<pair<int, int>> v;
queue<pair<int, int>> q;
int main()
{
    int hx, hy, fx, fy, x, y;
    cin >> t;
    while(t--)
    {
        bool  c =  false;
        cin >> n;
        cin >> hx >> hy;
        q.push({hx, hy});
        for(int i = 0; i < n; i++)
        {
            cin >> x >> y;
            v.emplace_back(x, y);
        }
        cin >> fx >> fy;
        v.emplace_back(fx, fy);
        while(!q.empty())
        {
            int nx = q.front().first;
            int ny = q.front().second;
            q.pop();
            if(nx == fx && ny == fy)
            {
                cout << "happy\n";
                c = true;
                break;
            }
            for(int i = 0; i < v.size(); i++)
            {
                if(!check[i])
                {
                    int dist = abs(nx - v[i].first) + abs(ny - v[i].second);
                    if(dist <= 1000)
                    {
                        check[i] = true;
                        q.push({v[i].first, v[i].second});
                    }
                }
            }
        }
        if(!c)
            cout << "sad\n";
        while(!q.empty())
            q.pop();
        while(!v.empty())
            v.pop_back();
        memset(check, false, sizeof(check));
    }
}
