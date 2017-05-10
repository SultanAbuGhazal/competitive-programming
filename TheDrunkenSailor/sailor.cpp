#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(){
	int T;
	ifstream fin;
	fin.open("sailor.in");
	fin >> T;
	int t = 1;
	while (T--){
		bool fell = 0;
		int P, L, S;
		fin >> P >> L >> S;
		while (S--){
			int x;
			char c;
			fin >> x >> c;
			if (!fell){
				if (c == 'L'){
					L -= x;
					if (L < 1)
						fell = 1;
				}
				else{
					L += x;
					if (L>P)
						fell = 1;
				}
			}
		}
		cout << t++ << ". ";
		if (fell)
			cout << "Sailor Falls!\n";
		else
			cout << L << endl;
	}
	//system("pause");
}