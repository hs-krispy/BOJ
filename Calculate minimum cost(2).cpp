//
// Created by 0864h on 2020-09-08.
//
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int n, m, s, e, cost, dist[1001], from[1001];
vector<pair<int, int>> v[1001];
bool check[1001];
stack<int> st;
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &s, &e, &cost);
        v[s].emplace_back(e, cost);
    }
    for(int i = 1; i <= n; i++)
        dist[i] = 100000000;
    scanf("%d %d", &s, &e);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty())
    {
        int x = pq.top().second;
        pq.pop();
        if(!check[x]) {
            check[x] = true;
            for (int i = 0; i < v[x].size(); i++) {
                int nx = v[x][i].first;
                if (dist[nx] > dist[x] + v[x][i].second) {
                    dist[nx] = dist[x] + v[x][i].second;
                    pq.push({dist[nx], nx});
                    from[nx] = x; // 어디서 왔는지
                }
            }
        }
    }
    int num = 0, idx = e;
    st.push(e);
    while(idx != s)
    {
        st.push(from[idx]);
        idx = from[idx];
    }
    printf("%d\n", dist[e]);
    printf("%d\n", st.size());
    while(!st.empty())
    {
        printf("%d ", st.top());
        st.pop();
    }
}
