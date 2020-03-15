//
// Created by 0864h on 2020-03-15.
//
#include<cstdio>
#include <algorithm>
using namespace std;
int num[500001], num2[500001];
int main()
{
    int n, m, i, left, right, mid;
    scanf("%d", &n);
    for(i=1;i<=n;i++)
        scanf("%d", &num[i]);
    scanf("%d", &m);
    for(i=1;i<=m;i++)
        scanf("%d", &num2[i]);
    sort(&num[1], &num[n+1]);
    for(i=1;i<=m;i++) {
        left = 1; right = n;
        while (left <= right) {
            mid = (left + right) / 2;
            if(num2[i]<num[left] || num2[i]>num[right])
            {
                num2[i]=0; break;
            }
            if (num[left] == num2[i] || num[right] == num2[i])
            {
                num2[i] = 1; break;
            }
            else if(num2[i]==num[mid])
            {
                num2[i] = 1; break;
            }
            else if(num2[i]>num[mid])
                left = mid+1;
            else if(num2[i]<num[mid])
                right = mid-1;
        }
        if(num2[i]!=1)
            num2[i]=0;
    }
    for(i=1;i<=m;i++)
        printf("%d ", num2[i]);
}
