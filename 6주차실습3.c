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
	printf("공백 포함 문자 수 : %d\n", charnum + blank); //공백 제외 문자 수인 charnum에 공백 수를 더해 출력
	printf("줄 수 : %d\n", linenum);

	fclose(file); //파일닫기

	return 0;
}