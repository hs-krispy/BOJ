//
// Created by 0864h on 2020-08-09.
//
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
long long seq[101];
bool check[101], clear = false;
vector<long long> v;
void find(int c)
{
    if(c == N)
    {
        for(int i = 0; i < N; i++)
            cout << v[i] << " ";
        clear = true;
        return;
    }
    for(int i = 1; i <= N; i++)
    {
        if(!check[i])
        {
            if(c == 0 || (c > 0 && (2 * v.back() == seq[i] || v.back() / 3 == seq[i])))
            {
                check[i] = true;
                v.push_back(seq[i]);
                find(c + 1);
                if(clear)
                    break;
                check[i] = false;
                v.pop_back();
            }
        }
    }
}
int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> seq[i];
    sort(&seq[1], &seq[N + 1]);
    find(0);
}
