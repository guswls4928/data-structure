#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#define NAME_SIZE 30
#define STUDENT_SIZE 100
#define TRUE 1
#define FALSE 0


struct tree {
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

void nodecheck(struct tree* key, int value) {
	// key의 값이 추가할 값보다 크다면
	if (key->data > value) {
		// key의 왼쪽 자식이 없다면
		if (key->llink == NULL) {
			// 새로운 노드를 생성
			struct tree* newnode = node(value);
			// 새로운 노드를 왼쪽 자식에 저장
			key->llink = newnode;
		}
		// 자식이 있다면
		else {
			// 왼쪽 자식을 기준으로 검사
			key = key->llink;
			nodecheck(key, value);
		}
	}
	// key의 값이 추가할 값보다 작거나 같다면
	else {
		// key의 오른쪽 자식이 없다면
		if (key->rlink == NULL) {
			// 새로운 노드를 생성
			struct tree* newnode = node(value);
			// 새로운 노드를 오른쪽 자식에 저장
			key->rlink = newnode;
		}
		// 자식이 있다면
		else {
			// 오른쪽 자식을 기준으로 검사
			key = key->rlink;
			nodecheck(key, value);
		}
	}
}

void makenode(int value) {
	// key에 root를 저장
	struct tree* key = root;
	// root의 값이 없다면
	if (key->data == NULL) {
		// 삽입할 값을 root에 저장
		root->data = value;
		return;
	}
	// key를 기준으로 노드를 생성할 위치를 검사
	nodecheck(key, value);
}

int searchnode(struct tree* key, int value) {
	// key의 값이 검색할 값보다 크다면
	if (key->data > value) {
		// key의 왼쪽 자식이 없다면 FALSE를 반환
		if (key->llink == NULL) return FALSE;
		// key에 key의 왼쪽 자식을 기준으로 검색한 값을 저장
		key = searchnode(key->llink, value);
	}
	// key의 값이 검색할 값보다 작다면
	else if (key->data < value) {
		// key의 오른쪽 자식이 없다면 FALSE를 반환
		if (key->rlink == NULL) return FALSE;
		// key에 key의 오른쪽 자식을 기준으로 검색한 값을 저장
		key = searchnode(key->rlink, value);
	}
	return TRUE;
}

struct tree* minnode(struct tree* key) {
	// key의 왼쪽 자식이 없을 때까지
	while (key->llink != NULL) {
		// key를 key의 왼쪽 자식으로
		key = key->llink;
	}
	return key;
}

int removenode(int value) {
	struct tree* parent, * child, * p;
	struct tree* min, * min_parent;
	parent = NULL;
	p = root;

	// p의 값이 있고 삭제할 값이 아닐 때까지
	while (p != NULL && p->data != value) {
		// 부모 노드에 p를 저장
		parent = p;
		// p의 값이 삭제할 값보다 크다면
		if (p->data > value) {
			// p에 p의 왼쪽 자식을 저장
			p = p->llink;
		}
		// 아니라면
		else {
			// p에 p의 오른쪽 자식을 저장
			p = p->rlink;
		}
	}

	// p가 값이 없다면
	if (p == NULL) {
		// FALSE를 반환
		return FALSE;
	}

	// p의 자식 노드가 없다면 
	if (p->llink == NULL && p->rlink == NULL) {
		// 부모 노드가 있다면
		if (parent != NULL) {
			// 부모 노드의 왼쪽 자식이 p라면 왼쪽 자식을 삭제
			if (parent->llink == p) parent->llink = NULL;
			// 아니라면 부모 노드의 오른쪽 자식을 삭제
			else parent->rlink = NULL;
		}
		// 부모가 없다면 초기화
		else init();
	}
	// 한쪽 자식이 없다면
	else if ((p->llink == NULL) || (p->rlink == NULL)) {
		// p의 왼쪽 자식이 없다면 자식 노드에 p의 오른쪽 자식을 저장
		if (p->llink == NULL) child = p->rlink;
		// 아니라면 자식노드에 p의 왼쪽 자식을 저장
		else child = p->llink;

		// 만일 부모 노드가 있다면
		if (parent != NULL) {
			// 부모 노드의 왼쪽 노드가 p라면 부모 노드의 왼쪽 노드를 자식 노드로 저장
			if (parent->llink == p) parent->llink = child;
			// 아니라면 부모 노드의 오른쪽 노드를 자식 노드로 저장
			else parent->rlink = child;
		}
		// 부모 노드가 없다면 root에 자식 노드를 저장
		else root = child;
	}

	// 자식 노드가 둘 다 있다면
	else {
		// 최소 부모 노드에 p를 저장
		min_parent = p;
		// 최소 노드에 p의 오른쪽 노드를 저장
		min = p->rlink;

		// 최소 노드의 왼쪽 노드가 존재할 때까지
		while (min->llink != NULL) {
			// 최소 부모 노드에 최소 노드를 저장
			min_parent = min;
			// 최소 노드에 최소 노드의 왼쪽 자식을 저장
			min = min->llink;
		}

		// 최소 부모 노드의 오른쪽 자식이 최소 노드와 같다면
		if (min_parent->rlink == min) {
			// 최소 부모 노드의 오른쪽 자식에 최소 노드 왼쪽의 자식을 저장
			min_parent->rlink = min->llink;
		}
		// 아니라면 최소 부모 노드의 왼쪽 자식에 최소 노드 오른쪽의 자식을 저장
		else min_parent->llink = min->rlink;
		// p의 값에 최소 노드의 값을 저장
		p->data = min->data;
	}
	return TRUE;
}

int printnode(struct tree* key, int level) {
	// key의 값이 없다면 FALSE를 반환
	if (key->data == NULL) return FALSE;
	// key의 오른쪽 값이 있다면
	if (key->rlink != NULL) {
		// key의 오른쪽 값을 기준으로 깊이를 1증가하여 출력 함수 호출
		printnode(key->rlink, level + 1);
	}
	// 깊이 만큼 반복
	for (int i = 1; i < level; i++) {
		printf("\t");
	}
	printf("%d\n", key->data);
	// key의 왼쪽 값이 있다면
	if (key->llink != NULL) {
		// key의 왼쪽 값을 기준으로 깊이를 1증가하여 출력 함수 호출
		printnode(key->llink, level + 1);
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
