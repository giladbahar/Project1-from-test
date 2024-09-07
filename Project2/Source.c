#include <stdio.h>
#include <stdlib.h>

int** allocMatrix(int rows, int cols);
void printarr(int* arr, int size);
void inputDynamicMatrix(int** matrix, int rows, int cols);
void printDynamicMatrix(int** A, int rows, int cols);
void sortedRowsCols(int** ar, int m, int n,
    int** ar_s_rows, int* num_s_rows, int** ar_s_cols, int* num_s_cols);
int arrSorted(int* a, int n);
void main()
{
    int** arr = allocMatrix(5,4);
    inputDynamicMatrix(arr, 5, 4);
    int* ar_s_rows, * ar_s_cols;
    int num_s_rows, num_s_cols;
    sortedRowsCols(arr, 5, 4, &ar_s_rows, &num_s_rows, &ar_s_cols, &num_s_cols);
    printarr(ar_s_rows, num_s_rows);
    printf("\n\n");
    printarr(ar_s_cols, num_s_cols);

}

int arrSorted(int* a, int n)
{
    int i;
    for (i = 1; i < n; i++)
    {
        if (a[i - 1] >= a[i])
            return 0;
    }
    return 1;
}

int columnSorted(int** arr, int m, int col)
{
    int i;
    for (i = 1; i < m; i++)
    {
        if (arr[i - 1][col] <= arr[i][col])
            return 0;
    }
    return 1;
}

void sortedRowsCols(int** ar, int m, int n, int** ar_s_rows, int* num_s_rows, int** ar_s_cols, int*
    num_s_cols)
{
    int i, j;
    *num_s_rows = *num_s_cols = 0;
    *ar_s_rows = (int*)calloc(m, sizeof(int)); // max size - number of rows 
    *ar_s_cols = (int*)calloc(n, sizeof(int)); // max size - number of columns 
    for (i = 0; i < m; i++)
        if (arrSorted(ar[i], n))
            (*ar_s_rows)[(*num_s_rows)++] = i;
    for (j = 0; j < n; j++)
        if (columnSorted(ar, m, j))
            (*ar_s_cols)[(*num_s_cols)++] = j;
    *ar_s_rows = (int*)realloc(*ar_s_rows, *num_s_rows * sizeof(int));
    *ar_s_cols = (int*)realloc(*ar_s_cols, *num_s_cols * sizeof(int));
}
void printDynamicMatrix(int** A, int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}
void inputDynamicMatrix(int** matrix, int rows, int cols)
{
    printf("\nEnter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Element [%d][%d]: ", i, j);
            scanf_s("%d", &matrix[i][j]);
        }
    }
}

void printarr(int* arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d,", arr[i]);
    }
}

int** allocMatrix(int rows, int cols)
{
    int** matrixB = NULL, i;
    matrixB = (int**)calloc(rows, sizeof(int*));
    if (!matrixB) return NULL;

    for (i = 0; i < rows; i++)
    {
        matrixB[i] = (int*)calloc(cols, sizeof(int));
        if (!matrixB) return NULL;
    }
    return matrixB;
}
