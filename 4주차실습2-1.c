#include <stdio.h>

int func(int n);

int main() {
    int n = 0;

    scanf("%d", &n); //몇 번째 값까지 출력할지 결정

    for (int i = 0; i < n; i++) { //n번 반복
        printf("%d ", func(i)); //i번째 값을 출력
    }

    return 0;
}

int func(int n) {
    if (n <= 0) //n이 0이하면 0을 반환
        return 0;
    else if (n == 1) //n이 1이라면 1을 반환
        return 1;
    else if (n == 2) //n이 2라면 2를 반환
        return 2;
    return func(n - 3) + func(n - 2) + func(n - 1); //직전 3수를 더한 수를 반환
}
