#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int dim_autore = 32;
const int dim_titolo = 64;

// Struttura libro
struct libro {
    int codice;
    char autore[dim_autore];
    char titolo[dim_titolo];
    int pagine;
    double prezzo;
};

int main() {
    const int dim_libreria = 100;
    libro libreria[dim_libreria];

    // Acquisizione input da file
    fstream fin;
    fin.open("libri.txt", ios::in);
    if (!fin) {
        cout << "Errore nell'apertura del file" << endl;
        return -1;
    }
    const int dim = 64;
    char temp[dim] = "";
    int i = 0;
    while(!fin.eof() && i < 100){
        fin.getline(temp, dim, ',');
        libreria[i].codice = stoi(temp);    // stoi: funzione di libreria che converte una stringa in un numero intero di tipo int
        fin.getline(libreria[i].titolo, dim, ',');
        fin.getline(libreria[i].autore, dim, ',');
        fin.getline(temp, dim, ',');
        libreria[i].pagine = stoi(temp);
        fin.getline(temp, dim, '\n');
        libreria[i].prezzo = stod(temp);    // stod: funzione di libreria che converte una stringa in un numero reale di tipo double
        i++;
    }
    fin.close();

    char richiesta[dim_titolo];
    char continua = 's';
    do {
        // Richiesta di input all'utente
        cin.sync();     // pulizia dello stream in ingresso
        cin.clear();    // pulizia dello stream in ingresso
        cout << "Di quale libro desideri avere informazioni?" << endl;
        cin.getline(richiesta, dim_titolo, '\n');

        // Ricerca del libro desiderato e visualizzazione del risultato
        int trovato = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(richiesta, libreria[j].titolo) == 0) {
                cout << "Il libro e' presente nel catalogo" << endl;
                cout << "Il suo codice e': " << libreria[j].codice << endl;
                cout << "Il suo autore e': " << libreria[j].autore << endl;
                cout << "Il libro ha " << libreria[j].pagine << " pagine" << endl;
                cout << "Il libro costa " << libreria[j].prezzo << " Euro" << endl;
                trovato = 1;
                break;
            }
        }
        if (!trovato) {
            cout << "Il libro non e' in catalogo" << endl;
        }
        cout << endl;

        // Verifica per continuazione
        do {
            cout << "Desideri continuare (s/n)? ";
            cin >> continua;
            if (continua != 's' && continua != 'n')
                cout << "Attenzione: inserire s oppure n" << endl;
        } while (continua != 's' && continua != 'n');
        cout << endl;

    } while (continua == 's');

    return 0;
}
