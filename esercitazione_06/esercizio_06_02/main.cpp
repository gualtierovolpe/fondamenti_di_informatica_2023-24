#include <iostream>
#include <cstring>

using namespace std;

int conta_rima(char s1[], char s2[]) {
    int len1 = 0, len2 = 0, len = 0;
    int contarima = 0;

    // Calcolo della lunghezza minima tra le lunghezze delle due stringhe
    len1 = strlen(s1);
    len2 = strlen(s2);
    if (len1 < len2)
        len = len1;
    else
        len = len2;

    // Calcolo del numero di lettere in rima
    for (int i = 1; i <= len; i++){
        if (s1[len1 - i] == s2[len2 - i])
            contarima++;
        else
            break;
    }

    return contarima;
}

int main() {
    const int dim = 256;
    char stringa1[dim], stringa2[dim];

    // Lettura delle stringhe da tastiera
    cout << "Inserire due stringhe di caratteri" << endl;
    cout << "Prima stringa: ";
    cin.getline(stringa1, dim, '\n');
    cout << "Seconda stringa: ";
    cin.getline(stringa2, dim, '\n');

    // Chiamata della funzione conta_rima
    int n = conta_rima(stringa1, stringa2);

    // Stampa a video del risultato
    cout << "Il nuimero di lettere che fanno rima e': " << n << endl;

    return 0;
}
