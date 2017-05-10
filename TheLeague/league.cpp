#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ifstream in("league.in");
	int k;
	in >> k;
	for(int t=0; t < k; t++){
		if(t) cout << endl;
		long i; 
		in >> i;
		cout << t+1 << ". " << i-1;
	}
	system("pause");
	return 0;
}