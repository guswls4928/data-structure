#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct Stack {
    int top;
    char s[100];
}Stack; //식을 저장할 구조체

void push(Stack* s, char e) { //push구현
    s->top++;
    s->s[s->top] = e;
}

char pop(Stack* s) { //pop구현
    char tmp = s->s[s->top]; //top수를 tmp저장
    s->top--; //top감소
    return tmp;
}
int isempty(Stack* s) { //빈 스택인지 확인
    if (s->top != -1) //top이 -1이 아니라면(빈게 아니라면)
        return 0; //false 반환
    return 1; //true반환
}

char top(Stack* s) { //현재 최고 위치 표시
    return s->s[s->top];
}

int isOperator(char op) { //연산자 확인
    switch (op) {
    case '(': case ')':
        return 0;
    case '+': case '-':
        return 1;
    case '*': case '/':
        return 2;
    default:
        return -1;
    }
}

void post(char* str) { //후위표기법으로 변환
    int i = 0;
    Stack s;
    s.top = -1;
    for (i = 0; i < strlen(str); i++) {
        if (isOperator(str[i]) == -1) { //연산자가 아니라면 출력
            printf("%c", str[i]);
        }
        else if (str[i] == '(') { //여는 괄호라면 push
            push(&s, str[i]);
        }
        else if (str[i] == ')') { //닫는 괄호라면
            while (top(&s) != '(') { //여는 괄호가 나올때까지 pop하여 출력
                printf("%c", pop(&s));
            }
            pop(&s);
        }
        else if (isOperator(str[i]) >= 1) { //연산자라면
            while (!isempty(&s) && isOperator(str[i]) <= isOperator(top(&s))) { //스택이 비지 않았고 스택에 있는 연산자의 우선순위가 높다면 pop하여 출력
                printf("%c", pop(&s));
            }
            push(&s, str[i]);
        }
    }
    while (!isempty(&s)) { //스택이 빌때까지 출력
        printf("%c", pop(&s));
    }
}

int main(void) {
    char str[100];
    int i = 0;
    scanf("%s", str);
    post(str);
}