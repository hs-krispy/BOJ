//
// Created by 0864h on 2020-02-29.
//
#include<algorithm>
#include<cstdio>
#include <cstring>
using namespace std;
int num[101], d[10001];
int main()
{
    int i,j,n,k;
    scanf("%d %d",&n ,&k);
    for(i=1;i<=n;i++)
        scanf("%d", &num[i]);
    memset(d, 10001, sizeof(d));
    d[0] = 0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(j-num[i]>=0)
            {
                d[j] = min(1+d[j-num[i]], d[j]);
            }
        }
    }
    if(d[k]>10000 || d[k]<1)
        printf("%d", -1);
    else
        printf("%d", d[k]);
}

