#include <iostream>

using namespace std;

struct punto2d {
    double x;
    double y;
};

struct circonferenza {
    double a;
    double b;
    double c;
};

punto2d elabora(circonferenza cfr) {
    punto2d c;
    c.x = -cfr.a/2;
    c.y = -cfr.b/2;
    return c;
}

int main() {
    circonferenza cfr;
    char continua = ' ';

    do {
        // Acquisizione dell'input
        cout << "Calcolo del centro di una circonferenza" << endl;
        cout << "Inserire il coefficiente a: ";
        cin >> cfr.a;
        cout << "Inserire il coefficiente b: ";
        cin >> cfr.b;
        cout << "Inserire il coefficiente c: ";
        cin >> cfr.c;

        // Chiamata della funzione elabora
        punto2d p = elabora(cfr);

        // Visualizzazione del risultato
        cout << "Il centro e' (" << p.x << "," << p.y << ")." << endl;

        do {
            cout << "Vuoi continuare (s/n)? ";
            cin >> continua;
            if ((continua != 's') && (continua != 'n'))
                    cout << "Attenzione: inserire s per continuare, n per uscire" << endl;
        } while ((continua != 's') && (continua != 'n'));

    } while (continua == 's');

	return 0;
}
