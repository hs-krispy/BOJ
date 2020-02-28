//
// Created by 0864h on 2020-02-28.
//
#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int ans[500001];
int main()
{
    stack<pair<int, int>> s;
    int i,n, height;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%d", &height);
        if(i==1)
            s.push(make_pair(height, i));
        else if(i>=2) {
            if (s.top().first >= height) {
                ans[i] = s.top().second;
                s.push(make_pair(height, i));
            } else {
                while (!s.empty())
                {
                    if(height<s.top().first)
                        break;
                    s.pop();
                }
                if(s.empty())
                {
                    ans[i] = 0;
                    s.push(make_pair(height, i));
                }
                else {
                    ans[i] = s.top().second;
                    s.push(make_pair(height, i));
                }
            }
        }
    }
    for(i=1;i<=n;i++)
        printf("%d ", ans[i]);
}
