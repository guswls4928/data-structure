#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#define NAME_SIZE 30
#define STUDENT_SIZE 100
#define TRUE 1
#define FLASE -1

float rank[STUDENT_SIZE+1] = { 0, }; //학생들의 점수를 저장할 배열
int cnt = 0; //학생의 수

struct student{ //학생의 정보를 저장할 구조체
	struct student* blink; //이전노드
	char name[NAME_SIZE]; //이름
	float grade; //성적
	struct student* flink; //다음노드
};

struct student* head; //머리노드
struct student* tail; //꼬리노드

void init() { //초기화
	rank[0] = 101; //등수와 배열 인덱스 일치를 위한 만점보다 큰 수 저장

	head = (struct student*)malloc(sizeof(struct student));
	tail = (struct student*)malloc(sizeof(struct student));
	
	head->grade = 101;
	strcpy_s(head->name, NAME_SIZE+1, "head"); //머리노드 데이터 저장
	tail->grade = -1; 
	strcpy_s(tail->name, NAME_SIZE+1, "tail"); //꼬리노드 데이터 저장

	head->blink = tail; //머리노드의 다음노드를 꼬리노드로
	head->flink = head; //머리노드의 이전노드를 머리노드로
	tail->blink = tail; //꼬리노드의 다음노드를 머리노드로
	tail->flink = head; //꼬리노드의 이전노드를 꼬리노드로
}

void makenode(char *name_data, float value) { //노드생성 함수
	struct student* newnode = (struct student*)malloc(sizeof(struct student));
	struct student* p;
	p = tail; //p는 꼬리노드
	p->flink->blink = newnode; //꼬리노드의 앞노드의 뒷노드(맨뒤노드)는 새로운노드
	newnode->flink = p->flink; //새로운노드의 앞노드는 꼬리노드의 앞노드
	p->flink = newnode; //꼬리노드의 앞노드는 새로운노드
	newnode->blink = p; //새로운노드의 뒷노드는 꼬리노드
	strcpy_s(newnode->name, strlen(name_data)+1, name_data);
	newnode->grade = value;
}

int removenode(char *name_data) { //노드 삭제 함수
	struct student* p;
	p = head->blink; //p는 머리노드의 다음노드(첫번째노드)
	while (p != tail) { //p가 꼬리노드가 아닐 때까지(맨뒤노드가 아닐때까지)
		if (strcmp(p->name, name_data) == 0) { //현재노드의 이름 데이터가 원하는 이름 데이터랑 같다면
			for (int i = 1; i <= cnt; i++) { //학생 수만큼 반복
				if (rank[i] == p->grade) { //i번째로 큰 점수가 학생의 점수와 같다면
					for (int j = i; j <= cnt + 1; j++) rank[j] = rank[j + 1]; //같은 점수 데이터 위치부터 점수 데이터를 한칸씩 앞으로 당겨 저장 
					break;
				}
			}
			cnt--; //학생 수 감소
			if (p->flink == head && p->blink == tail) { //현재노드 이전이 머리노드, 다음이 꼬리노드라면(남은 노드 1개)
				free(p); //현재노드의 할당된 메모리 해제
				init(); //초기화
				return TRUE;
			}
			p->blink->flink = p->flink; //현재노드의 이전노드의 다음노드는 현재노드의 다음노드
			p->flink->blink = p->blink; //현재노드의 다음노드의 이전노드는 현재노드의 이전노드
			free(p); 
			return TRUE;
		}
		p = p->blink; //다음노드 검사
	}
	return FALSE; //함수가 제대로 작동하지 않았음(해당 학생이 없음)을 반환
}

float searchnode(char* name_data) { //노드 검색 함수
	struct student* p;
	p = head->blink; //p는 머리노드 다음노드
	while (p != tail) { //현재노드가 꼬리노드가 아닐때까지
		if (strcmp(p->name, name_data) == 0) return p->grade; //현재노드의 이름 데이터가 원하는 이름 데이터랑 같다면 학생의 점수반환
		p = p->blink; //다음노드 검사
	}
	return FALSE; //함수가 제대로 작동하지 않았음(해당 학생이 없음)을 반환
}

int main()
{
	int menu, end = FALSE;
	float grade_data;
	char name_data[NAME_SIZE];

	system("cls");
	init();

	while (1) {
		printf("Menu Option\n1.입력 2.제거 3.검색 4.종료\n");
		scanf("%d", &menu);
		while (getchar() != '\n'); //버퍼 비우기
		
		system("cls"); //화면 초기화
		
		switch (menu) {
			case 1:
				printf("학생의 이름 : ");
				scanf("%s", &name_data);
				while (1) {
					printf("학생의 성적 : ");
					scanf("%f", &grade_data);
					while (getchar() != '\n');
					if (grade_data > 100 || grade_data < 0) {
						printf("\nError!\n");
						printf("0~100사이의 수만 입력해주세요.\n\n");
						continue;
					}
					break;
				}
				makenode(name_data, grade_data);
				cnt++; //학생 수 증가
				for (int i = cnt; i >= 0; i--) {
					if (rank[i] < grade_data) rank[i + 1] = rank[i];
					else {
						rank[i + 1] = grade_data;
						break;
					}
				}
				break;

			case 2:
				printf("제거할 학생의 이름 : ");
				scanf("%s", &name_data);
				if (removenode(name_data) == FALSE) printf("해당 학생이 존재하지 않습니다.\n");
				break;

			case 3:
				printf("검색할 학생의 이름 : ");
				scanf("%s", &name_data);
				grade_data = searchnode(name_data);
				if (grade_data != FALSE) {
					printf("%s 학생의 점수 : %.1f\n", name_data, grade_data);
					for (int i = 1; i <= cnt + 1; i++) {
						if (rank[i] == grade_data) {
							printf("%s 학생의 등수 : %d\n", name_data, i);
							break;
						}
					}
				}
				else printf("해당 학생이 존재하지 않습니다.\n");
				break;

			case 4:
				end = TRUE;
				break;

			default:
				printf("\bError!\n");
				printf("올바른 메뉴를 입력해주세요.\n");
				break;
		}
		
		if (end) break;
		
		printf("\n아무 키나 입력하세요.\n");
		char buf = ' ';
		buf = _getch("\n"); //명령이 끝난 후 바로 화면초기화 방지
		system("cls");
	}
	
	printf("\n프로그램 종료..\n");

	return 0;
}