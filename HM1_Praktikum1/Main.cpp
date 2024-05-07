#include <iostream>
#include "Vektor.h"

// Testfunktion aus E-Test f(x,y,z) = 3x^2+5yz^2 mit h=0.1
double funktion_xyz(CMyVektor v) {
	double x = v.CMyVektorGetComponent(0);
	double y = v.CMyVektorGetComponent(1);
	double z = v.CMyVektorGetComponent(2);
	return 3*(x * x) + (5*y*(z * z));
}

int main() {

	//CMyVektor VektorA;
	//// Dimensionen
	//VektorA.CMyVektorSetDimension(4);
	//std::cout << "Dimension: " << VektorA.CMyVektorGetDimension() << std::endl;
	//// Ausgabe Vektor
	//VektorA.Print();
	//// Komponenten
	//VektorA.CMyVektorSetComponent(5, 3);
	//VektorA.Print();
	//VektorA.CMyVektorSetComponent(8.2, 4);
	//VektorA.Print();
	//std::cout << "Komponente an Position: " << VektorA.CMyVektorGetComponent(2) << std::endl;
	//std::cout << "Laenge des Vektors: " << VektorA.CMyVektorLength() << std::endl;

	//CMyVektor VektorB;
	//VektorB.CMyVektorSetDimension(4);
	//VektorB.CMyVektorSetComponent(2, 2);
	//VektorB.CMyVektorSetComponent(4, 3);

	//CMyVektor Vektoraddition = VektorA + VektorB;
	//std::cout << "Vektoraddition: ";
	//Vektoraddition.Print();

	//double Lambda = 2.0;
	//CMyVektor SkalarMultiplikation = VektorA * Lambda;
	//std::cout << "Skalare Multiplikation: ";
	//SkalarMultiplikation.Print();

	// Stelle x für Testfunktion E-Test
	CMyVektor gradientBerechnung;
	gradientBerechnung.CMyVektorSetDimension(3);
	gradientBerechnung.CMyVektorSetComponent(1, 1); // x = 1
	gradientBerechnung.CMyVektorSetComponent(3, 2); // y = 3
	gradientBerechnung.CMyVektorSetComponent(2, 3); // z = 2

	// Berechnung Gradient an Stelle x
	CMyVektor gradient_result = gradientBerechnung.gradient(gradientBerechnung, funktion_xyz);

	std::cout << "grad f(1,3,2): ";
	gradient_result.Print();

	system("PAUSE");
}