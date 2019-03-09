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

MyType & MyVector::operator[](int index)
{
	return Element(index);
}

MyVector & MyVector::operator=(const MyVector & V)
{
	MyVector copy(V);
	VSwap(copy);
	cout << "assignment operator =" << endl;

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
{
	file.open("Report.txt", fstream::app);
	file << "[Default constuctor] ";
	file << ": line = " << __LINE__;
	file << ", data = " << data << endl << endl;
	file.close();
}

MyVector::MyVector(int init_size) :
	size	(init_size),
	data	(new MyType(init_size))
{
	file.open("Report.txt", fstream::app);
	file << "[Size constuctor] ";
	file << ": line = " << __LINE__;
	file << ", data = " << data << endl << endl;
	file.close();
}

MyVector::MyVector(const MyVector& vector) :
	size 	(vector.size),
	data	(new MyType[vector.size])
{
	file.open("Report.txt", fstream::app);
	file << "[Copying constuctor] ";
	file << ": line = " << __LINE__;
	file << ", data = " << data << endl << endl;
	file.close();

	for(int i = 0; i < vector.size; i++)
		data[i] = vector.data[i];
}

MyVector::~MyVector()
{
	file.open("Report.txt", fstream::app);
	file << "[Destuctor] ";
	file << ": line = " << __LINE__;
	file << ", data = " << data << endl << endl;
	file.close();

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

MyType & MyVector::Element(int index)
{
	assert(0 <= index && index < this->size);
	return this->data[index];
}
