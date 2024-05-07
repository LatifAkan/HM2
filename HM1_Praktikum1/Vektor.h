#pragma once 
#include <cmath>
#include <vector>

class CMyVektor {

private:

	int dimension = 1, position = 0;
	std::vector<double> Vektor;

public:

	CMyVektor() {}

	CMyVektor(const std::vector<double>& v)
		: Vektor(v) {}

	// Dimension des Vektors setzten & mit 0 füllen
	void CMyVektorSetDimension(int dim) {
		if (dim > 0) {
			dimension = dim;
			for (int i = 0; i <= dimension - 1; i++) {
				Vektor.push_back(0);
			}
		}
		else
			std::cout << "Ungueltige Dimension!" << std::endl;
	}

	int CMyVektorGetDimension() const {
		return dimension;
	}

	void CMyVektorSetComponent(double comp, int pos) {
		position = pos - 1;
		if (position <= dimension) {
			for (int i = 0; i <= dimension - 1; i++)
				if (i == position)
					Vektor[i] = comp;
		}
		else
			std::cout << "Komponente existiert nicht!" << std::endl;
	}

	double CMyVektorGetComponent(int pos) {
		for (int i = 0; i < dimension; i++) {
			if (i == pos)
				return Vektor[i];
		}
		// Fehlermeldung einbauen
		return 0;
	}

	// Vektor ausgeben
	void Print() const {
		std::cout << "[ ";
		for (double komponente : Vektor) {
			if (komponente == Vektor.back())
				std::cout << komponente << " ";
			else
				std::cout << komponente << "; ";
		}
		std::cout << "]" << std::endl;
	}

	// Laenge Vektor
	double CMyVektorLength() {
		double VektorLength = 1;
		for (int i = 0; i <= dimension - 1; i++) {
			VektorLength += pow(Vektor[i], 2);
		}
		return sqrt(VektorLength);
	}

	// Vektoraddition & Skalare Mult implementieren

	CMyVektor operator+(const CMyVektor& otherVektor) const {
		std::vector<double> ergebnisVektor;
		for (int i = 0; i < Vektor.size(); i++) {
			ergebnisVektor.push_back(Vektor[i] + otherVektor.Vektor[i]);
		}
		return CMyVektor(ergebnisVektor);
	}

	CMyVektor operator*(double lambda) const {
		std::vector<double> ergebnisVektor;
		for (double komponente : Vektor) {
			ergebnisVektor.push_back(komponente * lambda);
		}
		return CMyVektor(ergebnisVektor);
	}

	// Gradient Funktion

	CMyVektor gradient(CMyVektor& x, double (*funktion)(CMyVektor)) {

		// Wert für h
		const double h = 1e-8;

		CMyVektor gradientVector;
		gradientVector.CMyVektorSetDimension(x.CMyVektorGetDimension()); // Gradientenvektor mit gleicher Dimension wie x

		for (int i = 0; i < dimension; ++i) {

			// Kopie von x
			CMyVektor x_plus_h = x;

			// Stelle x_i mit h addieren
			x_plus_h.CMyVektorSetComponent(x.CMyVektorGetComponent(i) + h, i+1);

			// Berechnung x_i + h in Funktion f(x_1,...,x_(i-1),x_i+h,x_(i+1),...,x_n)
			double f_x_plus_h = (*funktion)(x_plus_h);

			// Funktion selbst f(x_1,...,x_n)
			double f_x = (*funktion)(x);

			// Berechnung Gradient für i-te Komponente
			double gradient_i = (f_x_plus_h - f_x) / h;

			// i-te Komponente des Gradientenvektors setzen
			gradientVector.CMyVektorSetComponent(gradient_i, i + 1);
		}

		return gradientVector;
	}

};