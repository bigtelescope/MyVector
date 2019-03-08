#include "Vector.h"

int main()
{
	MyVector v1(3);
	std::cin >> v1;
	v1.~MyVector();
	std::cout << "v1[0] = " << v1[0] << std::endl;
	std::cout << "v1[1] = " << v1[1] << std::endl;
	std::cout << "v1[2] = " << v1[2] << std::endl;
	return 0;
}
