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

	void CMyVektorSetDimension(int dim) {
		if (dim > 0) {
			dimension = dim;
			for (int i = 0; i <= dimension-1; i++) {
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
		position = pos-1;
		if (position <= dimension) {
			for (int i = 0; i <= dimension-1; i++)
				if (i == position)
					Vektor[i] = comp;
		}
		else
			std::cout << "Komponente existiert nicht!" << std::endl;
	}

	double CMyVektorGetComponent() {
		for (int i = 0; i <= dimension-1; i++) {
			if (i == position)
				return Vektor[position];
		}
	}

	// Hilfsfunktion
	void Print() const{
		std::cout << "[ ";
		for (double komponente : Vektor) {
			if (komponente == Vektor.back())
				std::cout << komponente << " ";
			else 
				std::cout << komponente << "; ";
		}
		std::cout << "]" << std::endl;
	}

	// Länge Vektor
	double CMyVektorLength() {
		double VektorLength = 1;
		for (int i = 0; i <= dimension-1; i++) {
			VektorLength += pow(Vektor[i],2);
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

	//CMyVektor gradient(CMyVektor x, double (*funktion)(CMyVektor x)) {

	//}
};