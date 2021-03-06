#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void multiply(int** matrix1, int** matrix2, int matrix1_rows, int matrix2_rows, int matrix1_columns, int matrix2_columns);
// close file
int main(int argc, char** argv){
FILE* file = fopen(argv[1],"r");

int matrix1_rows, matrix1_columns;
int matrix2_rows, matrix2_columns;
int** matrix1;
int** matrix2;
fscanf(file, "%d", &matrix1_rows);
fscanf(file, "%d", &matrix1_columns);

matrix1 = (int**) malloc(sizeof(int*) * matrix1_rows);
int i = 0;

/*for(i = 0; i < matrix1_rows; i++){
matrix1[i] = (int*) malloc(sizeof(int) * matrix1_columns);
}*/
int j;
int matrix1_enteries;
for(i = 0; i < matrix1_rows; i++){
matrix1[i] = (int*) malloc(sizeof(int) * matrix1_columns);
for(j = 0; j < matrix1_columns; j++){
fscanf(file,"%d",&matrix1_enteries);
matrix1[i][j] = matrix1_enteries;
}
}
fscanf(file,"%d", &matrix2_rows);
fscanf(file,"%d", &matrix2_columns);

matrix2 = (int**) malloc(sizeof(int*) * matrix2_rows);
int x, y, matrix2_enteries;
/*for (x = 0; x < matrix2_rows; x++){
matrix2[x] = (int*) malloc(sizeof(int) * matrix2_columns);

}*/
for (x = 0; x < matrix2_rows; x++){
matrix2[x] = (int*) malloc(sizeof(int) * matrix2_columns);
for(y = 0; y < matrix2_columns; y++){
fscanf(file, "%d", &matrix2_enteries);
matrix2[x][y] = matrix2_enteries;
}
}
/*int k,l;
for(k = 0; k < matrix2_rows; k++){
for(l = 0; l < matrix2_columns; l++){
printf("%d", matrix2[k][l]);
}
}*/
if(matrix1_columns != matrix2_rows)
printf("bad-matrices");
else{
multiply(matrix1, matrix2, matrix1_rows, matrix2_rows, matrix1_columns, matrix2_columns);
}
}

void multiply(int** matrix1, int** matrix2, int matrix1_rows, int matrix2_rows, int matrix1_columns, int matrix2_columns){

int product = 0,x,i,k,p,v;
int **matrix_product = (int**) malloc(sizeof(int*)*matrix1_rows);


for(i = 0; i < matrix1_rows; i++){
matrix_product[i] = (int*) malloc(sizeof(int) * matrix2_columns);
for(k = 0; k < matrix2_columns; k++){
for(x = 0; x < matrix2_rows; x++){
product += matrix1[i][x] * matrix2[x][k];
}
matrix_product[i][k]= product;
product = 0;
}
}
//printing

for(p = 0; p <matrix1_rows; p++){
for(v = 0; v <matrix2_columns; v++){
printf("%d\t", matrix_product[p][v]);
}
printf("\n");
}
}

