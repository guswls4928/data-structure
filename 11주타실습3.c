#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define HEAP_SIZE 1000
#define TRUE 1
#define FALSE 0

int heap[HEAP_SIZE];
int heapCount;

void init() {
    for (int i = 0; i < HEAP_SIZE; i++) heap[i] = 0;
    heapCount = 0;
}

void push(int value) {
	// 힙의 개수를 1증가 시키고 해당 인덱스에 값을 저장
    heap[++heapCount] = value;

    int child = heapCount;
    int parent = child / 2;

	// 부모인덱스가 0이 아니라면 반복
    while (parent) {
		// 부모의 값이 자식의 값보다 작다면 교환
        if (heap[parent] < heap[child]) {
            int temp = heap[parent];
            heap[parent] = heap[child];
            heap[child] = temp;
            
			// 위치를 바꾼 인덱스위치로 
			child = parent;
			parent = child / 2;
        }
		// 내가 더 크다면 자리를 찾았으므로 종료.
        else {
            break;
        }
    }
}

int empty() {
    // 힙 사이즈가 0이면 TRUE 반환, 그 외 FALSE 반환
    return (heapCount ? FALSE : TRUE);
}

int pop() {
    // 가장 큰값을 res 에 저장
    int res = heap[1];
    // 맨 마지막 데이터를 맨위로 올린다음 힙 사이즈 1감소
    heap[1] = heap[heapCount--];

    int parent = 1;
    int child = 2;
    // 자식의 인덱스가 힙 크기보다 작거나 같으면 반복
    while (child <= heapCount) {

        // 오른쪽 자식의 인덱스번호가 힙 크기 이하이면서 왼쪽 자식보다 더 큰경우
        if (child + 1 <= heapCount && heap[child] < heap[child + 1]) {
            // 비교할 자식의 인덱스를 1증가
            child += 1;
        }

		// 부모의 값이 자식의 값보다 작다면 교환
        if (heap[parent] < heap[child]) {
            int temp = heap[parent];
            heap[parent] = heap[child];
            heap[child] = temp;

            // 위치를 바꾼 인덱스위치로 
            parent = child;
            child = parent * 2;
        }
        // 내가 더 크다면 자리를 찾았으므로 종료.
        else {
            break;
        }
    }
    return res;
}

int search(int value) {
	// 힙 크기만큼 반복
	for (int i = 1; i <= heapCount; i++) {
		// 해당 인덱스의 값이 값이랑 같다면 TRUE반환
		if (heap[i] == value) return TRUE;
	}
	// 비교되지 않았다면 FALSE반환
	return FALSE;
}

int main() {
	int menu, end = FALSE, value, cnt;

	system("cls");
	init();

	while (1) {
		printf("Menu Option\n1.삽입 2.삭제 3.탐색 4.종료\n");
		scanf("%d", &menu);
		while (getchar() != '\n');

		system("cls");

		switch (menu) {
		case 1:
			printf("삽입할 값의 개수 : ");
			scanf("%d", &cnt);
			for (int i = 0; i < cnt; i++) {
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
				push(value);
			}
			break;

		case 2:
			if (empty() == TRUE) {
				printf("저장된 값이 없습니다..\n");
				break;
			}
			printf("제거된 값 : %d", pop());
			break;

		case 3:
			printf("검색할 값 : ");
			scanf("%d", &value);
			if (search(value) == FALSE) printf("해당 노드가 존재하지 않습니다.\n");
			else printf("해당 값은 저장되어 있습니다.\n");
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
		buf = _getch("\n");
		system("cls");
	}

	printf("힙으로 정렬된 값 : ");
	//배열이 비기 전까지 반복
	while (empty() != TRUE) {
		printf("%d ", pop());
	}
	printf("\n\n프로그램 종료..\n");

	return 0;
}