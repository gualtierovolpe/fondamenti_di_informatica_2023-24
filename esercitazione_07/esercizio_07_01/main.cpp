#include <iostream>

using namespace std;

const int dim = 3;

void riempi_matrice(int M[dim][dim]) {
   for (int i = 0; i < dim; i++) {
        cout << "Riga " << i + 1 << endl;
        for (int j = 0; j < dim; j++){
            cout << "Colonna " << j + 1 << ": ";
            cin >> M[i][j];
        }
   }
}

void stampa_matrice(int M[dim][dim]) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
}

void prodotto_matrici(int A[dim][dim], int B[dim][dim], int C[dim][dim]) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            C[i][j] = 0;
            for (int k = 0; k < dim; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
   int A[dim][dim] = {0}, B[dim][dim] = {0}, C[dim][dim] = {0};

   // Acquisizione dell'input
   cout << "Inserire gli elementi della matrice A" << endl;
   riempi_matrice(A);
   cout << endl << "La prima matrice e': " << endl;
   stampa_matrice(A);

   cout << endl << "Inserire gli elementi della matrice B" << endl;
   riempi_matrice(B);
   cout << endl << "La seconda matrice e': " << endl;
   stampa_matrice(B);

   // Calcolo del prodotto
   prodotto_matrici(A, B, C);

   // Visualizzazione del risultato
   cout << endl << "La matrice prodotto e': " << endl;
   stampa_matrice(C);

   return 0;
}

