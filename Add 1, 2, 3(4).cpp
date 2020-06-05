//
// Created by 0864h on 2020-06-06.
//
#include <stdio.h>
int d[10001];
int main() {
    d[0] = 1;
    for (int i = 1; i <= 10000; i++) {
        if (i >= 1) {
            d[i] += d[i - 1];
        }
    }
    for (int i = 1; i <= 10000; i++) {
        if (i >= 2) {
            d[i] += d[i - 2];
        }
    }
    for (int i = 1; i <= 10000; i++) {
        if (i >= 3) {
            d[i] += d[i - 3];
        }
    }
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", d[n]);
    }
}