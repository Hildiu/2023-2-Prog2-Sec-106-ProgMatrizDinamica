#include <iostream>
#include <iomanip>
using namespace std;

void llenarDatos( int **pM, int filas, int col);
void imprimirMatriz(int **pMatriz, int filas, int col);
int hallarElMenor(int **pMat, int filas, int col);
int sumaDeDiagonal(int **pMat, int filas, int col);

int main()
{
    srand(time(nullptr));

    int * *pMat = new int*[8];
    for(int i=0; i<8; i++)
        pMat[i] = new int[8];

    llenarDatos(pMat, 8, 8);
    imprimirMatriz(pMat, 8, 8);
    cout << "\nEl dato mas chico es: " << hallarElMenor(pMat,8,8) <<"\n";
    cout<<"\nLa suma de los elementos de la diagonal principal es: " << sumaDeDiagonal(pMat,8,8);
    return 0;
}

int sumaDeDiagonal(int **pMat, int filas, int col)
{
  int suma=0;
  for(int i=0; i<filas; i++)
      suma = suma + pMat[i][i];
  return suma;
}


int hallarElMenor(int **pMat, int filas, int col)
{
    int menor = pMat[0][0];
    for(int cf=0; cf<filas; cf++)
        for(int cc=0; cc<col; cc++)
            if(pMat[cf][cc]<menor)
                menor = pMat[cf][cc];
    return menor;

}

void imprimirMatriz(int **pMatriz, int filas, int col)
{
    cout << "\n";
    for(int f=0; f<filas; f++)
    {
        for(int c=0; c<col; c++)
            cout << setw(6) << pMatriz[f][c];
        cout << "\n";
    }
}


void llenarDatos( int **pM, int filas, int col)
{
    for(int cf=0; cf<filas; cf++)
        for(int cc=0; cc<col; cc++)
            pM[cf][cc] = rand() % 99 + 1;
}
