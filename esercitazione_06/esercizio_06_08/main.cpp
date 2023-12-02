#include <iostream>

using namespace std;

const int dim_arr = 4;
const int dim_str = 16;

int strToIP(char s[], int ip[dim_arr]) {

    // Inizializziamo l'array a zero
    for (int i = 0; i < dim_arr; i++)
        ip[i] = 0;

    int k = 0; int i = 0; int num = 0;
    while (s[k] != '\0') {

        // E' terminata la lettura di un numero, quindi se e' valido lo inseriamo nell'array
        if (s[k] == '.') {
            if (num > 255)
                return -1;
            ip[i] = num;
            i++;
            num = 0;
        }

        // Stiamo leggendo un numero, quindi effettuiamo la conversione da carattere a cifra
        // e ricostruiamo il numero
        else {
            num = num * 10 + (s[k] - '0');
        }

        k++;
    }

    // Terminata la lettura della stringa, resta da verificare e inserire nell'arrray l'ultimo numero
    if (num > 255)
        return -1;
    ip[i] = num;

    return 1;
}

int main() {
    int address[dim_arr];
    char str[dim_str];
    char c = 'n';

    do {
        // Acquisizione dell'input
        cout << "Inserire un indirizzo IP: ";
        cin >> str;

        // Chiamata della funzione
        int risultato = strToIP(str, address);

        // Visualizzazione dell'output
        if (risultato == 1) {
            cout << "address = {";
            for (int i = 0; i < dim_arr - 1; i++)
               cout << address[i] << ", ";
            cout << address[dim_arr - 1] << '}' << endl;
        }
        else
            cout << "Stringa non valida" << endl;

        do {
            cout << "Vuoi continuare (s/n)? ";
            cin >> c;
            if (c != 's' && c != 'n')
                cout << "Attenzione: Inserire s o n" << endl;
        } while (c != 's' && c != 'n');

    } while (c == 's');

    return 0;
}
