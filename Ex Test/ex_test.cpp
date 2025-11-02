#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
	char* nume_stud;
	float* note_stud;
	int nr_note;
	char facultate[50];

public:

	Student() {
		nume_stud = nullptr;
		note_stud = nullptr;
		nr_note = 0;
		facultate[0] = '\0';
	}

	Student(const char* nume, const char* facultate) {
		this->nume_stud = new char[strlen(nume) + 1];
		strcpy(this->nume_stud, nume);

		strcpy(this->facultate, facultate);
	}

	Student(const char* nume, const float* note, const int nr_note, const char* facultate) {
		this->nume_stud = new char[strlen(nume) + 1];
		strcpy(this->nume_stud, nume);

		strcpy(this->facultate, facultate);

		this->nr_note = nr_note;

		this->note_stud = new float[this->nr_note];
		for (int i = 0; i < this->nr_note; i++)
			this->note_stud[i] = note[i];
	}

	//getter + setter NUME

	char* getNume()
	{
		return nume_stud;
	}

	void setNume(const char* nume)
	{
		if (this->nume_stud != nullptr)
			delete[] this->nume_stud;

		this->nume_stud = new char[strlen(nume) + 1];
		strcpy(this->nume_stud, nume);
	}

	//getter + setter nr_note

	int getNrNote()
	{
		return nr_note;
	}

	void setNrNote(int nr)
	{
		this->nr_note = nr;
	}

	//setter note

	void setNote(const float* note, int nr_note)
	{
		if (this->note_stud != nullptr)
			delete[] this->note_stud;

		this->nr_note = nr_note;
		this->note_stud = new float[nr_note];

		for (int i = 0; i < nr_note; i++)
			this->note_stud[i] = note[i];
	}

	//getter facultate

	char* getFacultate()
	{
		return facultate;
	}

	float calculeazaMedie()
	{
		float s = 0;
		for (int i = 0; i < nr_note; i++)
			s = s + note_stud[i];

		float medie = s * 1.00 / nr_note;

		return medie;

	}

	void afiseaza()
	{
		cout << "Nume: " << nume_stud << endl;

		cout << "Numar note: " << nr_note << endl;

		cout << "Note: ";
		for (int i = 0; i < nr_note; i++)
			cout << note_stud[i] << " ";
		cout << endl;

		cout << "Facultate: " << facultate;
	}


	void adaugaNota(int nota)
	{
		float* aux = new float[this->nr_note + 1];
		for (int i = 0; i < this->nr_note; i++)
			aux[i] = this->note_stud[i];

		aux[this->nr_note] = nota;

		delete[] this->note_stud;
		this->note_stud = aux;
		this->nr_note++;
	}
};

int main() {
	// vector de note pentru test
	float note[] = { 8.5, 9.0, 7.5 };

	//  Constructor complet
	Student s1("Andrei", note, 3, "CSIE");
	cout << "----- Student 1 -----" << endl;
	s1.afiseaza();
	cout << endl << "Media: " << s1.calculeazaMedie() << endl << endl;

	//  Setter pentru nume
	s1.setNume("Maria");
	cout << "----- Dupa schimbarea numelui -----" << endl;
	s1.afiseaza();
	cout << endl;

	//  Adauga o nota
	s1.adaugaNota(10);
	cout << endl << "----- Dupa adaugarea unei note -----" << endl;
	s1.afiseaza();
	cout << endl << "Noua medie: " << s1.calculeazaMedie() << endl << endl;

	//  Constructor simplu
	Student s2("Cristina", "CSIE");
	cout << "----- Student 2 -----" << endl;
	s2.afiseaza();
	cout << endl;

	return 0;
}
