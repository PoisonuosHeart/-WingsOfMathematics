#pragma once

#define MAX_RAND_VALUE 100 

#define M 4	// number of matrix rows
#define N 3 // number of matrix columns


// Swaps the values of elements a & b
void swapArrStackEl(int *a, int *b);

// Output arr in console
void arrStackOutConsole(int arr[M][N]);
void arrStackOutConsoleRev(int arr[N][M]);
void arrStackActualOutConsole(int arr[M][N], int t_arr[N][M], short int actualMatrDisp);

// Fills the arr array with random values, in case of an error, it returns 0. 
void arrStackFillRand(int arr[M][N]);

// Reflect the matrix vertically, otherwise return 0. 
// The function with the ending Rev takes a matrix, dimension N* M
void fliplr(int arr[M][N]);
void fliplrRev(int arr[N][M]);

//Outputs the transposed matrix arr, otherwise returns 0. 
// The function with the ending Rev takes a matrix, dimension M* N! actualMatrDisp = matrix number result
void transpose(int arr[M][N], int t_arr[N][M], short int* actualMatrDisp);
void transposeRev(int arr[M][N], int t_arr[N][M], short int* actualMatrDisp);

//Makes a turn. Returns 0 on error. actualMatrDisp = matrix number result
//short int turnOn(short int (*turnX)(int arr[M][N], int t_arr[N][M], short int* actualMatrDisp), int arr[M][N], int t_arr[N][M], short int* actualMatrDisp);
void turn90(int arr[M][N], int t_arr[N][M], short int* actualMatrDisp);
void turn180(int arr[M][N], int t_arr[N][M], short int* actualMatrDisp);
void turn270(int arr[M][N], int t_arr[N][M], short int* actualMatrDisp);

// Rotate matrix 90 k times. Returns 0 on error. actualMatrDisp = matrix number result
void rot90(int arr[M][N], long int k, int t_arr[N][M], short int* actualMatrDisp);