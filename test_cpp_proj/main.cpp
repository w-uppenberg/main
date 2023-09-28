#include "an_object.h"

int main() {
	std::cout << "Hello World" << std::endl;

	auto obj = AnObject(11);
	obj.testPrint();
	return 0;
}
