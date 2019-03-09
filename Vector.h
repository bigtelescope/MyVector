/*
-------------------QUESTIONS--------------

1) 	Если в классе есть указатель на файл, как лучше 
	его инициализировать в конструкторе?

2)	Можно ли как-нибудь узнать номер строки
	вызова без передачи аргумента __ЛАЙН__ 
	в конструкторе?

*/

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
		std::string str;

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

		void					Show		(const MyVector & V);	
		void 					VSwap		(MyVector & V);
		MyType &				Element		(int index);
};

#endif
