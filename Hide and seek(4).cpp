//
// Created by 0864h on 2020-03-08.
//
#include<iostream>
#include<cstdio>
#include<queue>
#include <stack>
using namespace std;
bool check[100002];
int dis[100002];
int main()
{
    int n,k,s,res=-1;
    cin>>n>>k;
    dis[n] = 0;
    check[n] = true;
    queue<int> q;
    stack<pair<int, int>> ans;
    stack<int> st;
    q.push(n);
    ans.push(make_pair(n, 0));
    if(n==k)
        cout<<0<<"\n"<<n;
    else {
        while (!q.empty()) {
            s = q.front();
            q.pop();
            if(s==k)
                break;
            if (s - 1 >= 0) {
                if (check[s - 1] == false)//s-1로 이동한경우
                {
                    q.push(s - 1);
                    ans.push(make_pair(s - 1, s));
                    check[s - 1] = true;
                    dis[s - 1] = dis[s] + 1;
                }
            }
            if (s + 1 <= k) {
                if (check[s + 1] == false)//s+1로 이동한경우
                {
                    q.push(s + 1);
                    ans.push(make_pair(s + 1, s));
                    check[s + 1] = true;
                    dis[s + 1] = dis[s] + 1;
                }
            }
            if (s * 2 <= k + 1) {
                if (check[s * 2] == false)//2*s로 이동한경우
                {
                    q.push(s * 2);
                    ans.push(make_pair(s * 2, s));
                    check[s * 2] = true;
                    dis[s * 2] = dis[s] + 1;
                }
            }
        }
        cout << dis[k] << "\n";
        while (!ans.empty()) {
            if (res == n)
                break;
            if (ans.top().first == k) {
                res = ans.top().second;
                st.push(k);
                st.push(res);
            }
            if (ans.top().first == res) {
                res = ans.top().second;
                st.push(res);
            }
            ans.pop();
        }
        while (!st.empty()) {
            printf("%d ", st.top());
            st.pop();
        }
    }
}

