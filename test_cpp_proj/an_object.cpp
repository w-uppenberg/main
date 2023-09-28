#include "an_object.h"

AnObject::AnObject(int num) {
	this->num = num;
}

void AnObject::testPrint() {
	std::cout << "test: " << num << std::endl; 
}

