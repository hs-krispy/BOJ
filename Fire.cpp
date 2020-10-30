//
// Created by 0864h on 2020-10-30.
//
#include<iostream>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool check[1001][1001];
char building[1001][1001];
queue<tuple<int, int, int>> q;
queue<tuple<int, int, int>> f;
int T, w, h;
int main()
{
    cin >> T;
    while(T--)
    {
        cin >> w >> h;
        bool escape = false;
        for(int i = 1; i <= h; i++)
        {
            for(int j = 1; j <= w; j++)
            {
                cin >> building[i][j];
                if(building[i][j] == '@')
                {
                    check[i][j] = true;
                    q.push({i, j, 0});
                }
                if(building[i][j] == '*')
                {
                    f.push({i, j, 0});
                }
            }
        }
        int c = 0;
        while(!q.empty())
        {
            int x, y, t;
            tie(x, y, t) = q.front();
            q.pop();
            if(x == 1 || x == h || y == 1 || y == w)
            {
                escape = true;
                cout << t + 1 << "\n";
                while(!q.empty())
                    q.pop();
                break;
            }
            while(t == c)
            {
                if(f.empty())
                {
                    c++;
                    break;
                }
                int fx, fy, ft;
                tie(fx, fy, ft) = f.front();
                if(c < ft)
                {
                    c++;
                    break;
                }
                f.pop();
                for(int i = 0; i < 4; i++)
                {
                    int nfx = fx + dx[i];
                    int nfy = fy + dy[i];
                    int nft = ft + 1;
                    if(nfx >= 1 && nfy >= 1 && nfx <= h && nfy <= w && building[nfx][nfy] != '#' && building[nfx][nfy] != '*')
                    {
                        building[nfx][nfy] = '*';
                        f.push({nfx, nfy, nft});
                    }
                }
            }
            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nt = t + 1;
                if(nx >= 1 && ny >= 1 && nx <= h && ny <= w && building[nx][ny] == '.' && !check[nx][ny])
                {
                    check[nx][ny] = true;
                    q.push({nx, ny, nt});
                }
            }
        }
        if(!escape)
            cout << "IMPOSSIBLE\n";
        while(!f.empty())
            f.pop();
        memset(building, 0, sizeof(building));
        memset(check, false, sizeof(check));
    }
}
