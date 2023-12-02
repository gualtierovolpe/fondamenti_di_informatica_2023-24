#include <iostream>
#include <cstring>

using namespace std;

void inverti(char s[]) {
    int lunghezza = strlen(s);
    int i = 0; int j = lunghezza - 1;
    while (i < j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
}

int main() {
    const int dim = 32;
    char str[dim] = "";

    // Acquisizione dell'input
    cout << "Inserire una stringa di caratteri: ";
    cin.getline(str, dim, '\n');

    // Chiamata della funzione
    inverti(str);

    // Visualizzazione dell'output
    cout << "Stringa invertita: " << str;

    return 0;
}
