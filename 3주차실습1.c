#include <stdio.h>

int func(int a, int b) {
	int tmp = b;
	while (tmp != 0) {
		printf("%d\n", a * (tmp % 10));
		tmp /= 10;
	}
	printf("%d\n", a * b);
}

int main() {
	func(215, 4984);

	return 0;
}
