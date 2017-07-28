#include "Vertice.hpp"
#include <iostream>

using std::cout;
using std::endl;


namespace ed{

	Vertice & Vertice::operator=(const Vertice &v){
		setData(v.getData());
		setLabel(v.getLabel());

		return *this;
	}








}
