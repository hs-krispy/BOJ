//
// Created by 0864h on 2020-08-22.
//
#include<iostream>
#include<vector>
using namespace std;
int arr[10][10];
bool rcheck[10][10], ccheck[10][10], scheck[4][4][10];
vector<pair<int, int>> v;
void fill(int r, int c, int count)
{
    int x = 0, y = 0;
    if(r % 3 == 0)
    {
        x = r / 3;
        if(c % 3 == 0)
            y = c / 3;
        else if(c % 3 > 0)
            y = c / 3 + 1;
    }
    else if(r % 3 > 0)
    {
        x = r / 3 + 1;
        if(c % 3 == 0)
            y = c / 3;
        else if(c % 3 > 0)
        {
            y = c / 3 + 1;
        }
    }
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
                cout << arr[i][j] << " ";
            }
            cout << "\n";
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
    for(int i = 1; i <= 9; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 0)
                v.emplace_back(i, j);
            if(arr[i][j] > 0)
            {
                rcheck[i][arr[i][j]] = true;
                ccheck[j][arr[i][j]] = true;
            }
            if(i % 3 == 0)
            {
                if(j % 3 == 0)
                    scheck[i / 3][j / 3][arr[i][j]] = true;
                else scheck[i / 3][j / 3 + 1][arr[i][j]] = true;
            }
            else
            {
                if(j % 3 == 0)
                    scheck[i / 3 + 1][j / 3][arr[i][j]] = true;
                else scheck[i / 3 + 1][j / 3 + 1][arr[i][j]] = true;
            }
        }
    }
    if(v.empty())
    {
        for(int i = 1; i <= 9; i++)
        {
            for(int j = 1; j <= 9; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        return 0;
    }
    fill(v[0].first, v[0].second, 0);
}
