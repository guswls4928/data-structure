#include <stdio.h>

int func(int a, int b) {
	int tmp = b; //자릿수를 반환할 더미값에 b값을 저장
	while (tmp != 0) { //tmp가 0이 되기 전까지 반복
		printf("%d\n", a * (tmp % 10)); //tmp를 10으로 나눴을 때 나머지를 a와 곱해 출력 -> 1의 자리와 a와의 곱 출력
		tmp /= 10; //tmp를 10으로 나눴을 때 몫을 tmp에 저장 -> 자릿수 낮추기
	}
	printf("%d\n", a * b); //a와 b의 곱을 출력
}

int main() {
	func(27, 4);

	return 0;
}
