//
// Created by 0864h on 2020-01-16.
//
#include<iostream>
#include<vector>
using namespace std;
int main() {
    int i, n, l = 1;
    long long sum = 0, div = 1000000000;
    vector< vector<long long> > d;
    d.assign(101, vector<long long>(10, 0));
    cin >> n;//계단수의 길이
    for(l=1;l<=9;l++)
    {
        d[1][l] = 1;
    } //길이가 1인 경우에는 마지막수가 1~9인 경우모두 계단수(9개)
    for (i = 2; i <= n; i++) {
        for (l = 0; l <= 9; l++) {
            if (l == 0) {
                d[i][l] = d[i - 1][l + 1];//마지막수가 0인 경우에는 앞 경우의 마지막 수가 1인 경우만 가능
            }
            if (l == 9) {
                d[i][l] = d[i - 1][l - 1];//마지막수가 9인 경우에는 앞 경우의 마지막 수가 8인 경우만 가능
            }
            if(l>=1 && l<=8){
                d[i][l] = d[i - 1][l - 1] + d[i - 1][l + 1];
            }
            d[i][l] %= div;
        }
    }
    for(l=0;l<=9;l++)
    {
        sum += d[n][l];
    }
    sum %= div;
    cout<<sum;
}
