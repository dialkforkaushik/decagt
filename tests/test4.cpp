#include "simplicial_complex.h"
#include "core_utils.h"
#include "finite_element_exterior_calculus.h"
#include <iostream>
#include <vector>

int main (int argc, char const *argv[]) {
	double error;
	Vector2D U;
	SimplicialComplex sc;
	sc.build_complex();

	FiniteElementExteriorCalculus fem(sc);

	for(int i = 0; i < 4; ++i) {
		U.push_back(sc.vertices[i]);
	}

	// DenMatD M;
	// fem.mass_matrix_bb_curl(M,U,1,1);
	// std::cout<<M<<"\n\n";

	error = fem.bb_error_1(1,
							sc.simplices,
							sc.vertices,
							sc.num_simplices,
							2);

	std::cout<<error<<"\n";

	return 0;
}



