#include <iostream>
#include "Vektor.h"

int main() {
	CMyVektor VektorA;
	// Dimensionen
	VektorA.CMyVektorSetDimension(4);
	std::cout << "Dimension: " << VektorA.CMyVektorGetDimension() << std::endl;
	// Ausgabe Vektor
	VektorA.CMyVektorPrint();
	// Komponenten
	VektorA.CMyVektorSetComponent(5, 3);
	VektorA.CMyVektorPrint();
	VektorA.CMyVektorSetComponent(8.2, 4);
	VektorA.CMyVektorPrint();
	std::cout << "Komponente an Position: " << VektorA.CMyVektorGetComponent() << std::endl;

	std::cin.get();
}