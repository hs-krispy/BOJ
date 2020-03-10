//
// Created by 0864h on 2020-03-10.
//
#include<iostream>
#include<queue>
#include <algorithm>
int p[101][101];
bool check[101][101];
int ans[101];
int dx[] = {0, 0, 1, -1};//우, 하, 상
int dy[] = {-1, 1, 0, 0};//우, 하, 상
using namespace std;
queue<pair<int, int>> q;
queue<int> res;
int main()
{
    int m,n,k,i,j,x,y,x1,y1,x2,y2,f,s,nx,ny,c=0,e=0;
    cin>>m>>n>>k;
    for(i=1;i<=k;i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (x=m-y2;x<=m-y1-1;x++)
        {
            for(y=x1;y<=x2-1;y++)
            {
                check[x][y]=true;
            }
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            e=0;
            if(check[i][j]==false) {
                e++;c++;
                q.push(make_pair(i, j));
                check[i][j] = true;
                while (!q.empty()) {
                    f = q.front().first;
                    s = q.front().second;
                    q.pop();
                    for (k = 0; k < 4; k++) {
                        nx = f + dx[k];
                        ny = s + dy[k];
                        if (ny>=0 && nx>=0 && nx<m && ny<n && check[nx][ny] == false) {
                            q.push(make_pair(nx, ny));
                            check[nx][ny] = true;
                            e++;
                        }
                    }
                }
                res.push(e);
            }
        }
    }
    cout<<c<<"\n";
    i=1;
    while(!res.empty())
    {
        ans[i] = res.front();
        i++;
        res.pop();
    }
    sort(&ans[1],&ans[i]);
    for(j=1;j<=i-1;j++)
        cout<<ans[j]<<" ";
}
