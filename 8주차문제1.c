#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int a[10001];
int n, i, j, temp;
int main() {
    scanf("%d", &n); //몇 개의 수를 정렬할 것인지
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]); //정렬할 수

    for (i = 1; i < n; i++)
    {

        for (j = 0; j < n; j++)
        {
            if (a[j] > a[j + 1]) //현재 값과 다음 값을 비교
            {
                temp = a[j]; //현재 값이 더 크다면 자리 교체
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for (i = 1; i <= n; i++) //정렬한 수를 출력
        printf("%d ", a[i]);
    
    return 0;
}