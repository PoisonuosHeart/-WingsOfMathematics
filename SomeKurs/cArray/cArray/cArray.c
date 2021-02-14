#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "cArr.h"
#include <assert.h>

void copy(int arr[M][N], int arrCopy[M][N]) {
	for (long int i = 0; i < M; ++i)
		for (long int j = 0; j < M; ++j)
			arrCopy[i][j] = arr[i][j];
}

int main()
{
	setlocale(LC_ALL, "rus");

	// Prepare Data
	int arr[M][N], t_arr[N][M];  short int actualMatrDisp = 0;
	arrStackFillRand(arr);
	arrStackActualOutConsole(arr, t_arr, actualMatrDisp);

	{
		/* Vertical Matrix Reflection Testing
		* copyArr := arr
		* Reflection
		* check elemnts reflection matrix and original (arr[0 + i][0 + j] must be eq copyArr[i][N - 1 - j])
		*/
		int copyArr[M][N];
		copy(arr, copyArr);
		fliplr(copyArr);

		for (long int i = 0; i < M; ++i)
			for (long int j = 0; j < N; ++j)
				assert(arr[i][j] == copyArr[i][N - 1 - j]);
		arrStackActualOutConsole(copyArr, t_arr, actualMatrDisp);
		printf("\ntest reflaction passed\n\n");
	}

	{
		/*Matrix transposition Testing
		* Transposition
		* check elemnts reflection matrix and original rows must be equals columns)
		*/
		transpose(arr, t_arr, &actualMatrDisp);

		for (long int i = 0; i < M; ++i)
			for (long int j = 0; j < N; ++j)
				assert(arr[i][j] == t_arr[j][i]);
		arrStackActualOutConsole(arr, t_arr, actualMatrDisp);
		actualMatrDisp = 0; // reset original matr flag
		printf("\ntest transposition passed\n\n");
	}

	{
		/*Matrix turn on 90 degrees Testing
		* Transposition
		* check position element with index 0 & 0 after turn
		*/
		int copyArr[M][N];
		copy(arr, copyArr);
		transpose(arr, t_arr, &actualMatrDisp);
		actualMatrDisp = 0;

		for (int i = -5; i < 6; ++i) {
			rot90(arr, i, t_arr, &actualMatrDisp);
			switch (i % 4) {
			case 0:
				(actualMatrDisp) ?
					assert(t_arr[0][0] == t_arr[0][0])
					:
					assert(arr[0][0] == arr[0][0])
					;
				break;
			case 1:
				(actualMatrDisp) ?
					assert(arr[0][0] == t_arr[0][M - 1])
					:
					assert(t_arr[0][0] == arr[0][N - 1])
					;
				break;
			case 2:
				(actualMatrDisp) ?
					assert(arr[0][N - 1] == t_arr[N - 1][M - 1])
					:
					assert(t_arr[0][0] == arr[0][N - 1])
					;
				break;
			case 3:
				(actualMatrDisp) ?
					assert(t_arr[0][0] == arr[0][0])
					:
					assert(arr[0][0] == t_arr[0][0])
					;
				break;
			case (-1):
				(actualMatrDisp) ?
					assert(t_arr[0][0] == arr[0][0])
					:
					assert(arr[0][0] == t_arr[0][0])
					;
				break;
			case -2:
				(actualMatrDisp) ?
					assert(arr[0][N - 1] == t_arr[N - 1][M - 1])
					:
					assert(t_arr[0][0] == arr[0][N - 1])
					;
				break;
			case -3:
				(actualMatrDisp) ?
					assert(arr[0][0] == t_arr[0][M - 1])
					:
					assert(t_arr[0][0] == arr[0][N - 1])
					;
				break;
			}
		}

		actualMatrDisp = 0; // reset original matr flag
		copy(copyArr, arr); // reset changes of test
		printf("\ntest transposition passed\n\n");
	}

	system("pause");
	return 0;
}

