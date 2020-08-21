//
// Created by 0864h on 2020-08-21.
//
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int N;
string word[11];
map<char, int> m;
int main()
{
    cin >> N;
    int ans = 0;
    char check[11];
    for(int i = 1; i <= N; i++)
    {
        cin >> word[i];
        for(int j = 0; j < word[i].length(); j++)
        {
            if(check[word[i][j]])
            {
                m[word[i][j]] += pow(10, word[i].length() - j - 1);
            }
            if(!check[word[i][j]])
            {
                check[word[i][j]] = true;
                m.insert({word[i][j], pow(10, word[i].length() - j - 1)});
            }
        }
    }
    vector<pair<int, char>> v;
    for (auto it = m.begin(); it != m.end(); ++it)
        v.emplace_back(it->second, it->first);
    sort(v.begin(), v.end(), greater<pair<int, char>>());
    for(int i = 0; i < v.size(); i++)
        ans += v[i].first * (9 - i);
    cout << ans;
}
