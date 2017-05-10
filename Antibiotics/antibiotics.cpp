#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct time{
	int t;
	char type;
	time(int a, char b): t(a), type(b) {}
};

bool comp(time a, time b){
	if(a.t < b.t) return true;
	else if(a.t == b.t && a.type == 's' && b.type == 'e') return true;
	else if(a.t == b.t && a.type == 'e' && b.type == 's') return false;
	else return false;
}

int main(){
	ifstream in("antibiotics.in");
	int N;
	in >> N;
	
	bool all_clear = true;
	for(int n=0; n < N; n++){
		if(n) cout << endl;
		all_clear = true;
		int C;
		in >> C;

		vector<time> patient[1000];
		for(int c=0; c < C; c++){
			int P, S, E;
			in >> P >> S >> E;
			time temp1(S, 's');
			time temp2(E, 'e');
			patient[P-1].push_back(temp1);
			patient[P-1].push_back(temp2);
		}

		for(int p=0; p < 1000; p++){ //iterating patients-------------------
			int len = patient[p].size();
			if(len > 0){
				sort(patient[p].begin(), patient[p].end(), comp);
				int count = 0, max = 0;
				//cout << "->";

				for(int i=0; i < len; i++){
					if(patient[p][i].type == 's'){
						count++;
					}else{
						count--;
					}
					if(count > max) max = count;
					//cout << count << " ";
				}

				//cout << endl;
				if(max > 1){
					all_clear = false;
					cout << p+1 << " " << max << endl;
				}
			}
		}//-----------------------------------------------------------------
		//cout << endl << endl;
		if(all_clear) cout << "All Clear" << endl;
	}

	system("pause");
	return 0;
}