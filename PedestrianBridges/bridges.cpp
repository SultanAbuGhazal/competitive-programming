#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
	ifstream in("bridges.in");
	int k;
	in >> k;
	for(int t=0; t < k; t++){
		if(t) cout << endl;
		int time[100000] = {0};
		int peds;
		in >> peds;
		for(int i=0; i<peds; i++){
			int start, duration, end;
			in >> start >> duration;
			end = start+duration;
			for(int s=start; s <= end; s++) time[s]++;
		}
		cout << t+1 << ". " << *max_element(time, time+100000);
	}
	system("pause");
	return 0;
}