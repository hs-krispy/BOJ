//
// Created by 0864h on 2020-03-15.
//
#include<cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
int num[200001], res[500001], j[100001], s[100001];
int main()
{
    int n,h,i,c1=1,c2=1,count=0,low,low2,m=500001;
    scanf("%d %d", &n, &h);
    memset(j, m, sizeof(j));
    for(i=1;i<=n;i++)
    {
        scanf("%d", &num[i]);
        if(i%2==1)
        {
            s[c1] = num[i]; c1++;
        }
        else if(i%2==0)
        {
            j[c2] = h-num[i]+1; c2++;
        }
    }
    sort(&s[1], &s[c1]); sort(&j[1], &j[c2]);
    for(i=1;i<=h;i++)
    {
        low = *lower_bound(&s[1], &s[c1], i);
        if(low==0)
            res[i]+=0;
        else
            res[i] += c1 - distance(s, lower_bound(&s[1], &s[c1], i));
        low2 = *lower_bound(&j[1], &j[c2], i+1);
        res[i] += distance(j, lower_bound(&j[1], &j[c2], i+1))-1;
        if(m==res[i])
            count+=1;
        if(m>res[i])
        {
            m=res[i]; count=1;
        }
    }
    printf("%d %d", m, count);
}
