#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a, i, j, cnt;
    scanf("%d", &a); //몇개를 넣을지
    int *num = malloc(sizeof(int)*a);
    for (i = 0; i < a - 1; i++) //배열에 넣을 수 입력
        scanf("%d", &num[i]);
    for (i = 1; i <= a; i++) {
        cnt = 0;
        for (j = 0; j < a - 1; j++) {
            if (i == num[j]) //모든 배열 값을 탐색 후 있으면 cnt를 true로
                cnt = 1;
            continue;
        }
        if (cnt)
            continue;
        else { //cnt가 true가 아니라면  없는 수를 출력
            printf("%d", i);
            break;
        }
    }
}
