#include<iostream>
#include<string>
#include<fstream>
using namespace std;
bool isSpecial(char x){
	return (x == '#' || x == '$' || x == '|' || x == '%');
}
int main(){
	int T;
	ifstream fin;
	fin.open("csv.in");
	fin >> T;
	//int t = 1;
	while (T--){
		string x;
		fin >> x;
		int count = 0;
		for (int i = 0; i < x.length(); i++){
			if (isSpecial(x[i])){
				count++;
				cout << ",";
			}
			else
				cout << x[i];
		}
		cout << "," << count+1 << endl;
	}
	//system("pause");
}