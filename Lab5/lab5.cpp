#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<random>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int n = 10, ** G = NULL, size = 0, * deg = NULL, * loop = NULL;
	printf("Введи количество вершин \n");
	scanf("%d", &n);
	deg = (int*)malloc(n * sizeof(int));
	loop = (int*)malloc(n * sizeof(int));
	G = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		deg[i] = 0;
		loop[i] = 0;
		G[i] = (int*)malloc(n * sizeof(int));


	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			G[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			G[i][j] = rand() % 2;
			G[j][i] = G[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			size += G[i][j];
		}

	}
	printf("size= %d \n", size);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				deg[i] += 2 * G[i][j];
				loop[i] += 2 * G[i][j];
			}
			else {
				deg[i] += G[i][j];
			}

		}

	}

	for (int i = 0; i < n; i++)
	{
		if (deg[i] - loop[i] == 0)printf("Вершина %d,изолированная\n", i);
		if (deg[i] - loop[i] == 1)printf("Вершина %d,концевая\n", i);
		if (deg[i] - loop[i] == n-1)printf("Вершина %d,доминирующая\n", i);
	}

	scanf("%d", &n);

	return 0;
}