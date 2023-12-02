#include <iostream>

using namespace std;

int main() {
    char c = 's';
    const int dim = 12;
    int a[dim];
    int b[dim];

    do {
        // Acquisizione dell'input
        cout << "Inserire i 12 elementi di un array" << endl;
        for (int i = 0; i < dim; i++) {
            cout << "Elemento " << i + 1 << ": ";
            cin >> a[i];
        }

        // Elaborazione dell'array
        b[0] = 1;
        for (int k = dim - 1; k > 0; k--)
            b[k] = a[k - 1] * a[k + 1];
        b[dim - 1] = 1;

        // Visualizzazione dell'output
        cout << "Array elaborato: [";
            for (int j = 0; j < dim - 1; j++)
                cout << b[j] << ", ";
        cout << b[dim - 1] << "]" << endl;

        do {
            cout << "Vuoi continuare (s/n)? ";
            cin >> c;
            if (c != 's' && c != 'n')
                cout << "Attenzione: Inserire s o n" << endl;
        } while (c != 's' && c != 'n');

    } while (c != 'n');

    return 0;
}
