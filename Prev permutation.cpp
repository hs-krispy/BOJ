//
// Created by 0864h on 2020-08-07.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i=0; i < N; i++)
        cin >> v[i];
    if (prev_permutation(v.begin(), v.end())) {
        for (int i = 0; i < N; i++)
            cout << v[i] << ' ';
    } else
        cout << "-1";
    return 0;
}
