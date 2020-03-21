//
// Created by 0864h on 2020-03-20.
//
#include<cstdio>
#include<cmath>
using namespace std;
int n;
void p(int num, int i)
{
    int j,k,a;
    bool check;
    for(j=1;j<=9;j++)
    {
        k = num + j;
        if(k<100)
        {
            for (a = 2; a <= 10; a++) {
                if (k!=a &&  k%a==0) {
                    check = false;
                    break;
                } else check = true;
            }
        }
        else {
            for (a = 2; a <= sqrt(k); a++) {
                if (k!=a && k%a==0) {
                    check = false;
                    break;
                } else check = true;
            }
        }
        if(check&&i==n-1)
            printf("%d\n",k);
        if(check&&i<n-1)
            p(k*10,i+1);
    }
}
int main()
{
    int i;
    scanf("%d", &n);
    if(n==1)
        printf("%d\n%d\n%d\n%d\n", 2,3,5,7);
    else
        for(i=2;i<=9;i++)
            if(i==2||i==3||i==5||i==7)
                p(i*10,1);
}
