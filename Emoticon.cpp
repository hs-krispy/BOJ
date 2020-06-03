//
// Created by 0864h on 2020-06-02.
//
#include<iostream>
#include<queue>
#include<climits>
using namespace std;
int s, screen[1001][1001], Min = INT_MAX;
void bfs()
{
    queue<pair<int, int>> q;
    screen[1][0] = 0;
    q.push({1, 0});
    while(!q.empty())
    {
        int e = q.front().first; // 화면에 이모티콘
        int cb = q.front().second; // 클립보드
        q.pop();
        if(screen[e][e] == 0) // 클립보드에 화면의 이모티콘 복사
        {
            screen[e][e] = screen[e][cb] + 1;
            q.push({e, e});
        }
        if(e + cb <= s && screen[e + cb][cb] == 0) // 화면에 클립보드 내용 붙여넣기
        {
            screen[e + cb][cb] = screen[e][cb] + 1;
            q.push({e + cb, cb});
        }
        if(e - 1 >= 0 && screen[e - 1][cb] == 0) // 화면에 있는 이모티콘 하나 삭제
        {
            screen[e - 1][cb] = screen[e][cb] + 1;
            q.push({e - 1, cb});
        }
    }
    for(int i = 0; i <= s; i++)
    {
        if(screen[s][i] != 0 && Min > screen[s][i])
            Min = screen[s][i];
    }
    cout << Min;
}
int main()
{
    cin >> s;
    bfs();
}
