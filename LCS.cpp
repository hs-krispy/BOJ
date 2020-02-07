//
// Created by 0864h on 2020-02-03.
//
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int d[1001][1001];
int main()
{
    int i, j, a, b;
    string str1, str2;
    cin>>str1>>str2;
    str1 = " " + str1; str2 = " " + str2;
    a=str1.length()-1; b=str2.length()-1;
    if(a<=b) {
        for (i = 1; i <= a; i++) {
            for (j = 1; j <= b; j++)
            {
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);//str1의 i 번째가 str2의 j번째 인덱스까지 가지는 부분수열의 최대길이
                if (str1[i] == str2[j])
                    d[i][j] = d[i-1][j-1]+1;//str1의 i 번째와 str2의 j 번째가 같다면 i-1, j-1번째 인덱스에 +1
            }
        }
        cout << d[a][b];
    }//str1의 길이가 더 짧거나 같을때
    else
    {
        for (i = 1; i <= b; i++) {
            for (j = 1; j <= a; j++)
            {
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
                if (str2[i] == str1[j])
                    d[i][j] = d[i-1][j-1]+1;
            }
        }
        cout<<d[b][a];
    }//str2의 길이가 더 짧을때
}