#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    // Definizione dell'array
    const int dim = 30;
    int arr[dim] = {0};

    // Inizializzazione con numeri casuali tra 0 e 199
    srand(time(NULL));
    for (int i = 0; i < dim; i++){
        arr[i] = rand() % 100;
    }

    // Stampa dell'array
    cout << "Ecco l'array inizializzato con numeri casuali:" << endl << "[";
    for (int j = 0; j < dim - 1; j++){
        cout << arr[j] << ", ";
    }
    cout << arr[dim - 1] << "]" << endl;

    return 0;
}
