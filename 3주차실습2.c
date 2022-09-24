#include <stdio.h>

int com_mul(int a, int b) {
	int lcm; //최소공배수를 저장할 변수
	int tmp; //변수 위치 교환과 공배수의 수를 저장할 더미 변수
	if (a > b) { //a와 b를 비교하여 a에 더 작은 변수를 저장
		tmp = a;
		a = b;
		b = tmp;
	}
	for (lcm = b; ; lcm += b) { //b의 배수를 lcm에 저장하며 계속 반복
		if (lcm % a == 0) { //lcm이 a로 나눴을 때 나머지가 없다면 종료 -> 공배수
			break;
		}
	}
	tmp = 0;
	for (int i = lcm; i <= 1000000; i += lcm) { //lcm의 배수를 i에 저장하며 1000000전까지 계속 반복하여 tmp값을 1씩 추가 -> 배수
		tmp++;
	}
	printf("공배수의 개수 : %d\n", tmp);
}

int com_fac(int a, int b) {
	int gcd; //최대공약수를 저장할 변수
	int tmp; //변수 위치 교환과 공약수의 수를 저장할 더미 변수
	if (a > b) { //a와 b를 비교하여 a에 더 작은 변수를 저장
		tmp = a;
		a = b;
		b = tmp;
	}
	for (gcd = a; ; gcd--) { //gcm에 a값을 저장하고 1씩 감소하며 무한 반복
		if ((a % gcd == 0) && (b % gcd == 0)) { //만일 a와 b가 gcd로 나눴을 때 나머지가 0이 된다면 종료 -> 공약수
			break;
		}
	}
	tmp = 0;
	for (int i = gcd; i > 0; i--) { //i에 gcd를 저장하고 1씩 감소시키며 0보다 클때까지 반복
		if (gcd % i == 0) { //gcd가 i로 나눴을때 나머지가 0이면 tmp값 1씩 증가 -> 약수
			tmp++;
		}
	}
	printf("공약수의 개수 : %d\n", tmp);
}

int main() {
	int a, b;

	scanf_s("%d %d", &a, &b); //연산할 두 변수를 입력

	com_mul(a, b); //공배수 개수를 구하는 함수
	com_fac(a, b); //공약수 개수를 구하는 함수

	return 0;
}
