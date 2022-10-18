#include <stdio.h>
#include <string.h>
#include <conio.h>

int main() {
	char str[202] = { ' ' };
	char input[202] = { ' ' };

	printf("입력할 문자열을 입력하세요 : ");
	scanf("%s", str);

	int len = strlen(str); //입력받은 문자열의 길이를 len에 저장
	for (int i = 0; i < len; i++) {
		input[i] = _getch(); //한글자 입력을 input배열 i번째에 저장
		if (input[i] == '\r' || input[i] == '\n') { //줄 넘김이 생기면 출력이 되지 않고 경고음 출력 후 아래에 코드를 넘김
			printf("\a");
			i--;
			continue;
		}
		printf("%c", input[i]); //한글자 입력을 출력
		if (i > 0 && input[i] == '\b') { //백스페이스를 하면 전에 입력받은 글자를 공백으로 바꾸고 출력을 지운뒤 그 글자를 입력받았던 i값으로 되돌림
			input[i - 1] = ' ';
			printf("%c\b", input[i - 1]);
			i -= 2;
		}
		else if (input[i] != str[i]) { //입력받은 글자가 입력할 문자열과 다른 경우 입력을 공백으로 바꾸고 출력값을 지우고 에러음 출력후 그 글자를 입력받았던 i값으로 되돌림
			input[i] = ' ';
			printf("\b%c\b\a", input[i]);
			i--;
		}
	}
}
