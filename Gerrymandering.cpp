//
// Created by 0864h on 2020-05-14.
//
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<cstring>
using namespace std;
bool check[11], check2[11], check3[11];
int N, p[11], sum = 0, Min = INT_MAX;
vector<int> v[11];
vector<int> sector;
bool bfs1(int idx, int c1)
{
    queue<int> q;
    int count = 1;
    q.push(idx);
    check3[idx] = true;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i = 0; i < v[x].size(); i++)
        {
            if(check[v[x][i]] && !check3[v[x][i]])
            {
                check3[v[x][i]] = true;
                count++;
                q.push(v[x][i]);
            }
        }
    }
    return c1 == count;
}
bool bfs2(int idx, int c1)
{
    queue<int> q;
    int count = 1;
    q.push(idx);
    check2[idx] = true;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i = 0; i < v[x].size(); i++)
        {
            if(!check2[v[x][i]])
            {
                check2[v[x][i]] = true;
                count++;
                q.push(v[x][i]);
            }
        }
    }
    return N - c1 == count;
}
void dfs(int idx, int c, int val)
{
    if(c < N)
    {
        bool possible = false;
        memset(check3, false, sizeof(check3));
        for(int i = 1; i <= N; i++)
        {
            if(!check[i])
                check2[i] = false;
        }
        for(int i = 1; i <= N; i++)
        {
            if(check[i])
            {
                possible = bfs1(i, c);
                break;
            }
        }
        if(possible)
        {
            for(int i = 1; i <= N; i++)
            {
                if(!check2[i])
                {
                    possible = bfs2(i, c);
                    break;
                }
            }
        }
        if(possible && Min > abs(sum - 2 * val))
            Min = abs(sum - 2 * val);
    }
    for(int i = idx; i < N; i++)
    {
        if(!check[i])
        {
            check[i] = check2[i] = true;
            val += p[i];
            sector.push_back(i);
            dfs(i + 1, c + 1, val);
            sector.pop_back();
            val -= p[i];
            check[i] = check2[i] = false;
        }
    }
}
int main()
{
    int near, num, val = 0;
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> p[i];
        sum += p[i];
    }
    for(int i = 1; i <= N; i++)
    {
        cin >> near;
        for(int j = 1; j <= near; j++)
        {
            cin >> num;
            v[i].push_back(num);
        }
    }
    for(int i = 1; i <= N; i++)
    {
        check[i] = check2[i] = true;
        val += p[i];
        sector.push_back(i);
        dfs(i, 1, val);
        sector.pop_back();
        val -= p[i];
        check[i] = check2[i] = false;
    }
    if(Min == INT_MAX)
    {
        cout << -1;
        return 0;
    }
    cout << Min;
}