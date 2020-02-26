#include<iostream>
using namespace std;
int main()
{
    int i,j,k,n,v[101][101];
    long long d[101][101];
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cin>>v[i][j];
    }
    d[1][1]=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(!(i==1&&j==1)) {
                for (k = 1; k <= j - 1; k++) {
                    if (j == k + v[i][k])
                        d[i][j] += d[i][k];
                }
                for (k = 1; k <= i - 1; k++) {
                    if (i == k + v[k][j])
                        d[i][j] += d[k][j];
                }
            }
        }
    }
    cout<<d[n][n];
}
