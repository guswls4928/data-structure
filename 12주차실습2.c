#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 정점의 개수
#define NUM 6
// 가중치보다 높은 수
#define INF 999

#define TRUE 1
#define FALSE 0

// 다익스트라 알고리즘을 적용할 그래프
int graph[NUM][NUM] = { 
	{0, INF, 25, 15, INF, INF},
	{15, 0, INF, INF, 10, INF},
	{10, 50, 0, INF, 65, INF},
	{INF, 20, INF, 0, 35, INF},
	{INF, INF, INF, 30, 0, INF},
	{INF, INF, INF, 3, INF, 0}
};
// 최소 가중치 저장할 배열
int dist[NUM];
// 최소 거리를 찾았는 지 저장할 배열
int t[NUM];

// 최소 가중치의 위치를 반환할 함수
int least() {
    int min;
    int min_pos;

    min = INF;
    min_pos = -1;

    for (int i = 0; i < NUM; i++) {
        // 최소 거리를 못찾았고 가중치가 더 작다면
        if (dist[i] < min && t[i] == FALSE) {
            min = dist[i];
            min_pos = i;
        }
    }
    return min_pos;
}

void dijkstra(int start) {
    for (int i = 0; i < NUM; i++) {
        // 시작 정점을 기준으로 가중치 초기화
        dist[i] = graph[start][i]; 
        t[i] = FALSE;
    }

    for (int i = 0; i < NUM; i++) {
        int min = least();
        if (min == -1) break;
        // 해당 정점의 최단 경로를 발견함으로 변경
        t[min] = TRUE;
        for (int j = 0; j < NUM; j++) {
            // 최단 경로를 발견하지 못 한 정점이라면
            if (t[j] == FALSE) {
                // min을 경우해서 가는 것이 j로 가는 것 보다 더 가중치가 적다면
                if (dist[min] + graph[min][j] < dist[j]) {
                    // 가중치 값을 경우한 것으로 변경
                    dist[j] = dist[min] + graph[min][j];
                }
            }
        }
    }

    for (int i = 1; i < NUM; i++) {
        // 만일 최단 경로를 못찾았으면
        if (t[i] == 0) {
            // 최단 경로를 찾았다고 여기고
            t[i] = TRUE;
            // 가중치 값을 무한으로 여김 -> 가는 길이 없음
            dist[i] = INF;
        }
    }
}

int main() {
    int check = 0;
    for (check = 0; check < NUM; check++) {
        dijkstra(check);
        for (int i = 0; i < NUM; i++) {
            printf("\tv%d", i);
        }
        printf("\nv%d", check);
        for (int i = 0; i < NUM; i++) {
            printf("\t%d", dist[i]);
        }
        printf("\n\n");
    }
}