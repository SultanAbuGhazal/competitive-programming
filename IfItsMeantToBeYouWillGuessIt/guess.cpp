#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	ifstream in("guess.in");
	int n;
	in >> n;
	for(int t=0; t < n; t++){
		if(t) cout << endl;
		double N, X, Y, p;
		in >> N >> X >> Y;
		if(N==X && Y!=0) p=1;
		else {double ppt = 1/pow(10, N-X); p=ppt*Y;}
		if(p>1.00) p=1;
		cout << t+1 << ". " << fixed << setprecision(2) << p*100 << "%";
	}
	//system("pause");
	return 0;
}