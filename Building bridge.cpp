#include<iostream>
#include<queue>
#include<climits>
#include<vector>
#include<tuple>
#include<cstring>
using namespace std;
int N, map[101][101], Min = INT_MAX;
bool check[101][101];
vector<queue<tuple<int, int, int>>> v;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void field(int a, int b, int c)
{
    queue<pair<int, int>> q;
    queue<tuple<int, int, int>> q2;
    q.push({a, b});
    q2.push({a, b, 0});
    map[a][b] = c;
    check[a][b] = true;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 1 && ny >= 1 && nx <= N && ny <= N && !check[nx][ny] && map[nx][ny] == 1)
            {
                check[nx][ny] = true;
                q.push({nx, ny});
                q2.push({nx, ny, 0});
                map[nx][ny] = c;
            }
        }
    }
    v.push_back(q2);
}
int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
            cin >> map[i][j];
    }
    int num = 1;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(map[i][j] == 1 && !check[i][j])
            {
                field(i, j, num);
                num++;
            }
        }
    }
    for(int i = 0; i < v.size(); i++)
    {
        auto q = v[i];
        bool c = true;
        int num = i + 1;
        memset(check, false, sizeof(check));
        while(!q.empty())
        {
            int x, y, count;
            tie(x, y, count) = q.front();
            q.pop();
            for(int j = 0; j < 4; j++)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];
                int ncount = count + 1;
                if(nx >= 1 && ny >= 1 && nx <= N && ny <= N && !check[nx][ny] && map[nx][ny] == 0)
                {
                    check[nx][ny] = true;
                    q.push({nx, ny, ncount});
                }
                else if(nx >= 1 && ny >= 1 && nx <= N && ny <= N && map[nx][ny] != num && map[nx][ny] != 0)
                {
                    if(Min > count)
                        Min = count;
                    c = false;
                    break;
                }
            }
            if(!c)
                break;
        }
    }
    cout << Min;
}