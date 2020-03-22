//
// Created by 0864h on 2020-03-22.
//
#include<cstdio>
#include<algorithm>
using namespace std;
int d[201][2];
int main()
{
    int n,i,j,ans=0;
    scanf("%d", &n);
    for(i=1;i<=n;i++)
        scanf("%d", &d[i][0]);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(d[i][0]>d[j][0])
                d[i][1] = max(d[i][1], d[j][1]+1);
        }
        if(ans<=d[i][1])
            ans=d[i][1];
    }
    printf("%d", n-ans);
}
