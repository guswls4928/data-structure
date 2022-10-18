#include <stdio.h>
#include <math.h>

typedef struct { //원의 정보를 저장할 구조체
	double x, y, r;
}CIRCLE;

typedef struct { //점의 정보를 저장할 구조체
	double x, y;
}POINT;

void circle_to_point(CIRCLE c1, POINT p1) { //점과 원사이의 관계를 측정하는 함수
	double d = sqrt(pow((c1.x - p1.x), 2) + pow((c1.y - p1.y), 2)); //점과 원의 중심사이의 거리를 측정후 d에 저장

	if (d < c1.r) { //점과 원의 중심의 거리의 거리가 원의 반지름보다 작으면
		printf("점은 원 안입니다.\n");
	}
	else if (d > c1.r) { //점과 원의 중심의 거리의 거리가 원의 반지름보다 크면
		printf("점은 원 밖입니다.\n");
	}
	else { //점과 원의 중심의 거리가 원의 반지름과 같으면
		printf("점은 원 위입니다.\n");
	}
}

void circle_to_circle(CIRCLE c1, CIRCLE c2) { //원과 원사이의 관계를 측정하는 함수
	if ((c1.x == c2.x && c1.y == c2.y) && c1.r == c2.r) { //두 원의 x,y좌표가 같고 반지름이 같으면
		printf("일치합니다.\n");
	}
	double d = sqrt(pow((c1.x - c2.x), 2) + pow((c1.y - c2.y), 2)); //두 원 사이의 거리를 측정후 d에 저장
	if ((d == (c1.r + c2.r)) || ((d + c1.r) == c2.r || (d + c2.r) == c1.r)) { //두 원의 반지름의 합이 더 원 사이의 거리와 같거나 두 원사이의 거리와 한 원의 반지름과 더했을때 다른 원의 반지름과 같을 경우
		printf("한 점 일치합니다.\n");
	}
	else if ((d + c2.r) < c1.r) { //두 원사이의 거리와 원B의 반지름 합이 원A의 반지름보다 작을경우
		printf("원B가 원A안에 있습니다.\n");
	}
	else if ((d + c1.r) < c2.r) { //두 원사이의 거리와 원A의 반지름 합이 원B의 반지름보다 작을경우
		printf("원A가 원B안에 있습니다.\n");
	}
	else if (d < (c1.r + c2.r) && (d >= c1.r || d >= c2.r)) { //두 원사이의 거리가 두 원의 반지름의 합보다 작으며, 한 원의 반지름보다 크거나 같을경우
		printf("두 점 일치합니다.\n");
	}
	else {
		printf("두 원은 관계가 없습니다.\n");
	}
}

int main() {
	double x, y, r;

	printf("원A을 입력하세요(x,y,r) : ");
	scanf("%lf %lf %lf", &x, &y, &r);
	r = sqrt(r);
	CIRCLE c1 = { x,y,r };

	printf("점을 입력하세요(x,y) : ");
	scanf("%lf %lf", &x, &y);
	POINT p1 = { x,y };

	circle_to_point(c1, p1);

	printf("원B을 입력하세요(x,y,r) : ");
	scanf("%lf %lf %lf", &x, &y, &r);
	r = sqrt(r);
	CIRCLE c2 = { x,y,r };

	circle_to_circle(c1, c2);

	return 0;
}
