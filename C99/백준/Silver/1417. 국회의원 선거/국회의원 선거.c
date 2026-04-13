#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int fmax(int person[], int size) {        //최댓값의 index 를 찾는 함수
	int max = 1;
	for (int i = 1; i < size; i++) {
		if (person[i] >= person[max]) {
			max = i;
		}
	}
	return max;
}


int main() {
	int N;
	int person[51];
	scanf("%d", &N);
	if (N == 0) {
		printf("0");         //N이 0일 경우 코드 종료
		return 0;
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &person[i]);
	}
	if (N == 1) {
		printf("0");         //N이 1인경우 0출력 후 종료
		return 0;
	}

	int answer = 0;
	while (1) {
		int index = fmax(person, N);          //index에 최댓값이 몇번째에 있는지를 저장
		if (person[0] > person[index]) {       //다솜이의 값이 가장 크면 종료
			break;
		}
		else {
			person[index]--;            //최댓값에 해당하는 수를 1 감소시키고
			person[0]++;				//다솜이의 값 1 증가
			answer++;					//매수된 사람 수 표시
		}
	}
	printf("%d", answer);
}








