#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
#include <algorithm>

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
		MyVector &		operator=	(const MyVector & rhs);
		MyVector 		operator+	(const MyVector & rhs);
		MyVector 		operator-	(const MyVector & rhs);
//		MyVector &		operator*	(const MyVector & v1, const MyVector & v2);
//		MyVector &		operator/	(const MyVector & v1, const MyVector & v2);

		void			 Show		(const MyVector & V);	
		void 			VSwap		(MyVector & V);
};

#endif
