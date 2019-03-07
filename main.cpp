#include "Vector.h"

int main()
{
	MyVector v1(2);
	MyVector v2(2);
	std::cin >> v1;
	std::cin >> v2;
	v1.VSwap(v2);
	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;
	MyVector v3(2);
	v3 = v2 - v1;
	std::cout << "v3 =" << v3 << std::endl;
	return 0;
}
