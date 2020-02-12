//
// Created by 0864h on 2020-02-12.
//
#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
    int n,i,num;
    scanf("%d", &n);
    for(i=1;i<=n*n;i++)
    {
        scanf("%d", &num);
        if(i<=n)
            pq.push(num);
        else if(i > n && pq.top()<num)
        {
            pq.pop(); pq.push(num);
        }
    }
    printf("%d", pq.top());
}
