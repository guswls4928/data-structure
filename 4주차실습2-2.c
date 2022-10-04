#include <stdio.h>

void func(int n);

int main() {
    int n = 0;

    scanf("%d", &n); //몇 번째 값까지 출력할지 결정

    func(n);

    return 0;
}

void func(int n) {
    if (n <= 1) //n이 1이하면 0을 출력
        printf("0");
    else if (n == 2) //n이 2이라면 0과 1을 출력
        printf("0 1");
    else
        printf("0 1 2"); //n이 2이하가 아니라면 0과 1, 2를 출력

    int x1 = 0, x2 = 1, x3 = 2, x4;
    
    for (int i = 4; i <= n; i++) { //4번째 수부터 n번까지 반복
        x4 = x1 + x2 + x3; //n번째 수를 직전 세 수를 더해서 저장
        x1 = x2; //직전 세 수를 n번째 수 기준으로 저장
        x2 = x3;
        x3 = x4;
        printf(" %d", x4); //n번째 수를 출력
    }
}
