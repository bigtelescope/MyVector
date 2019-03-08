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

MyType & MyVector::operator[](int index)
{
	return Element(index);
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
	assert(this->size == rhs.size);

	MyVector v1(rhs.size);
	for(int i(0); i < rhs.size; i++)
		v1.data[i] = rhs.data[i] + this->data[i];

	return v1;
}

MyVector MyVector::operator-(const MyVector & rhs)
{
	assert(this->size == rhs.size);

	MyVector v1(rhs.size);
	for(int i(0); i < rhs.size; i++)
		v1.data[i] = this->data[i] - rhs.data[i];
	return v1;
}

MyVector MyVector::operator*(MyType number)
{
	MyVector v1(this->size);

	for(int i(0); i < v1.size; i++)
		v1.data[i] = this->data[i] * number;

	return v1;
}

MyVector MyVector::operator/(MyType number)
{
	MyVector v1(this->size);

	for(int i(0); i < v1.size; i++)
		v1.data[i] = this->data[i] / number;

	return v1;
}

MyVector operator*(MyType number, const MyVector & V)
{
	MyVector v1(V.size);

	for(int i(0); i < v1.size; i++)
		v1.data[i] = V.data[i] * number;

	return v1;
}

void * MyVector::operator new(size_t, void * ptr)
{
	return ptr;
}

/*void MyVector::operator delete[] (int _size, void * ptr)
{
	for(int i(0); i < _size - 1; i++)
		delete (ptr + i*sizeof(MyType));
}*/

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

MyType & MyVector::Element(int index)
{
	assert(0 <= index && index < this->size);
	return this->data[index];
}
