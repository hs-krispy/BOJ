#include<cstdio>
using namespace std;
int arr[701][701], date[4], res[1400];
int main()
{
    int n, m, i, j;
    scanf("%d %d", &m, &n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d", &date[1], &date[2], &date[3]);
        for(j=1;j<=2*m-1;j++)
        {
            if(j<=date[1])
                res[j] += 0;
            else if(j<=date[1]+date[2])
                res[j] += 1;
            else
                res[j] += 2;
        }
    }
    for(i=m,j=1;i>=1;i--,j++)
        arr[i][1] = res[j];
    for(i=2,j;i<=m;i++,j++)
        arr[1][i] = res[j];
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(i>=2 && j>=2)
                printf("%d ", arr[1][j]+1);
            else printf("%d ", arr[i][j]+1);
        }
        printf("\n");
    }
}
