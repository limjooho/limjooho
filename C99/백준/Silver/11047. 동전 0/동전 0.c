#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 



int main() {
	int N, K;
	int answer = 0;

	scanf("%d", &N);


	scanf("%d", &K);

	int arr[10];

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	
	for (int i = 0; i < N; i++) {
		answer += K / arr[N - i-1];
		K = K % arr[N - i-1];
		if (K == 0) {
			break;
		}
	}
	printf("%d", answer);
}