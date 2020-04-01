//
// Created by 0864h on 2020-04-01.
//
#include<cstdio>
#include<cmath>
using namespace std;
int a[100001];
int gcd(int a, int b)
{
    int c;
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
    int i,n,s,val=0;
    scanf("%d %d", &n, &s);
    for(i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
        if(i==1)
            val = abs(s-a[i]);
        else
        {
            if(val >= gcd(val, abs(s-a[i])))
                val = gcd(val, abs(s-a[i]));
        }
    }
    printf("%d", val);
}

