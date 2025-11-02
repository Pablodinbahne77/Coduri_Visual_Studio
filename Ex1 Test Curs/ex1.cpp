#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

bool esteNotaValida(int valoare) {
	return (valoare >= 1 && valoare <= 10);
}

class Student {
	char* nume;
	float bugetDisponibil;
	int nrNote;
	int* note;


public:
	//constructor fara param

	Student() {
		nume = nullptr;
		bugetDisponibil = 0;
		nrNote = 0;
		note = nullptr;
	}

	//constructor care primeste nume si bugetDisponibil

	Student(const char* nume, const int bugetDisponibil) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);

		this->bugetDisponibil = bugetDisponibil;
	 }

	//constructor care primeste toti param dar valideaza notele
	//(nu se vor adauga in vector notele care nu apartin [1;10]

	Student(const char* nume, const int bugetDisponibil, const int nrNote, const int* note) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);

		this->bugetDisponibil = bugetDisponibil;

		this->note = new int[nrNote];   // vector cu dimensiunea maximă posibilă

		int validCount = 0;             // contor separat
		for (int i = 0; i < nrNote; i++) {
			if (esteNotaValida(note[i])) {
				this->note[validCount] = note[i];
				validCount++;
			}
		}

		this->nrNote = validCount;      // setăm abia la final numărul real de note valide
	}


	//metoda care primeste o noua nota si o adauga in lista de note
	 
	void NotaNoua(int nota) {
		int* aux = new int[nrNote + 1];
		for (int i = 0; i < nrNote; i++)
			aux[i] = note[i];

		aux[nrNote] = nota;   // scriem în cel NOU vector
		delete[] note;
		note = aux;
		nrNote++;
	}

	 
	//metoda care elimina notele sub medie
	 
	void ElimNote() {
		int s = 0;
		for (int i = 0; i < this->nrNote; i++)
			s = s + this->note[i];

		int medie = s / nrNote;

		int cnt = 0;
		for (int i = 0; i < this->nrNote; i++)
			if (this->note[i] < medie)
				cnt++;

		int* aux = new int[nrNote - cnt];
		for (int i = 0; i < this->nrNote-cnt; i++)
			if (this->note[i] > medie)
				aux[i] = this->note[i];

		delete[] this->note;
		this->note = aux;  // redirecționează pointerul către vectorul nou
		this->nrNote -= cnt;


	 }
	
	//metoda care dubleaza ultima nota din lista
	 
	void DublNota() {
		int ultnota = this->note[this->nrNote - 1];

		int* aux = new int[this->nrNote + 1];

		for (int i = 0; i < this->nrNote; i++)
			aux[i] = this->note[i];

		aux[this->nrNote] = ultnota;

		delete[] this->note;
		this->note = aux;
		this->nrNote++;
	
	 }
	 
	//metoda care suplimenteaza bugetul disponibil cu o valoare primita ca parametru

	void SuplBuget(int supliment) {
		this->bugetDisponibil = this->bugetDisponibil + supliment;
	}

};

//functie globala care verifica daca o valoare intreaga reprezinta o nota


int main() {
	// Vector de note pentru test
	int note1[] = { 10, 8, 7, 3, 11, -2 };  // include și valori invalide (11 și -2)
	int nrNote1 = 6;

	//  Constructor complet (cu validare)
	Student s1("Andrei", 1000, nrNote1, note1);

	cout << "===== STUDENT 1 =====" << endl;
	s1.SuplBuget(500);  // crește bugetul
	s1.DublNota();      // dublează ultima notă
	s1.NotaNoua(9);     // adaugă o nouă notă
	s1.ElimNote();      // elimină notele sub medie

	cout << "Test complet pentru s1 terminat!" << endl;

	//  Constructor simplu
	Student s2("Maria", 750);
	s2.SuplBuget(250);

	cout << "\n===== STUDENT 2 =====" << endl;
	cout << "Student creat doar cu nume si buget (fara note)." << endl;

	//  Constructor default
	Student s3;
	cout << "\n===== STUDENT 3 =====" << endl;
	cout << "Student creat cu constructor default (fara parametri)." << endl;

	//  Testare funcție globală
	cout << "\n===== TESTARE FUNCTIE GLOBALA =====" << endl;
	int x;
	cout << "Introdu o nota pentru validare: ";
	cin >> x;
	if (esteNotaValida(x))
		cout << "Nota valida!\n";
	else
		cout << "Nota invalida!\n";

	return 0;
}

