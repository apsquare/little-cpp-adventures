#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 100
// Structure to represent a single non-zero element triplet
typedef struct {
    int row;
    int col;
    int val;
} Element;
// Structure to represent the complete Sparse Matrix in Triplet Form

typedef struct {
    int rows;
    int cols;
    int total_values;
    Element data[MAX_ELEMENTS];
} SparseMatrix;

// Function Prototypes
void readMatrix(SparseMatrix *matrix);
void printTriplet(const SparseMatrix *matrix);
void printNormalMatrix(const SparseMatrix *matrix);
SparseMatrix transpose(const SparseMatrix *matrix);
SparseMatrix add(const SparseMatrix *m1, const SparseMatrix *m2);

int main() {
    SparseMatrix m1, m2, m1_transposed, m_added;
    int choice;

    printf("--- Sparse Matrix Processing System ---\n");
    printf("\nReading Matrix 1:\n");
    readMatrix(&m1);

    while (1) {
        printf("\n=================================");
        printf("\nSparse Matrix Operations Menu:");
        printf("\n1. Display Matrices (Triplet and Normal Form)");
        printf("\n2. Compute Transpose of Matrix 1");
        printf("\n3. Add Matrix 1 and Matrix 2");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n--- Matrix 1 (Triplet Format) ---\n");
                printTriplet(&m1);
                printf("\n--- Matrix 1 (Standard Grid Format) ---\n");
                printNormalMatrix(&m1);
                break;

            case 2:
                m1_transposed = transpose(&m1);
                printf("\n--- Transposed Matrix 1 (Triplet Format) ---\n");
                printTriplet(&m1_transposed);
                printf("\n--- Transposed Matrix 1 (Standard Grid Format) ---\n");
                printNormalMatrix(&m1_transposed);
                break;

            case 3:
                printf("\nReading Matrix 2 (Must have same dimensions %dx%d):\n", m1.rows, m1.cols);
                readMatrix(&m2);
                
                if (m1.rows != m2.rows || m1.cols != m2.cols) {
                    printf("\nError: Addition impossible! Matrix dimensions must match.\n");
                } else {
                    m_added = add(&m1, &m2);
                    printf("\n--- Result of Addition (Triplet Format) ---\n");
                    printTriplet(&m_added);
                    printf("\n--- Result of Addition (Standard Grid Format) ---\n");
                    printNormalMatrix(&m_added);
                }
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please select a valid operation.\n");
        }
    }
    return 0;
}
// Reads standard matrix inputs and converts them to triplet form on-the-fly

void readMatrix(SparseMatrix *matrix) {
    int element;
    matrix->total_values = 0;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &matrix->rows, &matrix->cols);

    printf("Enter matrix elements row by row:\n");
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            scanf("%d", &element);
            if (element != 0) {
                if (matrix->total_values >= MAX_ELEMENTS) {
                    printf("Matrix exceeds maximum storage limit!\n");
                    return;
                }
                matrix->data[matrix->total_values].row = i;
                matrix->data[matrix->total_values].col = j;
                matrix->data[matrix->total_values].val = element;
                matrix->total_values++;
            }
        }
    }
}
// Prints the compact sparse triplet form

void printTriplet(const SparseMatrix *matrix) {
    if (matrix->total_values == 0) {
        printf("Matrix is completely empty (all zeros).\n");
        return;
    }
    printf("%-6s %-6s %-6s\n", "Row", "Col", "Value");
    printf("------------------\n");
    for (int i = 0; i < matrix->total_values; i++) {
        printf("%-6d %-6d %-6d\n", matrix->data[i].row, matrix->data[i].col, matrix->data[i].val);
    }
}
// Reconstructs and prints the standard grid matrix format from the compact structure

void printNormalMatrix(const SparseMatrix *matrix) {
    int k = 0;
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            if (k < matrix->total_values && matrix->data[k].row == i && matrix->data[k].col == j) {
                printf("%d\t", matrix->data[k].val);
                k++;
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }
}
// Performs transpose of a triplet sparse matrix using systematic counting

SparseMatrix transpose(const SparseMatrix *matrix) {
    SparseMatrix result;
    result.rows = matrix->cols;
    result.cols = matrix->rows;
    result.total_values = matrix->total_values;

    if (matrix->total_values <= 0) return result;

    int current_result_index = 0;
    
    // Scan by columns to keep the transposed matrix rows sorted
    for (int c = 0; c < matrix->cols; c++) {
        for (int i = 0; i < matrix->total_values; i++) {
            if (matrix->data[i].col == c) {
                result.data[current_result_index].row = matrix->data[i].col;
                result.data[current_result_index].col = matrix->data[i].row;
                result.data[current_result_index].val = matrix->data[i].val;
                current_result_index++;
            }
        }
    }
    return result;
}
// Adds two sparse triplet matrices efficiently using a two-pointer merge approach

SparseMatrix add(const SparseMatrix *m1, const SparseMatrix *m2) {
    SparseMatrix result;
    result.rows = m1->rows;
    result.cols = m1->cols;
    
    int i = 0, j = 0, k = 0;

    while (i < m1->total_values && j < m2->total_values) {
        // Condition A: Matrix 1 element row is smaller, or rows match but M1 column is smaller
        if (m1->data[i].row < m2->data[j].row || 
           (m1->data[i].row == m2->data[j].row && m1->data[i].col < m2->data[j].col)) {
            result.data[k++] = m1->data[i++];
        }
        // Condition B: Matrix 2 element row is smaller, or rows match but M2 column is smaller
        else if (m2->data[j].row < m1->data[i].row || 
                (m2->data[j].row == m1->data[i].row && m2->data[j].col < m1->data[i].col)) {
            result.data[k++] = m2->data[j++];
        }
        // Condition C: Elements overlap at the exact same row and column
        else {
            int sum = m1->data[i].val + m2->data[j].val;
            if (sum != 0) { // Only store non-zero sums
                result.data[k].row = m1->data[i].row;
                result.data[k].col = m1->data[i].col;
                result.data[k].val = sum;
                k++;
            }
            i++;
            j++;
        }
    }

    // Append remaining elements from Matrix 1
    while (i < m1->total_values) {
        result.data[k++] = m1->data[i++];
    }

    // Append remaining elements from Matrix 2
    while (j < m2->total_values) {
        result.data[k++] = m2->data[j++];
    }

    result.total_values = k;
    return result;
}



