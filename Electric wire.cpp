//
// Created by 0864h on 2020-03-05.
//
#include<cstdio>
#include<vector>
#include <algorithm>
using namespace std;
vector<pair<unsigned int,unsigned int>> s(100, make_pair(501,501));
vector<unsigned int> d(100, 1);
int main()
{
    int i, j,n,ans=0,res=0;
    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d %d", &s[i].first, &s[i].second);
    sort(s.begin(), s.end());
    for(i=1;i<n;i++)
    {
        for(j=0;j<=i-1;j++)
        {
            if (s[i].second > s[j].second)
                d[i] = max(d[i], d[j]+1);
            if (s[i].second < s[j].second) continue;
        }
        if(ans <= d[i])
            ans = d[i];
    }
    res = n-ans;
    printf("%d", res);
}
