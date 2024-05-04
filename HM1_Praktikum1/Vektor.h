#pragma once 
#include <cmath>
#include <vector>

class CMyVektor {

private:

	int dimension = 1, position = 0;
	std::vector<double> Vektor;

public:

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

	void CMyVektorPrint() const{
		std::cout << "[ ";
		for (int i = 0; i <= dimension-1; i++) {
			if (i == dimension-1)
				std::cout << Vektor[i] << " ";
			else 
				std::cout << Vektor[i] << " ; ";
		}
		std::cout << "]" << std::endl;
	}

	double CMyVektorLength() {
		double VektorLength = 1;
		for (int i = 0; i <= dimension - 1; i++) {
			VektorLength += pow(Vektor[i],2);
		}
		sqrt(VektorLength);
	}

	/*CMyVektor operator+(CMyVektor a, CMyVektor b) {

	}*/

};