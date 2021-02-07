//
// Created by 0864h on 2021-02-02.
//
#include<iostream>
#include<vector>
using namespace std;
int N, count[51], Max = 0;
bool check[51][51];
char f;
vector<char> v[51];
void find(int s, int e)
{
    for(int i = 0; i < v[e].size(); i++)
    {
        if(!check[s][i] && v[e][i] == 'Y')
        {

            check[s][i] = check[i][s] = true;
            count[s]++;
            count[i]++;
        }
    }
}
int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> f;
            v[i].push_back(f);
            if(i == j)
                check[i][j] = true;
            if(!check[i][j] && f == 'Y')
            {
                count[i]++;
                count[j]++;
                check[i][j] = check[j][i] = true;
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            if(v[i][j] == 'Y')
            {
                find(i, j);
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        if(Max < count[i])
            Max = count[i];
    }
    cout << Max;
}

