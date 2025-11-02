#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

class Masina {
public:
	char* marca;
	char* model;
	double* preturi_revizii;
	int nrRevizii;
	int anFab;


	Masina() {
		marca = nullptr;
		model = nullptr;
		preturi_revizii = nullptr;
		nrRevizii = 0;
		anFab = 0;
	}

	Masina(const char* marca, const char* model)
	{
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);

		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
	}

	Masina(const char* marca, const char* model, const double* preturi_revizii, const int nrRevizii, const int anFab) {
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);

		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);

		this->nrRevizii = nrRevizii;

		this->preturi_revizii = new double[this->nrRevizii];
		for (int i = 0; i < this->nrRevizii; i++)
			this->preturi_revizii[i] = preturi_revizii[i];

		this->anFab = anFab;
	}

	char* getMarca() {
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);

		return this->marca;
	}

	void setMarca(const char* marca)
	{
		if (this->marca != nullptr)
			delete[] this->marca;

		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
	}

	char* getModel() {
		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);

		return this->model;
	}

	void setModel(const char* model) {
		if (this->model != nullptr)
			delete[] this->model;

		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
	}

	int getNrRevizii() {

		return this->nrRevizii;
	}

	void setNrRevizii(const int nrRevizii) {
		if (this->nrRevizii != 0)
			this->nrRevizii = 0;

		this->nrRevizii = nrRevizii;
	}

	void setPreturi(const double* preturi_revizii, const int nrPreturi)
	{
		if (this->preturi_revizii != nullptr)
			delete[] this->preturi_revizii;

		this->preturi_revizii = new double[nrPreturi];
		for (int i = 0; i < nrPreturi; i++)
			this->preturi_revizii[i] = preturi_revizii[i];
	}

	int getAnFab() {
		return this->anFab;
	}

	double CostTotal() {
		double s = 0;
		for (int i = 0; i < this->nrRevizii; i++)
			s = s + this->preturi_revizii[i];

		return s;
	}

	void AdaugaPret(double pret_nou) {
		double* aux = new double[this->nrRevizii + 1];

		for (int i = 0; i < this->nrRevizii; i++)
			aux[i] = this->preturi_revizii[i];

		aux[this->nrRevizii] = pret_nou;

		this->nrRevizii++;

		delete[] this->preturi_revizii;

		for (int i = 0; i < this->nrRevizii; i++)
			this->preturi_revizii[i] = aux[i];
	}

	void Afiseaza() {
		cout << "Marca: " << marca << endl;
		cout << "Model: " << model << endl;
		cout << "Numar revizii: " << nrRevizii << endl;
		cout << "Preturi revizii: ";
		for (int i = 0; i < this->nrRevizii; i++)
			cout << this->preturi_revizii[i] << " ";
		cout << endl;

		cout << "An fabricatie: " << anFab;
	}
};

int main()
{
	char marca[50] = "Toyota";
	char model[50] = "Corolla";
	int nrRevizii = 4;
	double preturi_revizii[4] = {500.35, 350.75, 275.65, 490.25};
	int anFab = 2025;

	cout << "-------------CONSTRUCTOR COMPLET---------------" << endl;
	
	Masina m1(marca, model, preturi_revizii, nrRevizii, anFab);

	m1.setMarca("Dacia");
	cout << m1.marca<<endl;
	m1.setModel("Logan");
	cout << m1.model<<endl;
	m1.setNrRevizii(3);

	double preturi_noi[] = {100,200,300};
	m1.setPreturi(preturi_noi, 3);

	double suma=m1.CostTotal();
	cout<<suma<< endl;
	m1.AdaugaPret(500);
	
	for (int i = 0; i < m1.nrRevizii; i++)
		cout << m1.preturi_revizii[i] << " ";

	m1.Afiseaza();
	
}