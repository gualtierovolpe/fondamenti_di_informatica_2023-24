#include <iostream>

using namespace std;

const int d = 3;

void stampa_matrice(double M[d][d]) {
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
}

double traccia(double M[d][d]) {
	double somma = 0.0;
	for (int k = 0; k < d; k++) {
		somma += M[k][k];
	}
	return somma;
}

int main () {
	double A[d][d] = {1, 1, 2, 0, 2, 1, 3, 4, 3};

	cout << "La traccia della matrice" << endl << endl;
    stampa_matrice(A);
	cout << endl;
	cout << "vale " << traccia(A) << endl << endl;

	return 0;
}
