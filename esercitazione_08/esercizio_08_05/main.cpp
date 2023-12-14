#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    const int dim = 16;
    char nome_file[dim] = "";
    int contatore = 0;
    int termina = 0;
    fstream fin;

    while(1) {
        int aperto;
        do {
            // Acquisizione dell'input
            cout << "Inserire il nome di un file o exit per terminare" << endl;
            cin.getline(nome_file, dim, '\n');

            // Verifica per la terminazione del programma
            if (strcmp(nome_file, "exit") == 0) {
                termina = 1;
            }
            else {
                // Verifica del nome del file e apertura del file
                aperto = 1;
                fin.open(nome_file, ios::in);
                if (!fin) {
                    aperto = 0;
                    cout << "Attenzione: il file inserito non esiste" << endl;
                }
            }
        } while (aperto == 0 && termina == 0);

        if (termina == 1)
            break;

        // Elaborazione del file
        double temperatura = 0.0;
        fin >> temperatura;
        double minimo = temperatura, massimo = temperatura;
        int file_vuoto = 1;
        while (!fin.eof()) {
            file_vuoto = 0;
            fin >> temperatura;
            if (temperatura < minimo)
                minimo = temperatura;
            if (temperatura > massimo)
                massimo = temperatura;
        }

        // Chiusura del file
        fin.close();

        // Visualizzazione dell'output
        if (file_vuoto)
            cout << endl << "Attenzione: il file e' vuoto" << endl << endl;
        else {
            contatore++;
            cout << endl << "File: " << nome_file << endl;
            cout << "Temperatura minima: " << minimo << "C" << endl;
            cout << "Temperatura massima: " << massimo << "C" << endl << endl;
        }
    }

    cout << endl << "Numero di file non vuoti elaborati: " << contatore << endl;
    return 0;
}
