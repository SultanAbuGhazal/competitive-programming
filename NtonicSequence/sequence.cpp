#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
	ifstream in("sequence.in");
	int a, seqs = 0;
	in >> a;
	while(a != 0){
		if(seqs) cout << endl;
		seqs++;
		vector<bool> vec;
		if(a > 1){
			int prev; in >> prev;
			for(int n = 1; n < a; n++){
				int c;
				in >> c;
				if(prev <= c) {vec.push_back(true);}//add a 1 to the vector
				else if(prev > c){vec.push_back(false);}//add a 0 to the vector
				prev = c;
			}
		} else if(a == 1){
			int ignr; in >> ignr;
			vec.push_back(false);
		}

		//print sequence type
		int count = 0;
		for(int i=0; i < vec.size()-1; i++){
			if(vec[i] != vec[i+1]) count++;
		}

		cout << seqs;
		if(count == 0) cout << " mono";
		else if(count == 1) cout << " bi";
		else if (count > 1) cout << " poly";

		in >> a;
	}

	//system("pause");
	return 0;
}