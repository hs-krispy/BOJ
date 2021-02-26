#include<cstdio>
using namespace std;
int d[1000001][2];
int main()
{
    int n,i,temp;
    scanf("%d", &n);
    for(i = 2; i <= n; i++)
    {
        d[i][0] = d[i - 1][0] + 1;
        d[i][1] = i - 1;
        if(i % 2 == 0 && d[i][0] >= d[i / 2][0] + 1)
        {
            d[i][0] = d[i / 2][0] + 1;
            d[i][1] = i / 2;
        }
        if(i % 3 == 0 && d[i][0] >= d[i / 3][0] + 1)
        {
            d[i][0] = d[i / 3][0] + 1;
            d[i][1] = i / 3;
        }
    }
    printf("%d\n", d[n][0]);
    printf("%d ", n);
    while(true)
    {
        if(n == 1)
            break;
        printf("%d ", d[n][1]);
        n = d[n][1];
    }
}
