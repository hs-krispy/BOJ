//
// Created by 0864h on 2021-01-02.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, A, B, Max = 0;
vector<int> v[20001];
int count[20001];
bool check[20001];
queue<int> q;
int main()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> A >> B;
        v[A].push_back(B);
        v[B].push_back(A);
    }
    q.push(1);
    check[1] = true;
    count[1] = 0;
    while(!q.empty())
    {
        int num = q.front();
        q.pop();
        if(v[num].size() > 0)
        {
            for(int i = 0; i < v[num].size(); i++)
            {
                if(!check[v[num][i]])
                {
                    check[v[num][i]] = true;
                    q.push(v[num][i]);
                    count[v[num][i]] = count[num] + 1;
                }
            }
        }
    }
    int idx = 0;
    int c = 1;
    for(int i = 1; i <= N; i++)
    {
        if(Max < count[i])
        {
            idx = i;
            Max = count[i];
            c = 1;
            continue;
        }
        if(Max == count[i])
            c++;
    }
    cout << idx << " " << Max << " " << c;
}
