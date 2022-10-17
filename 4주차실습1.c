/*
#include <stdio.h>
#include <math.h>

typedef struct  { //원의 정보를 저장할 구조체
	double x,y,r;
}CIRCLE;

typedef struct { //점의 정보를 저장할 구조체
	double x,y;
}POINT;

void circle_to_point(CIRCLE c1, POINT p1) { //점과 원사이의 관계를 측정하는 함수
	double d = sqrt(pow((c1.x - p1.x), 2) + pow((c1.y - p1.y), 2)); //점과 원의 중심사이의 거리를 측정후 d에 저장

	if (d < c1.r) { //점과 원의 중심의 거리의 거리가 원의 반지름보다 작으면
		printf("점은 원 안입니다.\n");
	}
	else if (d > c1.r) { //점과 원의 중심의 거리의 거리가 원의 반지름보다 크면
		printf("점은 원 밖입니다.\n");
	}
	else { //점과 원의 중심의 거리가 원의 반지름과 같으면
		printf("점은 원 위입니다.\n");
	}
}

void circle_to_circle(CIRCLE c1, CIRCLE c2) { //원과 원사이의 관계를 측정하는 함수
	if ((c1.x == c2.x && c1.y == c2.y) && c1.r == c2.r) { //두 원의 x,y좌표가 같고 반지름이 같으면
		printf("일치합니다.\n");
	}
	double d = sqrt(pow((c1.x - c2.x), 2) + pow((c1.y - c2.y), 2)); //두 원 사이의 거리를 측정후 d에 저장
	if ((d == (c1.r + c2.r)) || ((d + c1.r)==c2.r || (d + c2.r) == c1.r)) { //두 원의 반지름의 합이 더 원 사이의 거리와 같거나 두 원사이의 거리와 한 원의 반지름과 더했을때 다른 원의 반지름과 같을 경우
		printf("한 점 일치합니다.\n");
	}
	else if ((d + c2.r) < c1.r) { //두 원사이의 거리와 원B의 반지름 합이 원A의 반지름보다 작을경우
		printf("원B가 원A안에 있습니다.\n");
	}
	else if ((d + c1.r) < c2.r) { //두 원사이의 거리와 원A의 반지름 합이 원B의 반지름보다 작을경우
		printf("원A가 원B안에 있습니다.\n");
	}
	else if (d < (c1.r + c2.r) && (d >= c1.r || d >= c2.r)) { //두 원사이의 거리가 두 원의 반지름의 합보다 작으며, 한 원의 반지름보다 크거나 같을경우
		printf("두 점 일치합니다.\n");
	}
	else {
		printf("두 원은 관계가 없습니다.\n");
	}
}

int main() {
	double x, y, r;
	
	printf("원A을 입력하세요(x,y,r) : ");
	scanf("%lf %lf %lf", &x, &y, &r);
	CIRCLE c1 = { x,y,r };

	printf("점을 입력하세요(x,y) : ");
	scanf("%lf %lf", &x, &y);
	POINT p1 = { x,y };

	circle_to_point(c1, p1);

	printf("원B을 입력하세요(x,y,r) : ");
	scanf("%lf %lf %lf", &x, &y, &r);
	CIRCLE c2 = { x,y,r };

	circle_to_circle(c1, c2);

	return 0;
}
*/


#include <stdio.h>
#include <string.h>

int main() {
	char str[101] = {' ' };
	char input[101] = { ' ' };

	printf("입력할 문자열을 입력하세요 : ");
	scanf("%s", str);

	int len = strlen(str); //입력받은 문자열의 길이를 len에 저장
	for (int i = 0; i < len; i++) { 
		input[i] = _getch(); //한글자 입력을 input배열 i번째에 저장
		if (input[i] == '\r' || input[i] == '\n') { //줄 넘김이 생기면 
			printf("\a");
			i--;
			continue;
		}
		printf("%c", input[i]);
		if (i > 0 && input[i] == '\b') {
			input[i - 1] = ' ';
			printf("%c\b", input[i - 1]);
			i -= 2;
		}
		else if (input[i] != str[i]) {
			input[i] = ' ';
			printf("\b%c\b\a", input[i]);
			i--;
		}
	}
}


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BLANK "\t \n \r" //공백을 의미하는 이스케이프 시퀀스를 묶음

int main() {
	FILE* file = fopen("readme.txt", "r"); //같은 디렉토리 내 readme.txt파일을 읽기 형식으로 열고 file변수에 저장
	char* noneblank, charlist[5000]; //파일에 문장을 받아올 배열와 단어를 받아올 포인터를 생성
	int charnum = 0, blank = 0, linenum = 0; 

	while (fgets(charlist, sizeof(charlist), file) != NULL) { //file변수에서 문장을 NULL이 나오기 전까지 하나씩 꺼내오고 charlist에 저장
		++linenum; //줄 수 증가
		noneblank = strtok(charlist, BLANK); //charlist의 저장된 문징를 첫 공백을 기준으로 잘라 noneblank에 저장
		charnum += strlen(noneblank); //noneblank에 저장된 문자의 길이만큼 charnum에 더하여 저장
		while ((noneblank = strtok(NULL, BLANK)) != NULL) { //charlist의 다음 공백을 기준으로 잘라 NULL이 나오기 전까지 nonblank에 저장
			blank++; //공백 수 1증가
			charnum += strlen(noneblank);
		}
	}

	printf("공백 제외 문자 수 : %d\n", charnum);
	printf("공백 포함 문자 수 : %d\n", charnum+blank); //공백 제외 문자 수인 charnum에 공백 수를 더해 출력
	printf("줄 수 : %d\n", linenum);

	fclose(file); //파일닫기

	return 0;
}
*/