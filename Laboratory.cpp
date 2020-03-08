//
// Created by 0864h on 2020-03-08.
//
#include<iostream>
#include<queue>
using namespace std;
int map[9][9], ch[9][9];
int dx[] = {-1, 1, 0, 0};//상,하,좌,우
int dy[] = {0, 0, -1, 1};//상,하,좌,우
int n,m;
queue<pair<int, int>> q;
int bfs()
{
    int i,j,x,y,c=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            ch[i][j] = map[i][j];
            if(ch[i][j]==2)
                q.push(make_pair(i,j));
        }
    }
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx>=1 && ny>=1 && nx<=n && ny<=m) {
                if (ch[nx][ny] == 0) {
                    ch[nx][ny] = 2;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(ch[i][j]==0)
                c++;
        }
    }
    return c;
}
int main()
{
    int i,j,x1,y1,x2,y2,x3,y3,max=0,count=0;
    cin>>n>>m;
    for(i=1;i<=n;i++) {
        for (j = 1; j <= m; j++)
        {
            cin >> map[i][j];
        }
    }
    for(x1=1;x1<=n;x1++)
    {
        for(y1=1;y1<=m;y1++)
        {
            if(map[x1][y1]!=0) continue;
            for(x2=1;x2<=n;x2++)
            {
                for(y2=1;y2<=m;y2++)
                {
                    if (map[x2][y2] != 0 || (x1==x2 && y1==y2)) continue;
                    for(x3=1;x3<=n;x3++)
                    {
                        for(y3=1;y3<=m;y3++)
                        {
                            if(map[x3][y3]!=0) continue;
                            if(x1==x3 && y1==y3) continue;
                            if(x2==x3 && y2==y3) continue;
                            map[x1][y1]=1; map[x2][y2]=1; map[x3][y3]=1;
                            count = bfs();
                            map[x1][y1]=0; map[x2][y2]=0; map[x3][y3]=0;
                            if(max<=count)
                                max=count;
                        }
                    }
                }
            }
        }
    }
    cout<<max;
}
