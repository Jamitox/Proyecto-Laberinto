#include <stdio.h>

#define N 5
#define M 5
 int maze [N] [M] = {
     {1, 1, 0, 0, 0},
     {1, 1, 1, 0, 0},
     {0, 1, 0, 1, 0},
     {0, 1, 0, 1, 1},
     {1, 1, 1, 1, 1},
 };
 
 int sol [N][M];
 
 // Funcion para imprimir la solución
 void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", sol[i][j]);
        }
        printf("\n");
    }
}

 // Funcion para verificar si una celda es segura para moverse 
 int isSafe(int x, int y) {
     return (x >= 0 && x < N && y >= 0 && y < M && maze[x][y] == 1 && sol[x][y] == 0);
 }
 
// Funcion para resolver el laberinto usando backtracking
 int solveMazeUtil(int x, int y) {
     // Caso base: si hemos llegado a la posicion final
     if (x == N -1 && y == M -1) {
         sol[x][y] = 1;
         return 1;
     }
     
     // verificar se la celda es segura para moverse 
     if (isSafe(x, y)) {
         // Marcar la celda como parte de la solucion 
         sol[x][y] = 1;
         
         // moverse hacia delante en la direccion x
         if (solveMazeUtil(x + 1, y))
         return 1;
         
         // si moverse en la direccion x  no lleva a una solucion, intentar en la direccion y
         if (solveMazeUtil(x, y + 1))
         return 1;
         
         // si ninguna de las soluciones anteriores lleva a una solucion, macar la celda como no parte de 
         sol[x][y] = 0;
         return 0;
         
     }
     return 0;
     
 }
 
 // Funcion principl para resolver el laberinto
 void solveMaze() {
     if (solveMazeUtil(0, 0) == 0) {
         printf("No hay solucion.\n");
         return;
     }
     
     printf("solucion encontrada:\n");
     printSolution();
 }
 
 int main() {
     solveMaze();
     return 0;
 }
