#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

class Magazin {
public:
	char* denumire;
	int nrProduse;
	int* coduri;//retine codurile produselor ( se respecta unicitatea)

public:
	//constructor fara param
	 
	Magazin() {
		denumire = nullptr;
		nrProduse = 0;
		coduri = nullptr;
	}
	 
	//constructor cu denumire
	 
	Magazin(const char* denumire) {
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
	 }
	 
	//constructor care primeste toti param dar valideaza unicitatea elem din vector (va elimina dublurile)
	
	Magazin(const char* denumire, const int nrProduse, const int* coduri) {
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);

		this->nrProduse = nrProduse;

		int frecv[80000] = { 0 };
		for (int i = 0; i < this->nrProduse; i++)
			frecv[coduri[i]]=1;

		int cnt = 0;
		for (int i = 0; i < 80000; i++)
			if (frecv[i] == 1)
				cnt++;

		this->nrProduse = cnt;
		this->coduri = new int[cnt];

		int index = 0;
			for(int j=0;j<80000;j++)
				if (frecv[j] == 1)
				{
					this->coduri[index] = j;
					index++;
				}

		
	 }
	
	//metoda care adauga un nou cod in vectorul coduri

	void AdaugaCod(int cod_nou) {
		int* aux = new int[this->nrProduse + 1];

		for (int i = 0; i < this->nrProduse; i++)
			aux[i] = this->coduri[i];

		aux[nrProduse] = cod_nou;

		delete[] coduri;

		this->nrProduse = this->nrProduse + 1;
		this->coduri = new int[nrProduse];

		for (int i = 0; i < this->nrProduse; i++)
			this->coduri[i] = aux[i];
	}
};

int main() {
	// vector cu dubluri
	int coduri1[] = { 101, 202, 303, 101, 404, 202, 505 };
	int nr1 = 7;

	cout << "===== TEST CONSTRUCTOR COMPLET =====\n";
	Magazin m1("MegaImage", nr1, coduri1);

	cout << "Codurile dupa eliminarea dublurilor:\n";
	for (int i = 0; i < m1.nrProduse; i++)  // ⚠️ dacă nrProduse e private, adaugă un getter
		cout << m1.coduri[i] << " ";
	cout << "\n\n";

	cout << "===== TEST AdaugaCod() =====\n";
	m1.AdaugaCod(606);
	m1.AdaugaCod(707);

	cout << "Codurile dupa adaugarea unor coduri noi:\n";
	for (int i = 0; i < m1.nrProduse; i++)
		cout << m1.coduri[i] << " ";
	cout << "\n\n";

	cout << "===== TEST CONSTRUCTOR CU DENUMIRE =====\n";
	Magazin m2("Carrefour");
	cout << m2.denumire << endl;
	cout << "===== TEST CONSTRUCTOR FARA PARAM =====\n";
	Magazin m3;

	cout << "===== SFARSIT TESTE =====\n";
	return 0;
}



