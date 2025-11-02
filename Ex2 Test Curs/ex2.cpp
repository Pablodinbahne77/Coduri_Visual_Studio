#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstring>
using namespace std;

class Produs {
	char denumire[21];
	int nrPreturi;
	double* preturi;//stocheaza istoricul preturilor Produsului
	//nu va contine 2 valori alaturate egale

public:
	//constructor fara param 
	
	Produs() {
		denumire[0] = '\0';
		nrPreturi = 0;
		preturi = nullptr;
	}
	 
	//constructor doar cu denumire
	 
	Produs(const char* denumire) {
		
		strcpy(this->denumire, denumire);
	 }
	 
	//constructor cu toti param dar care verifica proprietatea enuntata pentru vectorul de preturi
	
	Produs(const char* denumire, const int nrPreturi, const double* preturi) {
		strcpy(this->denumire, denumire);

		this->preturi = new double[nrPreturi];
		int index = 0;

		this->preturi[index++] = preturi[0];
		for (int i = 1; i < nrPreturi; i++) {
			if (preturi[i] != preturi[i - 1]) {
				this->preturi[index++] = preturi[i];
			}
		}

		this->nrPreturi = index; // actualizează numărul real de prețuri
	}

	 
	//metoda care primeste un nou pret si il adauga la sf de vector daca respecta conditia
	
	void Pret_Nou(double pret_nou) {
		double* aux = new double[this->nrPreturi + 1];

		for (int i = 0; i < this->nrPreturi; i++)
			aux[i] = this->preturi[i];

		if (aux[nrPreturi - 1] != pret_nou)
			aux[nrPreturi] = pret_nou;

		delete[] preturi;
		this->preturi = aux;
	 }
	 
	//metoda care elimina din vectorul de preturi primele k valori
	 
	void ElimPreturi(int k) {
		double* aux = new double[this->nrPreturi-k];
		for (int i = 0; i < this->nrPreturi - k; i++)
			aux[i] = this->preturi[i];

		delete[] preturi;
		this->preturi = aux;
	 }
	 
	//metoda care goleste vectorul de preturi
	 
	void Golire() {
		if (preturi != nullptr) {
			delete[] preturi;   
			preturi = nullptr;  
		}
		nrPreturi = 0;
	 }
	 
	//metoda care returneaza pretul mediu in functie de istoric
	 
	double Pret_Mediu() {
		double s = 0;
		for (int i = 0; i < this->nrPreturi; i++)
			s = s + this->preturi[i];

		double medie = s * 1.0 / nrPreturi;

		return medie;
	 }
	 
	//metoda care returneaza cel mai mic pret
	double Pret_Min() {
		double min = 999999;
		for (int i = 0; i < this->nrPreturi; i++)
			if (this->preturi[i] < min)
				min = this->preturi[i];

		return min;
	}

};

int main() {
	// vector de preturi initial
	double v[] = { 12.5, 10.0, 11.2, 9.9, 9.9, 12.5 };

	cout << "===== TEST CONSTRUCTOR COMPLET =====\n";
	Produs p1("Mouse", 6, v);
	cout << "Pret mediu initial: " << p1.Pret_Mediu() << "\n";
	cout << "Pret minim initial: " << p1.Pret_Min() << "\n\n";

	// testare Pret_Nou()
	cout << "===== TEST Pret_Nou() =====\n";
	p1.Pret_Nou(8.7); // adauga un pret nou diferit de ultimul
	cout << "Dupa adaugare, pret mediu: " << p1.Pret_Mediu() << "\n";
	cout << "Dupa adaugare, pret minim: " << p1.Pret_Min() << "\n\n";

	// testare Pret_Nou() cu pret repetat
	cout << "===== TEST Pret_Nou() (pret repetat) =====\n";
	p1.Pret_Nou(8.7); // NU ar trebui să-l adauge
	cout << "Pret mediu dupa incercarea adaugarii unui pret identic: "
		<< p1.Pret_Mediu() << "\n\n";

	// testare ElimPreturi()
	cout << "===== TEST ElimPreturi() =====\n";
	p1.ElimPreturi(2); // sterge primele 2 preturi
	cout << "Dupa eliminare, pret mediu: " << p1.Pret_Mediu() << "\n";
	cout << "Dupa eliminare, pret minim: " << p1.Pret_Min() << "\n\n";

	// testare Golire()
	cout << "===== TEST Golire() =====\n";
	p1.Golire();
	cout << "Dupa golire, pret mediu: " << p1.Pret_Mediu() << "\n";
	cout << "Dupa golire, pret minim: " << p1.Pret_Min() << "\n\n";

	// testare constructor cu denumire
	cout << "===== TEST CONSTRUCTOR DOAR CU DENUMIRE =====\n";
	Produs p2("Laptop");
	cout << "Pret mediu (fara valori): " << p2.Pret_Mediu() << "\n";
	cout << "Pret minim (fara valori): " << p2.Pret_Min() << "\n\n";

	// testare constructor fara parametri
	cout << "===== TEST CONSTRUCTOR DEFAULT =====\n";
	Produs p3;
	cout << "Pret mediu: " << p3.Pret_Mediu() << "\n";
	cout << "Pret minim: " << p3.Pret_Min() << "\n\n";

	cout << "===== SFARSIT TESTE =====\n";
	return 0;
}

