#include <stdio.h>

int com_mul(int a, int b) {
	int lcm;
	int tmp;
	if (a > b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	for (lcm = b; ; lcm += b) {
		if (lcm % a == 0){
			break;
		}
	}

	for (int i = lcm; i <= 1000000; i += lcm) {
		tmp++;
	}
	printf("공배수의 개수 : %d\n", tmp);
}

int com_fac(int a, int b) {
	int gcd;
	int tmp;
	if (a > b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	for (gcd = a; ; gcd--) {
		if ((a % gcd == 0) && (b % gcd == 0)) {
			break;
		}
	}
	tmp = 0;
	for (int i = gcd; i > 0; i--) {
		if (gcd % i == 0) {
			tmp++;
		}
	}
	printf("공약수의 개수 : %d\n", tmp);
}

int main() {
	com_mul(20, 19);
	com_fac(20, 19);

	return 0;
}
