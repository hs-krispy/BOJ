//
// Created by 0864h on 2020-02-12.
//
#include<iostream>
using namespace std;
int d[16][16] = {-1};
int main()
{
    int n,m,k,i,j,a,b;
    cin>>n>>m>>k;
    d[1][1] = 1;
    if(k==0)
    {
         a = n;
         b = m;
    }
    else
    {
        if (k % m == 0) {
            a = k / m;
            b = m;
        } else {
            a = k / m + 1;
            b = k % m;
        }
    }
        for (i = 1; i <= a; i++) {
            for (j = 1; j <= b; j++) {
                if (!(i == 1 && j == 1)) {
                    if (i - 1 < 1)
                        d[i][j] = d[i][j - 1];
                    if (j - 1 < 1)
                        d[i][j] = d[i - 1][j];
                    else
                        d[i][j] = d[i - 1][j] + d[i][j - 1];
                }
            }
        }
        for (i = a; i <= n; i++) {
            for (j = b; j <= m; j++) {
                if (!(i == a && j == b)) {
                    if (i - 1 < a)
                        d[i][j] = d[i][j - 1];
                    if (j - 1 < b)
                        d[i][j] = d[i - 1][j];
                    else
                        d[i][j] = d[i - 1][j] + d[i][j - 1];
                }
            }
        }
    cout<<d[n][m];
}
