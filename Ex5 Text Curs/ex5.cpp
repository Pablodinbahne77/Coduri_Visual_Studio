#include<iostream>
using namespace std;

enum TipContact { familie, prieten, serviciu, altele };

class AgendaTelefon {
	string posesor;
	int nrContacte;
	string* numeContacte;
	//alt atribut de tip enum si bool la alegere
	TipContact tip;
	bool* favorit;
public:
	//constructor fara parametri
	 
	AgendaTelefon() {
		posesor = "";
		nrContacte = 0;
		numeContacte = nullptr;
		tip = altele;
		favorit = nullptr;

	 }
	 
	//constructor cu un singur parametru
	
	AgendaTelefon(string posesor) {
		this->posesor = posesor;
	 }
	 
	//metoda care adauga un nou contact in lista de contacte (numele nu trebuie sa se mai regaseasca)
	 
	void AdaugaContact(string contact_nou, bool favorit_nou) {
		string* aux = new string[this->nrContacte + 1];
		bool* auxfav = new bool[this->nrContacte + 1];
		for (int i = 0; i < this->nrContacte; i++)
		{
			aux[i] = this->numeContacte[i];
			auxfav[i] = this->favorit[i];
		}
		aux[this->nrContacte] = contact_nou;
		auxfav[this->nrContacte] = favorit_nou;
		delete[] this->numeContacte;
		delete[] this->favorit;

		this->nrContacte++;

		this->numeContacte = new string[this->nrContacte];
		this->favorit = new bool[this->nrContacte];
		for (int i = 0; i < this->nrContacte; i++)
		{
			this->numeContacte[i] = aux[i];
			this->favorit[i] = auxfav[i];
		}
	 }
	
	//metoda de afisare

	void Afisare() {
		cout << "Posesor: " << this->posesor << endl;
		cout << "Numar contacte: " << this->nrContacte << endl;
		for (int i = 0; i < this->nrContacte; i++)
			cout << this->numeContacte[i] << endl;

		cout << "Tip contact: ";
		switch (tip) {
		case prieten:
			cout << "prieten"; break;
		case serviciu:
			cout << "serviciu"; break;
		case familie:
			cout << "familie"; break;
		case altele:
			cout << "altele"; break;
		}
		cout << endl;

		cout << "Lista preferinte: ";
		for (int i = 0; i < this->nrContacte; i++)
			if (this->favorit[i] == 0)
				cout << "favorit" << " ";
			else
				cout << "normal" << " ";
		cout << endl;

	}
};

int main() {
	cout << "=== TEST CONSTRUCTOR FARA PARAM ===" << endl;
	AgendaTelefon a1;
	a1.Afisare();
	cout << endl;

	cout << "=== TEST CONSTRUCTOR CU PARAM ===" << endl;
	AgendaTelefon a2("Andrei");
	a2.Afisare();
	cout << endl;

	cout << "=== TEST ADAUGARE CONTACTE ===" << endl;
	a2.AdaugaContact("Maria Popescu", true);
	a2.AdaugaContact("Ion Ionescu", false);
	a2.AdaugaContact("Elena Georgescu", true);
	a2.Afisare();

	return 0;
}
