//
// Created by 0864h on 2020-01-28.
//
#include<iostream>
#include<vector>
using namespace std;
int n, Max = 0;
vector<pair<int, int>> v;
bool check[8][8];
void break_egg(int idx, int count)
{
    if(idx == n)
    {
        if(Max < count)
            Max = count;
        return;
    }
    if(v[idx].first <= 0)
        break_egg(idx + 1, count);
    else
    {
        bool c = false;
        for(int i = 0; i < v.size(); i++)
        {
            if(i != idx && !check[idx][i] && v[i].first > 0)
            {
                c = true;
                v[idx].first -= v[i].second;
                v[i].first -= v[idx].second;
                if(v[idx].first <= 0)
                {
                    if(v[i].first <= 0)
                        break_egg(idx + 1, count + 2);
                    else break_egg(idx + 1, count + 1);
                }
                else
                {
                    if(v[i].first <= 0)
                        break_egg(idx + 1 , count + 1);
                    else
                        break_egg(idx + 1, count);
                }
                v[idx].first += v[i].second;
                v[i].first += v[idx].second;
            }
        }
        if(!c)
            break_egg(idx + 1, count);
    }
}
int main()
{
    int s, w;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> s >> w;
        v.emplace_back(s, w);
    }
    break_egg(0, 0);
    cout << Max;
}