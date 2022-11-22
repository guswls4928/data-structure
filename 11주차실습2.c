#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#define NAME_SIZE 30
#define STUDENT_SIZE 100
#define TRUE 1
#define FLASE 0


struct tree{
	struct tree* rlink;
	int data;
	struct tree* llink;
};

struct tree* root;

void init() {
	root = (struct tree*)malloc(sizeof(struct tree));
	root->data = NULL;
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
	if (key->data == NULL) {
		root->data = value;
		return;
	}
	nodecheck(key, value);
}

int searchnode(struct tree* key, int value) {
	if (key->data > value) {
		if (key->llink == NULL) return FALSE;
		key = searchnode(key->llink, value);
	}
	else if (key->data < value) {
		if (key->rlink == NULL) return FALSE;
		key = searchnode(key->rlink, value);
	}
	return TRUE;
}

struct tree* minnode(struct tree* key) {
	while (key->llink != NULL) {
		key = key->llink;
	}
	return key;
}

int removenode(int value) {
	struct tree* parent, * child, * p;
	struct tree* min, * min_parent;
	parent = NULL;
	p = root;
	while (p != NULL && p->data != value) {
		parent = p;
		if (p->data > value) {
			p = p->llink;
		}
		else {
			p = p->rlink;
		}
	}

	if (p == NULL) {
		return FALSE;
	}

	if (p->llink == NULL && p->rlink == NULL) {
		if (parent != NULL) {
			if (parent->llink == p) parent->llink = NULL;
			else parent->rlink = NULL;
		}
		else init();
	}
	else if ((p->llink == NULL) || (p->rlink == NULL)) {
		if (p->llink == NULL) child = p->rlink;
		else child = p->llink;

		if (parent != NULL) {
			if (parent->llink == p) parent->llink = child;
			else parent->rlink = child;
		}
		else root = child;
	}

	else {
		min_parent = p;
		min = p->rlink;
		
		while (min->llink != NULL) {
			min_parent = min;
			min = min->llink;
		}

		if (min_parent->rlink == min) min_parent->rlink = min->llink;
		else min_parent->llink = min->rlink;
		p->data = min->data;
	}
	return TRUE;
}

int printnode(struct tree* key, int level) {
	struct tree* temp;
	if (key->data == NULL) return FALSE;
	if (key->rlink != NULL) {
		temp = key->rlink;
		printnode(temp, level+1);
	}
	for (int i = 1; i < level; i++) {
		printf("\t");
	}
	printf("%d\n", key->data);
	if (key->llink != NULL) {
		temp = key->llink;
		printnode(temp, level+1);
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
					if (value <= 0) {
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
				key = root;
				if (searchnode(key, value) == FALSE) printf("해당 노드가 존재하지 않습니다.\n");
				else printf("해당 노드는 트리내에 존재합니다.\n");
				break;

			case 4:
				key = root;
				int level = 1;
				if (printnode(key, level) == FALSE) printf("빈 트리입니다.");
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