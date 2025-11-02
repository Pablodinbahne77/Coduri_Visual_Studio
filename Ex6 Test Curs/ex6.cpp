#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Masina {public:
	string numarMasina;
	double capacitateRezervor;
	double capacitateCurenta;
	int nrAlimentari;
	double* alimentari;


	//constructor cu un singur parametru (string)
	
	Masina(const string numarMasina) {
		this->numarMasina = numarMasina;
	 }
	 
	//constructor cu parametri (numarMasina, capacitate rezervor)
	 
	Masina(const string numarMasina, const double capacitateRezervor) {
		this->numarMasina = numarMasina;
		this->capacitateRezervor = capacitateRezervor;
	 }
	 
	//constructor cu toti parametri (se vor adauga restrictii la nivelul vectorului de alimentari, daca se depaseste pentru 
	//o alimentare capacitatea rezervorului, atunci aceasta se va inlocui cu capacitatea maxima a rezervorului)
	 
	Masina(const string numarMasina, const double capacitateRezervor, const double capacitateCurenta, const int nrAlimentari, double* alimentari) {
		this->numarMasina = numarMasina;
		this->capacitateRezervor = capacitateRezervor;
		this->capacitateCurenta = capacitateCurenta;
		this->nrAlimentari = nrAlimentari;

		this->alimentari = new double[this->nrAlimentari];
		for (int i = 0; i < nrAlimentari; i++)
		{
			if (alimentari[i] + this->capacitateCurenta > this->capacitateRezervor)
				alimentari[i] = this->capacitateRezervor;

			this->alimentari[i] = alimentari[i];
		}
	}

	//setter numar masina

	void setNumarMasina (const string numarMasina) {
		if (this->numarMasina != "")
			this->numarMasina = "";

		this->numarMasina = numarMasina;
	}

	//metoda care adauga o noua alimentare tinand cont de restrictiile (capacitate curenta si capacitate rezervor)
	 
	void AdaugaAlimentare(double alim_noua) {
		double* aux = new double[nrAlimentari + 1];

		for (int i = 0; i < nrAlimentari; i++)
		{
			aux[i] = this->alimentari[i];
		}

		if (alim_noua + this->capacitateCurenta > capacitateRezervor)
			alim_noua = capacitateRezervor;

		aux[this->nrAlimentari] = alim_noua;

		delete[] this->alimentari;
		this->nrAlimentari++;

		this->alimentari = new double[nrAlimentari];

		for (int i = 0; i < this->nrAlimentari; i++)
			this->alimentari[i] = aux[i];
	 }
	 
	//metoda de afisare dar care afiseaza in loc de vectorul de alimentari doar media tuturor alimentarilor
	void Afisare() {
		cout << "Numar masina: " << numarMasina << endl;
		cout << "Capacitate rezervor: " << capacitateRezervor << endl;
		cout << "Capacitate curenta: " << capacitateCurenta << endl;
		cout << "Numar alimentari: " << nrAlimentari << endl;

		double s = 0;
		for (int i = 0; i < this->nrAlimentari; i++)
			s += this->alimentari[i];

		double medie = s * 1.0 / this->nrAlimentari;

		cout << "Medie alimentari: " << medie;
	}

};

int main() {

	double alim[] = { 15.5, 5, 13 };
	Masina m1("VN94MAG", 50, 20, 3, alim);

	

	m1.AdaugaAlimentare(7);
	for (int i = 0; i < m1.nrAlimentari; i++)
		cout << m1.alimentari[i]<<" ";
	cout << endl;

	m1.Afisare();
	cout << endl;
	m1.setNumarMasina("VN77DD");

	cout << m1.numarMasina << endl;
}