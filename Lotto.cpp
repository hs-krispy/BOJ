//
// Created by 0864h on 2020-03-20.
//
#include<cstdio>
#include<vector>
#include <algorithm>

using namespace std;
int main()
{
    vector<int> lt(13);
    vector<int> temp(13);
    int i,k;
    while(true) {
        scanf("%d", &k);
        if(k==0)
            break;
        for (i = 1; i <= k; i++)
            scanf("%d", &lt[i]);
        for(i=1;i<=6;i++)
            temp[i] = 1;
        for(i=7;i<=k;i++)
            temp[i] = 0;
        do{
            for(i=1;i<=k;i++)
            {
                if(temp[i]==1)
                {
                    printf("%d ",lt[i]);
                }
            }
            printf("\n");
        }while(prev_permutation(&temp[1], &temp[k+1]));
        printf("\n");
    }
}