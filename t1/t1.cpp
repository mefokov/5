#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <locale>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include <queue>

void BFS(int p, int arr);
int **mass, *visit;

void BFS(int p, int arr) {
	std::queue <int> Q;
	Q.push(p);
	visit[p] = 1;
	while (!Q.empty()) {
		p = Q.front();
		printf("%d ", p);
		Q.pop();
		for (int i = 0; i <= arr; i++) {
			if (mass[p][i] == 1 && visit[i] == false) {
				Q.push(i);
				visit[i] = 1;
			}
		}
	}
}

int main()
{
	setlocale(0, "rus");

	int p, k;
	int arr;

	printf("Введите матрицу:");
	scanf_s("%d", &arr);

	mass = (int**)malloc(arr*sizeof(int));
	for (int i = 0; i<arr;i++) {
		mass[i] = (int *)malloc(arr*sizeof(int));
	}
	visit = (int*)malloc(arr*sizeof(int));

	for (int i = 0;i<arr;i++) {
		visit[i] = 0;
	}

	printf("Введем матрицу:\n");
	for (int i = 0;i<arr;i++) {
		for (int j = 0;j<i + 1;j++) {
			k = rand() % 2;
			if (i != j) {
				mass[i][j] = k;
				mass[j][i] = k;
			}
			else {
				mass[i][j] = 0;
			}
		}
	}
	for (int i = 0;i<arr;i++) {
		for (int j = 0;j<arr;j++) {
			printf("%d ", mass[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0;i<1;i++) {
		printf("Выберете вершину с которой необходимо начанете обход:");
		scanf_s("%d", &p);
		if (p <= arr) {
			printf("\nВы проходите");

		}
		else {
			printf("Выберете новую координату\n");
			i--;
		}
	}
	printf("\n");
	BFS(p, arr);
}