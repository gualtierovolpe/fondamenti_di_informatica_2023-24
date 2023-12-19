#include <iostream>
#include <cmath>

using namespace std;

struct punto2d {
    double x;
    double y;
};

struct retta {
    double a;
    double b;
    double c;
};

double distanza(punto2d p, retta r) {
    if (r.a == 0.0 && r.b == 0.0)
        return 0.0;
    double num = abs(r.a * p.x + r.b * p.y + r.c);
    double den = sqrt(r.a * r.a + r.b * r.b);
    return num / den;
}

int main() {
    punto2d pt;
    retta rt;
    char continua = ' ';

    do {
        // Acquisizione dell'input
        do {
            cout << "Calcolo della distanza punto-retta" << endl;
            cout << "Inserire il coefficiente a dell'equazione di una retta: ";
            cin >> rt.a;
            cout << "Inserire il coefficiente b dell'equazione di una retta: ";
            cin >> rt.b;
            cout << "Inserire il coefficiente c dell'equazione di una retta: ";
            cin >> rt.c;
            if (rt.a == 0.0 && rt.b == 0.0)
                    cout << "Attenzione: i coefficienti a e b non possono essere entrambi nulli" << endl;
        } while (rt.a == 0.0 && rt.b == 0.0);
        cout << "Inserire la coordinata x di un punto: ";
        cin >> pt.x;
        cout << "Inserire la coordinata y di un punto: ";
        cin >> pt.y;

        // Chiamata della funzione elabora
        double d = distanza(pt, rt);

        // Visualizzazione del risultato
        cout << "La distanza vale " << d << endl;

        do {
            cout << "Vuoi continuare (s/n)? ";
            cin >> continua;
            if ((continua != 's') && (continua != 'n'))
                    cout << "Attenzione: inserire s per continuare, n per uscire" << endl;
        } while ((continua != 's') && (continua != 'n'));

    } while (continua == 's');

	return 0;
}
