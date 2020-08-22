//
// Created by 0864h on 2020-08-23.
//
#include<cstdio>
#include<vector>
#include <cstdlib>
using namespace std;
int arr[10][10];
bool rcheck[10][10], ccheck[10][10], scheck[4][4][10];
vector<pair<int, int>> v;
vector<pair<int, int>> v2;
void fill(int r, int c, int count)
{
    int x = v2[count].first, y = v2[count].second;
    if(count == v.size() - 1)
    {
        for(int i = 1; i <= 9; i++)
        {
            if(!rcheck[r][i] && !ccheck[c][i] && !scheck[x][y][i])
            {
                rcheck[r][i] = true;
                ccheck[c][i] = true;
                scheck[x][y][i] = true;
                arr[r][c] = i;
            }
        }
        for(int i = 1; i <= 9; i++)
        {
            if(!rcheck[r][i] && !ccheck[c][i] && !scheck[x][y][i])
                return;
        }
        for(int i = 1; i <= 9; i++)
        {
            for(int j = 1; j <= 9; j++)
            {
                printf("%d", arr[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }
    for(int i = 1; i <= 9; i++)
    {
        if(!rcheck[r][i] && !ccheck[c][i] && !scheck[x][y][i])
        {
            rcheck[r][i] = true;
            ccheck[c][i] = true;
            scheck[x][y][i] = true;
            arr[r][c] = i;
            fill(v[count + 1].first, v[count + 1].second, count + 1);
            arr[r][c] = 0;
            rcheck[r][i] = false;
            ccheck[c][i] = false;
            scheck[x][y][i] = false;
        }
    }
}
int main()
{
    int x = 0, y = 0;
    for(int i = 1; i <= 9; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            scanf("%1d", &arr[i][j]);
            if(i % 3 == 0)
            {
                x = i / 3;
                if(j % 3 == 0)
                    y = j / 3;
                else y = j / 3 + 1;
            }
            else
            {
                x = i / 3 + 1;
                if(j % 3 == 0)
                    y = j / 3;
                else y = j / 3 + 1;
            }
            if(arr[i][j] > 0)
            {
                rcheck[i][arr[i][j]] = true;
                ccheck[j][arr[i][j]] = true;
                scheck[x][y][arr[i][j]] = true;
            }
            if(arr[i][j] == 0)
            {
                v.emplace_back(i, j);
                v2.emplace_back(x, y);
            }
        }
    }
    if(v.empty())
    {
        for(int i = 1; i <= 9; i++)
        {
            for(int j = 1; j <= 9; j++)
            {
                printf("%d", arr[i][j]);
            }
            printf("\n");
        }
        return 0;
    }
    fill(v[0].first, v[0].second, 0);
}

