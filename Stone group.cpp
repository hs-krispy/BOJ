//
// Created by 0864h on 2020-07-28.
//
#include<iostream>
#include<queue>
using namespace std;
int A, B, C;
bool check[1000][1000];
int main()
{
    cin >> A >> B >> C;
    int sum = A + B + C;
    if(sum % 3 != 0)
    {
        cout << 0;
        return 0;
    }
    queue<pair<int, int>> q;
    q.push({A, B});
    check[A][B] = true;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x == y && y == sum - x - y)
        {
            cout << 1;
            return 0;
        }
        for(int i = 1; i <= 3; i++)
        {
            for(int j = 1; j <= 3; j++)
            {
                int stone[4] = {0, x, y, sum - x - y};
                if(stone[i] < stone[j])
                {
                    stone[j] -= stone[i];
                    stone[i] += stone[i];
                    if(!check[stone[i]][stone[j]])
                    {
                        check[stone[i]][stone[j]] = true;
                        q.push({stone[i], stone[j]});
                    }
                }
            }
        }
    }
    cout << 0;
}
