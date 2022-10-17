#include <stdio.h>

void print_arr(int* arr, int size);

int main(void) {
    int arr[9] = { 1,2,3,4,5,6,7,8,9 }; //배열 선언

    int size = sizeof(arr)/sizeof(int); //배열의 크기 계산

    print_arr(arr, size);

    return 0;
}

void print_arr(int* arr, int size) {
    for (int i = 0; i < size; i++) { //배열의 크기만큼 반복
        printf("%d", arr[i]); //배열의 i번째값 출력 
    }
}
