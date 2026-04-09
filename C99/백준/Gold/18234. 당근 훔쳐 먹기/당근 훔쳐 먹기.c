#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	long long n;    //당근의 맛
	long long t;    //당근의 영양제
} carrot;

carrot list[200005];

int compare(const void* a, const void* b) {  //타입을 고정하지 않은 void 를 사용해야 오류가 나지 않음
	carrot* c1 = (carrot*)a;
	carrot* c2 = (carrot*)b;

	if (c1->t < c2->t) return -1; //c1 보다 c2 가 크다면 -1을 출력해 그대로 둔다
	if (c1->t > c2->t) return 1;  //c1이 c2보다 크다면 오름차순이 안되므로 1을 출력해 순서를 바꾼다
	return 0;
}



int main() {
	long long N, T;    //N종류 당근과 T일동안 재배

	scanf("%lld %lld", &N, &T);

	for (int i = 0; i < N; i++) {
		scanf("%lld %lld", &list[i].n, &list[i].t);      
	}

	qsort(list, N, sizeof(carrot), compare);  //qsort(배열이름, 데이터 개수, 데이터 크기, 함수)

	/*for (int i = 0; i < N - 1; i++) {
		for (int u = 0; u < N - 1; u++) {
			if (list[u].t > list[u + 1].t) {
				carrot temp = list[u];                  //carrot 리스트의 t값을 기준으로 오름차순 정렬 하지만 빅오가 매우 커짐
				list[u] = list[u + 1];
				list[u + 1] = temp;
			}
		}
	}*/

	long long ca = N-1;
	long long sum = 0;
	for (int i = T; i > 0; i--) {
		if (ca < 0) break;
		sum += list[ca].n + (list[ca].t * (i - 1));    //오름차순으로 정렬시킨 후 뒤에서부터 1씩 줄여가며 더함
		ca--;
	}
	printf("%lld", sum);
}