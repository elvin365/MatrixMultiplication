#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#define N 10//12000
int** initMEM(int** p);
void show(int** p);
void initValue(int**);
int** Ymnoshenie(int**,int**,int**);
int main()
{
	int **p=NULL;
	srand(time(NULL));
	p=initMEM(p);
	initValue(p);
	//show(p);
	//количество столбцов первой матрицы должно равняться количеству строк второй 
	int **b = NULL;
	b = initMEM(b);
	initValue(b);
	printf("\n");
	//show(b);
	int **c=NULL;
	c = initMEM(c);
	printf("\n");
	clock_t start, stop;
	start = clock();
	c = Ymnoshenie(p, b,c);
	stop = clock();
	printf("\n\t\t\t\t\t\t%f  seconds were spent", (double)(stop - start) / 100 / CLOCKS_PER_SEC); // приведение типов
	printf("\n");
	show(c);
	return 0;
}

int** initMEM(int** p)
{
	int i;
	p = (int**)malloc(sizeof(int*)*N);
	for (i = 0; i < N; i++)
	{
		p[i] = (int*)malloc(sizeof(int)*N);
	}
	return p;
}
void initValue(int** p)
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			p[i][j] = rand() % 100;
		}
	}
}
void show(int** p)
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		printf("\n");
		for (j = 0; j < N; j++)
		{
			printf("%5d",p[i][j] = rand() % 100);
		}
	}
}
int** Ymnoshenie(int** a, int** b ,int **result)
{
	int row, col, inner;
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) { 
			for (int inner = 0; inner < N; inner++) {
				result[row][col] += a[row][inner] * b[inner][col];
			}
		}
	}
	return result;
}