//
// Created by 0864h on 2020-05-31.
//
#include<iostream>
#include<queue>
#include<climits>
using namespace std;
int n, k, arr[100001], sol[100001];
int dy[] = {-1, 1};
void move(int a)
{
    queue<int> q;
    q.push(a);
    arr[a] = 0;
    while(!q.empty())
    {
        int y = q.front();
        q.pop();
        for(int i : dy)
        {
            int ny = y + i;
            if(ny >= 0 && ny <= 100000)
            {
                if(arr[ny] >= arr[y] + 1)
                {
                    arr[ny] = arr[y] + 1;
                    sol[ny]++;
                    q.push(ny);
                }
            }
        }
        int ny = 2 * y;
        if(ny >= 0 && ny <= 100000)
        {
            if(arr[ny] >= arr[y] + 1)
            {
                arr[ny] = arr[y] + 1;
                sol[ny]++;
                q.push(ny);
            }
        }
    }
}
int main()
{
    cin >> n >> k;
    if(n == k)
    {
        cout << 0 << "\n" << 1;
        return 0;
    }
    for(int i = 0; i <= 100000; i++)
        arr[i] = INT_MAX;
    move(n);
    cout << arr[k] << "\n" << sol[k];
}
