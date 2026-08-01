// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 10;

void readMatrix(int mat[][MAX], int &rows, int &cols) {
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
}

void printMatrix(int mat[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << setw(5) << mat[i][j];
        cout << endl;
    }
}

// Part A — Transpose
void transposeMatrix(int mat[][MAX], int rows, int cols) {
    int result[MAX][MAX] = {};
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[j][i] = mat[i][j];

    cout << "\nTransposed Matrix:" << endl;
    printMatrix(result, cols, rows);  // note: rows and cols are swapped
}

// Part B — Addition
void addMatrices(int a[][MAX], int b[][MAX], int rows, int cols) {
    int result[MAX][MAX] = {};
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = a[i][j] + b[i][j];

    cout << "\nSum Matrix:" << endl;
    printMatrix(result, rows, cols);
}

// Part C — Multiplication
void multiplyMatrices(int a[][MAX], int b[][MAX], int m, int n, int p) {
    int result[MAX][MAX] = {};
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            for (int k = 0; k < n; k++)
                result[i][j] += a[i][k] * b[k][j];

    cout << "\nProduct Matrix:" << endl;
    printMatrix(result, m, p);
}

int main() {
    int mat[MAX][MAX], rows, cols;

    // --- Part A ---
    cout << "=== Part A: Transpose ===" << endl;
    readMatrix(mat, rows, cols);
    cout << "\nOriginal Matrix:" << endl;
    printMatrix(mat, rows, cols);
    transposeMatrix(mat, rows, cols);

    cout << endl;

    // --- Part B ---
    cout << "=== Part B: Addition ===" << endl;
    int a[MAX][MAX], b[MAX][MAX], rA, cA, rB, cB;
    cout << "Matrix A:" << endl;
    readMatrix(a, rA, cA);
    cout << "Matrix B (must be " << rA << " x " << cA << "):" << endl;
    readMatrix(b, rB, cB);

    if (rA != rB || cA != cB) {
        cout << "Error: Matrices must be the same size for addition." << endl;
    } else {
        cout << "\nMatrix A:" << endl;
        printMatrix(a, rA, cA);
        cout << "\nMatrix B:" << endl;
        printMatrix(b, rB, cB);
        addMatrices(a, b, rA, cA);
    }

    cout << endl;

    // --- Part C ---
    cout << "=== Part C: Multiplication ===" << endl;
    int c[MAX][MAX], d[MAX][MAX], rC, cC, rD, cD;
    cout << "Matrix A (M x N):" << endl;
    readMatrix(c, rC, cC);
    cout << "Matrix B (must have " << cC << " rows):" << endl;
    readMatrix(d, rD, cD);

    if (cC != rD) {
        cout << "Error: Columns of A (" << cC << ") must equal rows of B (" << rD << ")." << endl;
    } else {
        cout << "\nMatrix A:" << endl;
        printMatrix(c, rC, cC);
        cout << "\nMatrix B:" << endl;
        printMatrix(d, rD, cD);
        multiplyMatrices(c, d, rC, cC, cD);
    }

    return 0;
}