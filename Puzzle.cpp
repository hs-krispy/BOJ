//
// Created by 0864h on 2021-01-19.
//
#include<iostream>
#include<set>
#include<queue>
using namespace std;
queue<pair<string, int>> q;
set<string> s;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int main()
{
    string init = "";
    char num;
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            cin >> num;
            init += num;
        }
    }
    s.insert(init);
    q.push({init, 0});
    while(!q.empty())
    {
        string st = q.front().first;
        int count = q.front().second;
        if(st == "123456780")
        {
            cout << count;
            return 0;
        }
        q.pop();
        int zero = st.find('0'); // 문자열에서 0의 위치
        // 2차원 좌표값으로 변형
        int x = zero / 3;
        int y = zero % 3;
        for(int i = 0; i < 4; i++)
        {
            string temp = st;
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < 3 && ny < 3)
            {
                swap(temp[x * 3 + y], temp[nx * 3 + ny]);
                // set에 존재하지 않는 문자열일때
                if(s.find(temp) == s.end())
                {
                    s.insert(temp);
                    q.push({temp, count + 1});
                }
            }
        }
    }
    cout << -1;
}
