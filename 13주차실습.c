#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define mix 50
int i, j, temp;
int num[N];

void init() {
    for (i = 0; i < N; i++) num[i] = i + 1;
    srand((unsigned)time(NULL));
}

void swap(int* arr, int a, int b) {
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// 난수 생성
void randarr(int* arr) {
    // mix만큼 수를 섞음
    for (i = 0; i < mix; i++) {
        int x = rand() % N;
        int y = rand() % N;

        // x와 y가 같지 않다면 둘의 값을 교환
        if (x != y) swap(num, x, y);
    }
    printf("\n");
    for (i = 0; i < N; i++) {
        arr[i] = num[i];
        printf("%d ", arr[i]);
    }
}

// 버블 정렬
void bubble_sort(int* arr) {
    // 0부터 N번 반복
    for (i = 0; i < N; i++) {
        printf("\n");
        // 0번 인덱스부터 N-i-1인덱스를 탐색
        for (j = 0; j < N - i - 1; j++) {
            // 자신이 다음 수보다 크다면 둘을 교환
            if (arr[j] > arr[j + 1]) swap(arr, j, j + 1);
        }
        for (j = 0; j < N; j++) printf("%d ", arr[j]);
    }
}

// 삽입 정렬
void insert_sort(int* arr) {
    // 1부터 N번 반복
    for (i = 1; i < N; i++) {
        printf("\n");
        // i인덱스부터 1번 인덱스를 탐색
        for (j = i; j > 0; j--) {
            // 자신이 이전 수보다 작다면 둘을 교환
            if (arr[j] < arr[j - 1]) swap(arr, j, j - 1);
            else break;
        }
        for (j = 0; j < N; j++) printf("%d ", arr[j]);
    }
}

// 퀵 정렬
int quick(int* arr, int l, int r) {
    // l번 인덱스 을 기준으로 정렬
    int pivot = l;
    
    // 다음 인덱스부터 비교
    l++;

    // l이 r보다 작다면 반복
    while (l < r) {
        // l이 r보다 작거나 같고 l인덱스 값이 pivot인덱스 값보다 작거나 같다면 l반복증가
        while (l <= r && arr[l] <= arr[pivot]) l++;
        // r이 l보다 크고 r인덱스 값이 pivot인덱스 값보다 크거나 같다면 r반복증가
        while (r > l && arr[r] >= arr[pivot]) r--;

        // l이 r보다 크거나 같으면 반복문 바로 종료
        if (l >= r) break;
        
        // l인덱스와 r인덱스 값을 교환
        swap(arr, l, r);
    }

    // l을 감소하며 pivot인덱스와 l인덱스 값을 교환
    swap(arr, pivot, --l);
    
    printf("\n");
    for (j = 0; j < N; j++) printf("%d ", arr[j]);

    // l을 반환
    return l;
}

void quick_sort(int* arr, int l, int r) {
    // l이 r보다 작다면(더 나눌 수 있을때)
    if (l < r) {
        // arr을 정렬하고 정렬된 값의 인덱스를 temp저장
        temp = quick(arr, l, r);

        // 정렬된 인덱스 양 옆을 분할해 다시 정렬
        quick_sort(arr, l, temp - 1);
        quick_sort(arr, temp + 1, r);
    }
}

// 병합 정렬
void merge(int* arr, int l, int m, int r) {
    int temparr[N], k = l;
    i = l;
    j = m + 1;

    // i이 m보다 작거나 같고 j가 r보다 작거나 같다면 반복
    while (i <= m && j <= r) {
        // 인덱스 값이 i인덱스 값보다 크거나 같다면 더미배열 k인덱스에 저장하고 k와 i값을 증가
        if (arr[i] <= arr[j]) temparr[k++] = arr[i++];
        else temparr[k++] = arr[j++];
    }
    // 
    while (i <= m) temparr[k++] = arr[i++];
    // 
    while (j <= r) temparr[k++] = arr[j++];
    
    // 정렬한 값을 원배열에 저장
    for (int a = l; a <= r; a++) arr[a] = temparr[a];
}

void merge_sort(int arr[], int l, int r) {
    int m;
    // l이 r보다 작다면(더 나눌 수 있을때)
    if (l < r) {
        // 중간 인덱스를 m에 저장
        m = (l + r) / 2;
        // l부터 m까지 분할하여 다시 정렬
        merge_sort(arr, l, m);
        // m+1부터 r까지 분할하여 다시 정렬
        merge_sort(arr, m + 1, r);
        // l부터 r까지 정렬
        merge(arr, l, m, r);
        
        printf("\n");
        for (i = 0; i < N; i++) printf("%d ", arr[i]);
    }
}

int main() {
    int arr[N];

    init();

    printf("버블 정렬");
    randarr(arr);
    bubble_sort(arr);

    printf("\n\n");
    printf("삽입 정렬");
    randarr(arr);
    insert_sort(arr);

    printf("\n\n");
    printf("퀵 정렬");
    randarr(arr);
    quick_sort(arr, 0, N-1);

    printf("\n\n");
    printf("병합 정렬");
    randarr(arr);
    merge_sort(arr, 0, N-1);
}