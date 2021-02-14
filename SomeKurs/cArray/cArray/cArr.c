#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cArr.h"

void swapArrStackEl(int* a, int* b) {
	int buf = *a; *a = *b; *b = buf;
}

void arrStackOutConsole(int arr[M][N]) {
	printf("Output matrix:\n\n");
	for (long int i = 0; i < M; ++i) {
		for (long int j = 0; j < N; ++j)
			printf("%d\t", arr[i][j]);
		printf("\n");
	}
}

void arrStackOutConsoleRev(int arr[N][M]) {
	printf("Output matrix:\n\n");
	for (long int i = 0; i < N; ++i) {
		for (long int j = 0; j < M; ++j)
			printf("%d\t", arr[i][j]);
		printf("\n");
	}
}

void arrStackActualOutConsole(int arr[M][N], int t_arr[N][M], short int actualMatrDisp) {
	(actualMatrDisp) ? arrStackOutConsoleRev(t_arr) : arrStackOutConsole(arr);
}

void arrStackFillRand(int arr[M][N]) {
	srand(time(NULL));
	for (long int i = 0; i < M; ++i)
		for (long int j = 0; j < N; ++j)
			arr[i][j] = rand() % MAX_RAND_VALUE;
}

void fliplr(int arr[M][N]) {
	for (long int i = 0; i < M; ++i) {
		long int k = N - 1; 
		for (long int j = 0; j < k; ++j, --k) {
			swapArrStackEl(&arr[i][j], &arr[i][k]);
		}
	}
}

void fliplrRev(int arr[N][M]) {
	for (long int i = 0; i < N; ++i) {
		long int k = M - 1;
		for (long int j = 0; j < k; ++j, --k) {
			swapArrStackEl(&arr[i][j], &arr[i][k]);
		}
	}
}

void transpose(int arr[M][N], int t_arr[N][M], short int* actualMatrDisp) {
	long int i, j;
	for (i = 0; i < M; ++i)
		for (j = 0; j < N; ++j)
			t_arr[j][i] = arr[i][j];
	*actualMatrDisp = 1;	// Set t_arr as current matrix
}

void transposeRev(int arr[M][N], int t_arr[N][M], short int* actualMatrDisp) {
	long int i, j;
	for (i = 0; i < M; ++i)
		for (j = 0; j < N; ++j)
			arr[i][j] = t_arr[j][i];
	*actualMatrDisp = 0; // Set arr as current matrix
}

void turn90(int arr[M][N], int t_arr[N][M], short int* actualMatrDisp) {
	if (!(*actualMatrDisp)) {// Current matrix for rotate is arr
		transpose(arr, t_arr, actualMatrDisp);
		fliplrRev(t_arr); // t_arr matrix is result turn on 90
	}
	else {
		transposeRev(arr, t_arr, actualMatrDisp);
		fliplr(arr); // arr matrix is result turn on 90
	}
}

void turn180(int arr[M][N], int t_arr[N][M], short int* actualMatrDisp) {
	if (!(*actualMatrDisp)) {// Current matrix for rotate is arr
		turn90(arr, t_arr, actualMatrDisp);
		transposeRev(arr, t_arr, actualMatrDisp);
		fliplr(arr); // arr - matrix is result turn on 180
	}
	else {
		turn90(arr, t_arr, actualMatrDisp);
		transpose(arr, t_arr, actualMatrDisp);
		fliplrRev(t_arr); // t_arr - matrix is result turn on 180
	}
}

void turn270(int arr[M][N], int t_arr[N][M], short int* actualMatrDisp) {
	if (!(*actualMatrDisp)) {	// Current matrix for rotate is arr
		fliplr(arr);
		transpose(arr, t_arr, actualMatrDisp); // t_arr - matrix is result turn on 270
	}
	else {
		fliplrRev(t_arr);
		transposeRev(arr, t_arr, actualMatrDisp); // arr - matrix is result turn on 270
	}
}

void rot90(int arr[M][N], long int k, int t_arr[N][M], short int* actualMatrDisp) {
	k = k % 4; // rotation of the matrix in 1 period
	if (k != 0) {
		switch (k) {
		case 1: {
			printf("Turn on 90\n");
			turn90( arr, t_arr, actualMatrDisp);
			break;
			}
		case 2:{
			printf("Turn on 180\n");
			turn180( arr, t_arr, actualMatrDisp);
			break;
			}
		case 3: {
			printf("Turn on 270\n");
			turn270( arr, t_arr, actualMatrDisp);
			break;
			}
		case -3: {
			printf("Turn on -270\n");
			turn90( arr, t_arr, actualMatrDisp);
			break;
			}
		case -2: {
			printf("Turn on -180\n");
			turn180( arr, t_arr, actualMatrDisp);
			break;
			}
		case -1: {
			printf("Turn on -90\n");
			turn270( arr, t_arr, actualMatrDisp);
			break;
			}
		}
	}
	else {
		printf("Turn on 0\n");
	}

	arrStackActualOutConsole(arr, t_arr, actualMatrDisp);
}
