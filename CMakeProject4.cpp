#include "CMakeProject4.h"
#include "Vector.h"

int main() {
	Vector<int> vec;
	for (int i = 0; i < 10; i++) {
		vec.pushBack(i);
		//std::cout << vec[i] << std::endl;
	}
	Vector<int> vec1;
	for (int i = 0; i < 11; i++) {
		vec1.pushBack(i);
	}
	Vector<int> vec2 = vec + vec1;
	for (int i = 0; i < vec2.getSize(); i++) {
		std::cout << vec2[i] << std::endl;
	}
}
