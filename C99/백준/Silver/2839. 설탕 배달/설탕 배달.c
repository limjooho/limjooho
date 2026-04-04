#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 


int main() {

	int n;
	scanf("%d", &n);

	int answer = 0;

	while (n > 0) {
		if (n == 7 || n == 4) {
			answer = -1;
			break;
		}
		if (n % 5 == 0) {
			answer = n / 5;
			break;
		}
		n = n - 3;
		answer++;

		if (n % 5 == 0) {
			answer += n / 5;
			break;
		}
	}
	printf("%d", answer);


}