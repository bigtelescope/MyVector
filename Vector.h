#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <fstream>
#include <cstring>

typedef double MyType;

class MyVector
{
	private:
		int 			size;
		MyType *		data;
		std::fstream 	file;

	public:
		MyVector		();
		MyVector		(int init_size);
		MyVector        (const MyVector& vector);
		MyVector		(MyVector && vector);
		~MyVector		();

		friend std::istream &	operator>>	(std::istream & stream, MyVector & V);
		friend std::ostream &	operator<<	(std::ostream & stream, MyVector & V);
		friend MyVector 		operator*	(MyType number, const MyVector & rhs);

		MyVector &				operator=	(const MyVector & rhs);
		MyVector &				operator=	(MyVector && rhs);
		const MyType &			operator[]	(int index) const;
		MyType &				operator[]	(int index);
		MyVector 				operator+	(const MyVector & rhs);
		MyVector 				operator-	(const MyVector & rhs);
		MyVector 				operator*	(MyType number);
		MyVector 				operator/	(MyType number);
		
		void					Show		(const MyVector & V);	
		void 					VSwap		(MyVector & V);
};

#endif
