#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 


int main() {
	int n;
	scanf("%d", &n);              //사람 수 입력
	int answer = 0;
	int sum = 0;
	int p[1000];

	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);            //걸리는 시간 출력을 배열에 저장
	}

	for (int i = 0; i < n - 1; i++) {
		for (int u = 0; u < n - 1; u++) {
			if (p[u] > p[u + 1]) {
				int t = p[u];
				p[u] = p[u + 1];
				p[u + 1] = t;            //걸리는 시간을 오름차순으로 정렬
			}
		}
	}

	for (int i = 0; i < n; i++) {          
		answer += p[i];               //누적 합을 구하기 위한 코드        
		sum += answer;                //answer에는 p의 배열이 더해지고, sum 에는 answer이 계속 더해짐
	}

	printf("%d", sum);
}
