//
// Created by 0864h on 2020-01-13.
//
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int i, n, num;
    vector<int> d(11);
    d[0]=1;
    cin>>n;
    for(i=1; i<=10;i++)
    {
        if(i-1>=0)
            d[i]+=d[i-1];
        if(i-2>=0)
            d[i]+=d[i-2];
        if(i-3>=0)
            d[i]+=d[i-3];
    }
    for(i=0;i<n;i++)
    {
        cin >> num;
        cout<<d[num]<<"\n";
    }
    return 0;
}
 
