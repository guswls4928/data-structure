#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#define NAME_SIZE 30
#define STUDENT_SIZE 100
#define TRUE 1
#define FLASE 0

int cnt;

struct tree{
	struct tree* rlink;
	int data;
	int level;
	struct tree* llink;
};

struct tree* root;

void init() {
	cnt = 0;
	
	root = (struct tree*)malloc(sizeof(struct tree));
	root->data = NULL;
	root->level = 0;
	root->rlink = NULL;
	root->llink = NULL;
}

struct tree* node(int value) {
	struct tree* newnode = (struct tree*)malloc(sizeof(struct tree));
	
	newnode->llink = NULL;
	newnode->rlink = NULL;
	newnode->data = value;
	
	return newnode;
}

void nodecheck(struct tree *key, int value) {
	if (key->data > value) {
		if (key->llink == NULL) {
			struct tree* newnode = node(value);
			newnode->level = key->level + 1;
			key->llink = newnode;
		}
		else {
			key = key->llink;
			nodecheck(key, value);
		}
	}
	else {
		if (key->rlink == NULL) {
			struct tree* newnode = node(value);
			newnode->level = key->level + 1;
			key->rlink  = newnode;
		}
		else {
			key = key->rlink;
			nodecheck(key, value);
		}
	}
}

void makenode(int value) {
	struct tree* key = root;
	cnt++;
	if (key->data == NULL) {
		root->level = 1;
		root->data = value;
		return;
	}
	nodecheck(key, value);
}

struct tree* searchnode(struct tree* key, int value) {
	if (key->data > value) {
		if (key->llink == NULL) return key;
		key = searchnode(key->llink, value);
	}
	else if (key->data < value) {
		if (key->rlink == NULL) return key;
		key = searchnode(key->rlink, value);
	}
	return key;
}

struct tree* minnode(struct tree* key) {
	while (key->llink != NULL) {
		key = key->llink;
	}
	return key;
}

int removenode(int value) {
	struct tree* key;
	key = root;
	key = searchnode(key, value);
	if (key->data != value) return FALSE;
	cnt--;
	if (key->llink == NULL && key->rlink == NULL) {
		key = NULL;
		printf("error %d", key->data);
		return TRUE;
	}
	else if (key->llink == NULL) {
		key->data = key->rlink->data;
		key->llink = key->rlink->llink;
		key->rlink = key->rlink->rlink;
		return TRUE;
	}
	else if (key->rlink == NULL) {
		key->data = key->llink->data;
		key->rlink = key->llink->rlink;
		key->llink = key->llink->llink;
		return TRUE;
	}

	struct tree* temp;
	struct tree* min;
	min = minnode(key->rlink);
	temp = key->rlink;
	key->data = min->data;
	key->rlink = min->rlink;
	while (key->rlink != NULL) {
		key = key->rlink;
	}
	key->rlink = temp;
	return TRUE;
}

int printnode(struct tree* key) {
	struct tree* temp;
	if (key->data == NULL) return FALSE;
	if (key->rlink != NULL) {
		temp = key->rlink;
		printnode(temp);
	}
	for (int i = 1; i < key->level; i++) {
		printf("\t");
	}
	printf("%d\n", key->data);
	if (key->llink != NULL) {
		temp = key->llink;
		printnode(temp);
	}
}

int main()
{
	struct tree* key;
	int menu, end = FALSE, value;

	system("cls");
	init();

	while (1) {
		printf("Menu Option\n1.삽입 2.삭제 3.탐색 4.출력 5.종료\n");
		scanf("%d", &menu);
		while (getchar() != '\n');
		
		system("cls");
		
		switch (menu) {
			case 1:
				while (1) {
					printf("삽입할 값 : ");
					scanf("%d", &value);
					while (getchar() != '\n');
					if (value > 100 || value < 0) {
						printf("\nError!\n");
						printf("정수만 입력해주세요.\n\n");
						continue;
					}
					break;
				}
				makenode(value);
				break;

			case 2:
				printf("제거할 값 : ");
				scanf("%d", &value);
				if (removenode(value) == FALSE) printf("해당 학생이 존재하지 않습니다.\n");
				break;

			case 3:
				printf("검색할 값 : ");
				scanf("%d", &value);
				struct tree* key;
				key = root;
				key = searchnode(key, value);
				if (key->data != value) printf("해당 노드가 존재하지 않습니다.\n");
				else printf("1\n");
				break;

			case 4:
				key = root;
				if (printnode(key) == FALSE) printf("빈 트리입니다.");
				break;

			case 5:
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
		buf = _getch("\n");
		system("cls");
	}
	
	printf("\n프로그램 종료..\n");

	return 0;
}