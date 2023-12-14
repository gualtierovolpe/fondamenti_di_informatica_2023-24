#include <iostream>
#include <fstream>

using namespace std;

int main() {

    // Dichiarazione dello stream
    fstream fin;

    // Associazione del file allo stream
    fin.open("dati.txt", ios::in);
    if (!fin) {
        cout << "Attenzione: non e' stato possibile aprire il file dati.txt" << endl;
        return -1;
    }

    // Elaborazione del file
    char codice[16] = "";
    int n_membri = 0;
    fin >> codice >> n_membri;
    while (!fin.eof()) {

        // Lettura delle eta'
        int valore = 0, somma = 0;
        for (int i = 1; i <= n_membri; i++) {
            fin >> valore;
            somma += valore;
        }

        // Calcolo dell'eta' media (secondo il testo, si suppone n_membri > 0)
        double media = double(somma) / n_membri;

        // Visualizzazione del risultato
        cout << "Gruppo: " << codice << ", età media: " << media << endl;

        // Lettura della riga successiva
        fin >> codice >> n_membri;
    }

    // Chiusura del file
    fin.close();

    return 0;
}
