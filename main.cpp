#include "Vector.h"

using namespace std;

int main()
{
	std::fstream file;
	file.open("Report.txt", fstream::out);
	file << "hello man\n\n";
	file.close();
	MyVector v1(3);
	cin >> v1;
	MyVector v3(v1);
	cout << "v1[0] = " << v3[0] << endl;
	cout << "v1[1] = " << v3[1] << endl;
	cout << "v1[2] = " << v3[2] << endl;
	return 0;
}
