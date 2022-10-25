#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	int m, n, p, i, j;

	printf("행열1의 세로 크기 : ");
	scanf("%d", &m);
	printf("행열1의 가로, 행열2의 세로 크기 : ");
	scanf("%d", &n);
	printf("행열2의 가로 크기 : ");
	scanf("%d", &p);

	int** arr1;
	int** arr2;
	int** arr3;
	arr1 = (int**)malloc(sizeof(int*) * m); //m크기의 1차원 배열 생성
	for (i = 0; i < m; i++) { //m*n크기의 2차원 배열 생성
		arr1[i] = (int *)malloc( sizeof(int) * n );
	}
	arr2 = (int**)malloc(sizeof(int*) * n); //n크기의 1차원 배열 생성
	for (i = 0; i < n; i++) { //n*p크기의 2차원 배열 생성
		arr2[i] = (int*)malloc(sizeof(int) * p);
	}
	arr3 = (int**)malloc(sizeof(int*) * m); //m크기의 1차원 배열 생성
	for (i = 0; i < m; i++) { //m*p크기의 2차원 배열 생성
		arr3[i] = (int*)malloc(sizeof(int) * p);
	}
	
	for (i = 0; i < m; i++) { //m*n크기의 배열에 값 입력
		for (j = 0; j < n; j++) {
		scanf("%d", &arr1[i][j]);
		}
	}
	for (i = 0; i < n; i++) { //n*p크기의 배열에 값 입력
		for (j = 0; j < p; j++) {
			scanf("%d", &arr2[i][j]);
		}	
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < p; j++) {
			int tmp = 0;
			for (int k = 0; k < n; k++) { //행렬곱
				tmp += arr1[i][k] * arr2[k][j];
			}
			arr3[i][j] = tmp; //m*p크기의 배열에 행렬곱 저장
		}
	}

	printf("array1\n");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}
	printf("array2\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < p; j++) {
			printf("%d ", arr2[i][j]);
		}
		printf("\n");
	}
	printf("array3\n");
	for (i = 0; i < m; i++) {
		for (j = 0; j < p; j++) {
			printf("%d ", arr3[i][j]);
		}
		printf("\n");
	}
}