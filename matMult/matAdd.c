#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void matadd (int **C, int **A, int **B, int height, int width) {
   for (int i = 0; i < height; ++i) {
      for (int j = 0; j < width; ++j) {
         for (int k = 0; k < width; ++k) {
            C[i][j] += A[i][k] * B[k][j];
         }
      }
   }
}

void printMatrix(int **C, int height, int width) {

   for (int i = 0; i < height; ++i) {
      for (int j = 0; j < width; ++j) {
         printf("%d  ", C[i][j]);
         if (j == width - 1)
            printf("\n");
      }
   }
}

int main() {
    int **A;
    int **B;
    int **C;

    int height = 250;
    int width = 250;

    A = (int**)malloc(sizeof(int*)*height);
    B = (int**)malloc(sizeof(int*)*height);
    C = (int**)malloc(sizeof(int*)*height);

    for(int i = 0; i < width; i++) {
        A[i] = malloc(sizeof(int)*width);
        B[i] = malloc(sizeof(int)*width);
        C[i] = malloc(sizeof(int)*width);
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            A[i][j] = rand() % 2;
            B[i][j] = rand() % 2;
        }
    }

    matadd(C, A, B, height, width); 
    printMatrix(C, height, width);
}
