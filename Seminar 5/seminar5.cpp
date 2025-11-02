#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

class Carte {
	//private: //by default
public:
	char* title = nullptr;
	char* author = nullptr;
	int year;

	Carte() {
		cout << "Acesta este constructorul default" << endl;
		this->title = new char[50];
		strcpy(this->title, "-");

		this->author = new char[50];
		strcpy(this->author, "-");

		this->year = -1;
	}

	Carte(const char* title, const char* author, const int year) {
		this->title = new char[strlen(title)+1];  //daca punem fara this la inceput se numeste shadowing
		strcpy(this->title, title);

		this->author = new char[strlen(author) + 1];
		strcpy(this->author, author);

		this->year = year;
	}

	void display() {
		cout << "Titlu: " << this->title << endl;
		cout << "Autor: " << this->author << endl;
		cout << "An: " << this->year << endl;
	}

	char* getTitle() {
		//return this->title; // shallow copy;
		char* copie = new char[strlen(this->title) + 1];
		strcpy(copie, this->title);
		return copie;
	}

	void setTitle(char* title) {
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);
	}
};

int main()
{
	Carte c1;

	c1.display();

	Carte c2("Ion", "Liviu Rebreanu", 1930);
	c2.display();

	return 0;
}