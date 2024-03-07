#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int x, y;
	int tomato, degree;
}NODE;

#define MAX_SIZE 10000000
NODE queue[MAX_SIZE];
int front = 0;
int rear = 0;

void Enque(NODE x);
NODE Deque();
int bfs(NODE** matrix, int** visited, int x, int y);

void Enque(NODE x) {
	if ((rear + 1) % MAX_SIZE == front)
		return;
	
	queue[rear] = x;
	rear = (rear + 1) % MAX_SIZE;
}

NODE Deque() {
	if (front == rear)
		return;

	NODE item = queue[front];
	front = (front + 1) % MAX_SIZE;

	return item;
}

int bfs(NODE** matrix, int** visited, int x, int y) {
	int i, j, degree;
	NODE temp;

	while (front != rear) {
		temp = Deque();
		degree = temp.degree;
		i = temp.x;
		j = temp.y;

		if (i + 1 < x && !visited[i + 1][j]) {
			matrix[i + 1][j].degree = degree + 1;
			visited[i + 1][j] = 1;
			Enque(matrix[i + 1][j]);
		}
		if (i - 1 >= 0 && !visited[i-1][j]) {
			matrix[i - 1][j].degree = degree + 1;
			visited[i - 1][j] = 1;
			Enque(matrix[i - 1][j]);
		}
		if (j + 1 < y && !visited[i][j+1]) {
			matrix[i][j + 1].degree = degree + 1;
			visited[i][j + 1] = 1;
			Enque(matrix[i][j + 1]);
		}
		if (j - 1 >= 0 && !visited[i][j-1]) {
			matrix[i][j - 1].degree = degree + 1;
			visited[i][j - 1] = 1;
			Enque(matrix[i][j - 1]);
		}
	}

	//탐색이 끝났는데 안 익은 토마토가 있다면 return -1;
	int flag = 0;
	for (i = 0; i < x; i++)
		for (j = 0; j < y; j++)
			if (visited[i][j] == 0) {
				flag = 1;
				break;
			}
	if (flag)
		return -1;

	return degree;
}

int main() {
	int x, y;
	scanf("%d %d", &y, &x);
	
	NODE** matrix = (NODE**)calloc(x, sizeof(NODE*));
	int i, j, input;
	for (i = 0; i < x; i++)
		matrix[i] = (NODE*)calloc(y, sizeof(NODE));

	int** visited = (int**)calloc(x, sizeof(int*));
	for (i = 0; i < x; i++)
		visited[i] = (int*)calloc(y, sizeof(int));

	int numEmpty = 0;
	for (i = 0; i < x; i++)
		for (j = 0; j < y; j++) {
			scanf("%d", &input);
			matrix[i][j].tomato = input;
			matrix[i][j].x = i;
			matrix[i][j].y = j;
			matrix[i][j].degree = 0;

			if (input == 1) {
				visited[i][j] = 1;
				Enque(matrix[i][j]);
			}
			//없는 칸은 받을 때부터 방문했다 치기
			else if (input == -1) {
				visited[i][j] = 1;
				numEmpty++;
			}
		}

	//전부 빈칸이면 -1 출력
	if (x * y == numEmpty) {
		printf("-1\n");
		return 0;
	}

	//이미 다 익어있다면 0 출력
	if (x * y - numEmpty == rear) {
		printf("0\n");
		return 0;
	}

	int degree = bfs(matrix, visited, x, y);

	printf("%d\n", degree);

	for (i = 0; i < x; i++)
		free(matrix[i]);
	free(matrix);

	for (i = 0; i < x; i++)
		free(visited[i]);
	free(visited);

	return 0;
}