#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 


int main() {
    int n;
    scanf("%d", &n);
    int answer = 0;
    int sum = 0;
    int p[1000];

    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n - 1; u++) {
            if (p[u] > p[u + 1]) {
                int t = p[u];
                p[u] = p[u+1];
                p[u + 1] = t;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        answer += p[i];
        sum += answer;
    }

    printf("%d", sum);
}