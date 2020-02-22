//
// Created by 0864h on 2020-02-19.
//
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int mod = 1000000000;
int main()
{
    int i=1,j=1,k1,k2,a,b,c;
    vector<int> arr1(11);
    vector<int> arr2(11);
    cin>>a>>b;
    while(mod>=1)
    {
        if(a/mod>=0)
        {
            if(!(a/mod==0 && i==1))
            {
                arr1[i] = a/mod;
                a %= mod;
                i++;
            }
        }
        if(b/mod>=0)
        {
            if(!(b/mod==0 && j==1))
            {
                arr2[j] = b / mod;
                b %= mod;
                j++;
            }
        }
        mod /= 10;
    }
    if(i>j)
        cout<<-1;//첫 번째 정수의 자릿수가 더 클때
    if(i<j)
    {
        sort(&arr1[1], &arr1[i], greater<>());
        for(k1=1;k1<i;k1++)
            cout<<arr1[k1];
    }//두 번째 정수의 자릿수가 더 클때
    if(i==j)
    {
        sort(&arr1[1], &arr1[i],greater<>());
        do
        {
            c=0;
            for(k1=1;k1<j;k1++)
            {
                if(arr2[k1]==arr1[k1])
                    c++;
                if(arr2[k1]>arr1[k1] && c==k1-1)
                    break;
            }
            if(c==k1-1 && arr1[1]!=0) {
                for (k1 = 1; k1 < j; k1++)
                    cout << arr1[k1];
                return 0;
            }
        }while(prev_permutation(&arr1[1], &arr1[i]));
        cout<<-1;
    }
}
