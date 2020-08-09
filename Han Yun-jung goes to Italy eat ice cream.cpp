//
// Created by 0864h on 2020-08-08.
//
#include<iostream>
using namespace std;
int N, M, ans = 0;
bool check[201][201];
int main()
{
    int num1, num2;
    cin >> N >> M;
    for(int i = 1; i <= M; i++)
    {
        cin >> num1 >> num2;
        check[num1][num2] = check[num2][num1] = true;
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = i + 1; j <= N; j++)
        {
            if(!check[i][j])
            {
                for(int k = j + 1; k <= N; k++)
                {
                    if(!check[i][k] && !check[j][k])
                        ans++;
                }
            }
        }
    }
    cout << ans;
}
