all:
go: main.cpp Vector.cpp
	g++ main.cpp Vector.cpp -Wall -o go
clean:
	rm -rf *.o
