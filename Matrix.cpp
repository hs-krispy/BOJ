//
// Created by 0864h on 2021-01-17.
//
#include <cstdio>
using namespace std;
int N, M, A[51][51], B[51][51], count = 0;
void flip(int n, int m)
{
    for(int i = n; i <= n + 2; i++)
    {
        for(int j = m; j <= m + 2; j++)
            A[i][j] = 1 - A[i][j];
    }
}
int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
            scanf("%1d", &A[i][j]);
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
            scanf("%1d", &B[i][j]);
    }
    for(int i = 1; i <= N - 2; i++)
    {
        for(int j = 1; j <= M - 2; j++)
        {
            if(A[i][j] != B[i][j])
            {
                flip(i, j);
                count++;
            }
        }
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            if(A[i][j] != B[i][j])
            {
                printf("%d", -1);
                return 0;
            }
        }
    }
    printf("%d", count);
}
