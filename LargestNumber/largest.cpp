#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ifstream in("largest.in");
	int k;
	in >> k;
	for(int t=0; t < k; t++){
		if(t) cout << endl;
		vector<string> vec;
		int n;
		in >> n;
		for(int i=0; i < n; i++){
			string c;
			in >> c;
			vec.push_back(c);
		}
		sort(vec.begin(), vec.end(), [](string a, string b) {
			if(a+b>b+a) return true;
			return false;
		});
		for (int i=0; i < n; i++)
			cout << vec[i];
	}
	system("pause");
	return 0;
}