#include <iostream>

using namespace std;

int rimuovi_occorrenze(char s[], char a) {
	int contatore = 0;
	int indice = 0;
	for (int k = 0; s[k] != '\0'; k++) {
		if (s[k] != a)
			s[indice++] = s[k];
		else
			contatore++;
	}
	s[indice] = '\0';
	return contatore;
}

int main () {
	char s[] = "Ottobre";

	// Visualizzazione della stringa originale
	cout << "Stringa originale: " << s << endl;

	// Chiamata della funzione
	int n_rimossi = rimuovi_occorrenze(s, 't');

	// Visualizzazione del risultato
	cout << "Nuova stringa: " << s << endl;
	cout << "Sono state rimosse " << n_rimossi << " occorrenze." << endl;

	return 0;
}
