#include "Vector.h"

using namespace std;

istream& operator>>(istream & stream, MyVector & V)
{
	for(int i = 0; i < V.size; i++)
		cin >> V.data[i];

	return stream;
}

ostream & operator<<(ostream & stream, MyVector & V)
{
	cout << "(";
	for(int i = 0; i < V.size - 1; i++)
		cout << V.data[i] << ", ";
	cout << V.data[V.size - 1] << ") ";

	return stream;
}

const MyType & MyVector::operator[](int index) const
{
	return this->data[index];
}

MyType & MyVector::operator[](int index)
{
	return data[index];
}

MyVector & MyVector::operator=(const MyVector & V)
{
	MyVector copy(V);
	VSwap(copy);

	return(*this);
}

MyVector & MyVector::operator=(MyVector && rhs)
{
	VSwap(rhs);
}

MyVector MyVector::operator+(const MyVector & rhs)
{
	assert(this->size == rhs.size);

	MyVector v1(rhs);
	for(int i(0); i < rhs.size; i++)
		v1.data[i] += rhs.data[i];

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

MyVector::MyVector() :
	size 	(0),
	data	(nullptr)
{}

MyVector::MyVector(int init_size) :
	size	(init_size),
	data	(new MyType[init_size])
{}

MyVector::MyVector(const MyVector& vector) :
	size 	(vector.size),
	data	(new MyType[vector.size])
{
	for(int i = 0; i < vector.size; i++)
		data[i] = vector.data[i];
}

MyVector::MyVector(MyVector && vector)
{
	VSwap(vector);
}

MyVector::~MyVector()
{
	if(data != nullptr)
	{
		delete [] data;
	}
}

void MyVector::Show(const MyVector & V)
{
	if(size)
	{
		cout << "(";
		for(int i = 0; i < size - 1; i++)
			cout << data[i] << ", ";
		cout << data[size -1] << ") " << endl;
	}
}

void MyVector::VSwap(MyVector & V)
{
	swap(size, V.size);
	swap(data, V.data);
}