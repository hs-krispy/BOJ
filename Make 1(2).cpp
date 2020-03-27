//
// Created by 0864h on 2020-03-27.
//
#include<cstdio>
using namespace std;
int d[1000001][2];
int main()
{
    int n,i,temp;
    scanf("%d", &n);
    for(i=2;i<=n;i++)
    {
        d[i][0] = d[i-1][0]+1;
        d[i][1] = i-1;
        if(i%2==0 && d[i][0] >= d[i/2][0]+1)
        {
            d[i][0] = d[i/2][0]+1;
            d[i][1] = i/2;
        }
        if(i%3==0 && d[i][0] >= d[i/3][0]+1)
        {
            d[i][0] = d[i/3][0]+1;
            d[i][1] = i/3;
        }
    }
    printf("%d\n", d[n][0]);
    printf("%d ", n);
    temp = d[n][1];
    for(i=n-1;i>=2;i--)
    {
        if(temp==i)
        {
            temp = d[i][1];
            printf("%d ", i);
        }
    }
    printf("%d", 1);
}
