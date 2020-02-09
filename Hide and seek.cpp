//
// Created by 0864h on 2020-02-09.
//
#include<iostream>
#include<queue>
using namespace std;
bool check[100001];
int dis[100001];
int main()
{
    int n,k,s;
    cin>>n>>k;
    dis[n] = 0;
    check[n] = true;
    queue<int> q;
    q.push(n);
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        if(s-1 >= 0)
        {
            if(check[s-1] == false)//s-1로 이동한경우
            {
                q.push(s-1);
                check[s-1] = true;
                dis[s-1] = dis[s]+1;
            }
        }
        if(s+1 <= k+1)
        {
            if (check[s+1] == false)//s+1로 이동한경우
            {
                q.push(s+1);
                check[s+1] = true;
                dis[s+1] = dis[s]+1;
            }
        }
        if(s*2 <= k+1)
        {
            if(check[s*2] == false)//2*s로 이동한경우
            {
                q.push(s*2);
                check[s*2] = true;
                dis[s*2] = dis[s]+1;
            }
        }
    }
    cout<<dis[k];
    return 0;
}
