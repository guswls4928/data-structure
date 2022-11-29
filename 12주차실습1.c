#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define VERTICES_NUM 4

struct node{
	int vertices;
	struct node* link;
};
struct node* head[VERTICES_NUM];

void init() {
	for (int i = 0; i < VERTICES_NUM; i++) head[i] = NULL;
}

void insert_edge(int v, int w) {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->vertices = w;
	temp->link = head[v];
	head[v] = temp;
}

void print() {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	for (int i = 0; i < VERTICES_NUM; i++) {
		printf("\n정점 %d의 인접 리스트 : %d ", i, i);
		temp = head[i];
		while (temp) {
			printf("-> %d ", temp->vertices);
			temp = temp->link;
		}
	}
}

int main() {
	int adj[VERTICES_NUM][VERTICES_NUM] = { {0,1,1,0},{1,0,1,1},{1,1,0,1},{0,1,1,0} };
	
	init();

	for (int i = VERTICES_NUM-1; i >= 0; i--) {
		for (int j = VERTICES_NUM-1; j >= 0; j--) {
			if (adj[i][j]) insert_edge(i, j);
		}
	}

	printf("주어진 인접행렬의 인접리스트");
	print();

	return 0;
}