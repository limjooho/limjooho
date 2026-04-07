#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 


int main() {
	int n;
	scanf("%d", &n);
	int answer = 0;

	while (n > 0) {
		if (n == 7 || n == 4) {          //정확하게 만들 수 없는 경우가 7 or 4 이기 때문에 7, 4를 제외
			answer = -1;
			break;
		}
		if (n % 5 == 0) {               // 15,20 같이 5로 나누어 떨어지면 몫 출력 후 break
			answer = n / 5;
			break;
		}
		n = n - 3;                     // 18kg인 경우, 먼저 3kg 을 빼고 
		answer++;                      // 뺀 3kg 1개를 answer++

		if (n % 5 == 0) {             //18kg 에서 3kg를 뺐을 때 5로 나누어 떨어지기에, answer에 5로 나눈 몫을 더하고 break;
			answer += n / 5;
			break;
		}
	}
	printf("%d", answer);
}















/*
ai를 이용하여 코드를 간결하게 만들어보았습니다
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int main() {
    int n;
    if (scanf("%d", &n) == 0) return 0; // 입력 예외 처리

    int answer = 0;

    while (n >= 0) {
        // 1. 현재 남은 n이 5로 나누어떨어지면, 남은 건 전부 5kg 봉지에 담는다.
        if (n % 5 == 0) {
            answer += (n / 5);
            printf("%d", answer);
            return 0; // 정답 출력 후 프로그램 즉시 종료
        }

        // 2. 5로 안 나누어떨어지면 3kg 봉지를 하나 쓴다.
        n -= 3;
        answer++;
    }

    // 3. while문을 빠져나왔다는 건 n이 음수가 됐다는 뜻 (정확히 못 만듦)
    printf("-1");
    return 0;
}

*/
