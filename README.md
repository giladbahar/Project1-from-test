
# Sorting Rows and Columns in a 2D Array

## General Description

This project implements a function named `sortedRowsCols`, which takes a dynamic 2D array of integers with dimensions \(m\) rows and \(n\) columns. The function creates two 1D arrays: one containing the rows sorted in strictly ascending order, and the other containing the columns sorted in strictly descending order.

### Function Signature

```cpp
void sortedRowsCols(int **ar, int m, int n,
                    int **ar_s_rows, int *num_s_rows, 
                    int **ar_s_cols, int *num_s_cols);
```

### Function Details

- **ar**: A 2D array of integers.
- **ar_s_rows**: A 1D array that will hold the rows sorted in strictly ascending order.
- **num_s_rows**: A variable that will hold the size of the sorted rows array.
- **ar_s_cols**: A 1D array that will hold the columns sorted in strictly descending order.
- **num_s_cols**: A variable that will hold the size of the sorted columns array.

The function updates the new arrays by reference and returns them. If the array is empty, the function will set the size of the arrays to 0.

### Helper Functions

- **arrSorted**: A function that checks if a row in the array is sorted in strictly ascending order.
  
  ```cpp
  int arrSorted(int *a, int n);
  ```

- **columnSorted**: A function that checks if a column in the array is sorted in strictly descending order.
  
  ```cpp
  int columnSorted(int **ar, int m, int col);
  ```

### Example

Given the following array:
```
10 13 56 99
23 57 59 93
36 15 78 89
25 73 84 85
```

The function will return the rows sorted in ascending order and the columns sorted in descending order.
