//
// Created by 0864h on 2020-03-12.
//
#include<iostream>
#include<cstdio>
#include <algorithm>
using namespace std;
int arr[9], ans[9];
bool check[9];
int n, m;
void seq(int count)
{
    if(count == m)
    {
        for(int j = 0;j < count;j++)
            printf("%d ", ans[j]);
        printf("\n");
        return;
    }
    bool num[10001] = {false, }; // 사용되는 수 자체를 체크
    for(int i = 1;i <= n;i++)
    {
        if(!num[arr[i]] && !check[i])
        {
            ans[count] = arr[i];
            num[arr[i]] = true;
            check[i] = true;
            seq(count+1);
            check[i] = false;
        }
    }
}
int main()
{
    int i;
    cin >> n >> m;
    for(i = 1;i <= n;i++)
        cin >> arr[i];
    sort(&arr[1], &arr[n+1]);
    seq(0);
}



