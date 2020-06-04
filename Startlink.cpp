//
// Created by 0864h on 2020-06-04.
//
#include<iostream>
#include<queue>
using namespace std;
int F, S, G, U, D, bt[1000001];
void bfs()
{
    queue<int> q;
    q.push(S);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        if(now + U <= F && bt[now + U] == -1)
        {
            q.push(now + U);
            bt[now + U] = bt[now] + 1;
        }
        if(now <= F && now - D >= 1 && bt[now - D] == -1)
        {
            q.push(now - D);
            bt[now - D] = bt[now] + 1;
        }
        if(bt[G] > -1)
        {
            cout << bt[G];
            break;
        }
    }
}
int main()
{
    cin >> F >> S >> G >> U >> D;
    for(int i = 1; i <= 1000000; i++)
        bt[i] = -1;
    bt[S] = 0;
    bfs();
    if(bt[G] == -1)
        cout << "use the stairs";
}
