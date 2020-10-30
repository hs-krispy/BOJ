//
// Created by 0864h on 2020-10-30.
//
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int d[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(int i = 0; i < puddles.size(); i++)
        d[puddles[i][0]][puddles[i][1]] = -1;
    d[1][1] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(i == 1 && j == 1)
                continue;
            else if(d[j][i] == -1)
                d[j][i] = 0;
            else
                d[j][i] = (d[j][i - 1] + d[j - 1][i]) % 1000000007;
        }
    }
    answer = d[m][n];
    return answer;
}
