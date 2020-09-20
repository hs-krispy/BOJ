//
// Created by 0864h on 2020-09-20.
//
#include<iostream>
#include<vector>
using namespace std;
int n, p1, p2, m, r1, r2;
vector<int> v[101];
bool check[101];
void count(int idx, int c)
{
    if(idx == p2)
    {
        cout << c;
        exit(0);
    }
    for(int i = 0; i < v[idx].size(); i++)
    {
        if(!check[v[idx][i]])
        {
            check[v[idx][i]] = true;
            count(v[idx][i], c + 1);
        }
    }
}
int main()
{
    cin >> n >> p1 >> p2 >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> r1 >> r2;
        v[r1].push_back(r2);
        v[r2].push_back(r1);
    }
    check[p1] = true;
    count(p1, 0);
    cout << -1;
}
