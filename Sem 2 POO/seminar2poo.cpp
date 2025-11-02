#include <iostream>
using namespace std;



int main()
{
	int x = 3;//modificare si initializare

	const int cx = 3;//initializare

	int* p = &x;//modificare si initiializare

	//const int* p = &x;//modificare, initializare a adresei pointerului

	int* const pc = &x;//initializare a adresei pointerului

	const int* const cpc = &cx;//initializare

	cout << "x= " << x << endl;
	*p = 5;
	cout << "x= " << x << endl;
	//cout << "x= " << x << endl;
	//cout << "x= " << x << endl;


}