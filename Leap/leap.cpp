#include <iostream>
#include <fstream>
using namespace std;

bool isLeap(long long x){
	if(x%4==0){
		if(x%100==0){
			if(x%400==0) return true;
			return false;
		}
		return true;
	} else return false;
}

int main(){
	ifstream in("leap.in");
	int n;
	in >> n;
	for(int t=0; t < n; t++){
		if(t) cout << endl;
		long long birth, now;
		in >> birth >> now;
		if(!isLeap(birth)) cout << t+1 << ". " << "Not a leap year!";
		else cout << t+1 << ". " << (now/4 - now/100 + now/400) - (birth/4 - birth/100 + birth/400);
	}
	system("pause");
	return 0;
}