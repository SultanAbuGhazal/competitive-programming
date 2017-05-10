#include<iostream>
#include<fstream>
using namespace std;
int main(){
	int T;
	ifstream fin;
	fin.open("rotate.in");
	fin >> T;
	int t = 1;
	while (T--){
		int n, x;
		fin >> n >> x;
		int a[3] = { 0 };
		int c = 2;
		while (c>=0){
			a[c--] = n % 10;
			n /= 10;
		}
		cout << t++ << ". ";
		if (x % 3 == 0)
			cout << a[0] << a[1] << a[2] << endl;
		else if (x % 3 == 1)
			cout << a[2] << a[0] << a[1] << endl;
		else
			cout << a[1] << a[2] << a[0] << endl;
	}
	//system("pause");
}