#include "Vector.h"

std::istream& operator>>(std::istream & stream, MyVector & V)
{
	for(int i = 0; i < V.size; i++)
		std::cin >> V.data[i];
	return stream;
}

std::ostream & operator<<(std::ostream & stream, MyVector & V)
{
	std::cout << "(";
	for(int i = 0; i < V.size - 1; i++)
		std::cout << V.data[i] << ", ";
	std::cout << V.data[V.size - 1] << ") ";
	return stream;
}

MyVector & MyVector::operator=(const MyVector & V)
{
	MyVector copy(V);
	VSwap(copy);
	std::cout << "assignment operator =" << std::endl;
	return(*this);
}

MyVector MyVector::operator+(const MyVector & rhs)
{
	//if(v1.size != v2.size)
	//	return 0;

	MyVector v1(rhs.size);
	for(int i(0); i < rhs.size; i++)
		v1.data[i] = rhs.data[i] + this->data[i];

	return v1;
}

MyVector MyVector::operator-(const MyVector & rhs)
{
	//if(v1.size != v2.size)
	//	return 0;

	MyVector v1(rhs.size);
	for(int i(0); i < rhs.size; i++)
		v1.data[i] = this->data[i] - rhs.data[i];

	return v1;
}

MyVector::MyVector() :
	size 	(0),
	data	(nullptr)
{std::cout << "default constructor, data = " << data << std::endl;}

MyVector::MyVector(int init_size) :
	size	(init_size),
	data	(new MyType(init_size))
{std::cout << "size constructor, data = " << data << std::endl;}

MyVector::MyVector(const MyVector& vector) :
	size 	(vector.size),
	data	(new MyType[vector.size])
{
	for(int i = 0; i < vector.size; i++)
		data[i] = vector.data[i];
	std::cout << "vector constructor, data = " << data << std::endl;
}

MyVector::~MyVector()
{
	std::cout << "DESTROOOOOOOOOY, data = " << data << std::endl;;
	if(data != nullptr)
		delete [] data;
}

void MyVector::Show(const MyVector & V)
{
	if(size)
	{
		std::cout << "(";
		for(int i = 0; i < size - 1; i++)
			std::cout << data[i] << ", ";
		std::cout << data[size -1] << ") " << std::endl;
	}
}

void MyVector::VSwap(MyVector & V)
{
	std::swap(size, V.size);
	std::swap(data, V.data);
}

