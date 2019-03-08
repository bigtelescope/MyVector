#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstddef>

typedef double MyType;

class MyVector
{
	private:
		int 		size;
		MyType *	data;

	public:
		MyVector		();
		MyVector		(int init_size);
		MyVector        (const MyVector& vector);
		~MyVector		();

		friend std::istream &	operator>>	(std::istream & stream, MyVector & V);
		friend std::ostream &	operator<<	(std::ostream & stream, MyVector & V);
		friend MyVector 		operator*	(MyType number, const MyVector & rhs);
		MyVector &				operator=	(const MyVector & rhs);
		MyVector 				operator+	(const MyVector & rhs);
		MyVector 				operator-	(const MyVector & rhs);
		MyVector 				operator*	(MyType number);
		MyVector 				operator/	(MyType number);
		MyType &				operator[]	(int index);
		void *					operator new(size_t, void * ptr);
		//void 					operator delete[] (int, void *);

		void					Show		(const MyVector & V);	
		void 					VSwap		(MyVector & V);
		MyType &				Element		(int index);
};

#endif
