//
// Created by 0864h on 2020-03-31.
//
#include<cstdio>
#include<map>
using namespace std;
int main()
{
    int n,i,age;
    char s[100];
    multimap<int, string> m;
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %s", &age, s);
        m.insert(pair<int, string>(age, s));
    }
    map<int, string>::iterator iter;
    for(iter=m.begin();iter!=m.end();iter++)
        printf("%d %s\n", iter->first, iter->second.c_str());
}

