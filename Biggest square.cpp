//
// Created by 0864h on 2021-02-19.
//
#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, d[1001][1001], Max = 0;
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            scanf("%1d", &d[i][j]);
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(d[i][j] == 1)
            {
                d[i][j] = min(d[i - 1][j - 1], min(d[i][j - 1], d[i - 1][j])) + 1;
                if(Max < d[i][j])
                    Max = d[i][j];
            }
        }
    }
    printf("%d", Max * Max);
}
