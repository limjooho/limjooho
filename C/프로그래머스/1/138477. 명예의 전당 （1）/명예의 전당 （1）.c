#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// score_len은 배열 score의 길이입니다.
int* solution(int k, int score[], size_t score_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * score_len);
    int* result = (int*)malloc(sizeof(int) * score_len);
    for(int i = 0; i < k && i < score_len; i++) {
        // 1. 일단 오늘 점수를 명예의 전당에 넣는다.
        answer[i] = score[i];

        // 2. 오늘 넣은 점수까지만 내림차순 정렬 (버블 정렬)
        for(int j = 0; j < i; j++) {
            for(int u = 0; u < i - j; u++) {
                if(answer[u] < answer[u + 1]) {
                    int temp = answer[u];
                    answer[u] = answer[u + 1];
                    answer[u + 1] = temp;
                }
            }
        }

        // 3. 현재 들어있는 점수들 중 가장 마지막 점수(꼴찌)를 기록
        result[i] = answer[i];
    }
    
    
    
    
    for(int i=k; i<score_len; i++) {
        if(score[i] > answer[k-1]) {
            answer[k-1] = score[i];
            for(int i=0; i<k-1; i++) {
                for(int u=0; u<k-1; u++) {
                    if(answer[u] < answer[u+1]) {      //내림차순
                        int temp = answer[u];
                        answer[u] = answer[u+1];
                        answer[u+1] = temp;
                                    }
                                }
                            }
            result[i] = answer[k-1];
        }
        else {
            result[i] = answer[k-1];
        }
    }
    return result;
}