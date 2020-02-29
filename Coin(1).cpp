//
// Created by 0864h on 2020-02-29.
//
#include<cstdio>
using namespace std;
int num[101], d[10001];
int main()
{
    int i,j,n,k;
    scanf("%d %d",&n ,&k);
    for(i=1;i<=n;i++)
        scanf("%d", &num[i]);
    d[0] = 1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(j-num[i]>=0)
                d[j] += d[j-num[i]];
        }
    }
    printf("%d", d[k]);
}
