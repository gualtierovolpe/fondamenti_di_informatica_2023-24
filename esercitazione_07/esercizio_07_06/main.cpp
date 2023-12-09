#include <iostream>

using namespace std;

const int nr1 = 4;
const int nr2 = 2;
const int nc = 3;

void riempi_matrice(double M[nr1][nc]) {
   for (int i = 0; i < nr1; i++) {
        cout << "Riga " << i + 1 << endl;
        for (int j = 0; j < nc; j++){
            cout << "Colonna " << j + 1 << ": ";
            cin >> M[i][j];
        }
   }
}

int main() {
    double M[nr1][nc] = {0};
    double X[nr2][nc] = {0};
    double Y[nr2][nc] = {0};

    // Acquisizione dell'input
    cout << "Inserire gli elementi di una matrice 4x3" << endl;
    riempi_matrice(M);

    // Elaborazione: matrice X
    double somma_x = 0.0;
    for (int i = 0; i < nr1; i+=2)
        for (int j = 0; j < nc; j++) {
            X[i / 2][j] = M[i][j];
            somma_x += X[i / 2][j];
        }

    // Elaborazione: matrice Y
    double somma_y = 0.0;
    for (int m = 1; m < nr1; m += 2)
        for (int n = 0; n < nc; n++) {
            Y[m / 2][n] = M[m][n];
            somma_y += Y[m / 2][n];
    }

    // Visualizzazione del risultato
    cout << endl;
    cout << "Somma degli elementi della matrice X: " << somma_x << endl;
    cout << "Somma degli elementi della matrice Y: " << somma_y << endl;

    return 0;
}

