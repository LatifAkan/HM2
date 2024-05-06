#include <iostream>
#include "Vektor.h"

int main() {
	CMyVektor VektorA;
	// Dimensionen
	VektorA.CMyVektorSetDimension(4);
	std::cout << "Dimension: " << VektorA.CMyVektorGetDimension() << std::endl;
	// Ausgabe Vektor
	VektorA.Print();
	// Komponenten
	VektorA.CMyVektorSetComponent(5, 3);
	VektorA.Print();
	VektorA.CMyVektorSetComponent(8.2, 4);
	VektorA.Print();
	std::cout << "Komponente an Position: " << VektorA.CMyVektorGetComponent() << std::endl;
	std::cout << "Laenge des Vektors: " << VektorA.CMyVektorLength() << std::endl;

	CMyVektor VektorB;
	VektorB.CMyVektorSetDimension(4);
	VektorB.CMyVektorSetComponent(2, 2);
	VektorB.CMyVektorSetComponent(4, 3);

	CMyVektor Vektoraddition = VektorA + VektorB;
	std::cout << "Vektoraddition: ";
	Vektoraddition.Print();

	double Lambda = 2.0;
	CMyVektor SkalarMultiplikation = VektorA * Lambda;
	std::cout << "Skalare Multiplikation: ";
	SkalarMultiplikation.Print();

	std::cin.get();
}