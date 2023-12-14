#include <fstream>
#include <iostream>

using namespace std;

int main() {

    // Dichiarazione degli stream
    fstream fin, fout;

    // Apertura dei file
    fin.open("input.txt", ios::in);
    if (!fin) {
        cout << "Attenzione: non e' stato possibile aprire il file input.txt" << endl;
        return -1;
    }
    fout.open("output.txt", ios::out);

    // Elaborazione del file
    char c = ' ';
    int contaoccorrenze['z' - 'a' + 1] = {0};
    fin >> c;
    while (!fin.eof()) {
        // Se c e' una lettera minuscola
        if ((c >= 'a') && (c <= 'z')) {
            int posizione = c - 'a';        //individuo il numero progressivo della lettera nell'alfabeto
            contaoccorrenze[posizione]++;   //conto uno in piu' per quella lettera
        }

        // Se c e' una lettera maiuscola faccio la stessa cosa
        if ((c >= 'A') && (c <= 'Z'))  {
            int posizione = c-'A';
            contaoccorrenze[posizione]++;
        }

        // Leggo il carattere successivo
        fin >> c;
    }

    // Chiusura del file in ingresso
    fin.close();

    // Stampa dell'output nel file in uscita
    for (int i = 0; i < 26; i++) {
        c = 'a' + i;
        fout << c << ": " << contaoccorrenze[i] << endl;
    }

    // Chiusura del file in uscita
    fout.close();

    cout << "Elaborazione completata" << endl;

    return 0;
}
