#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(){
	ifstream in("predict.in");
	int N;
	in >> N;

	while(N != 0){
		vector<string> dic;
		for(int i=0; i < N; i++){
			string temp;
			in >> temp;
			dic.push_back(temp);
		}

		string q;
		in >> q;
		while(q != "###"){
			int count = 0;
			int q_len = q.length();
			cout << q << ": ";			
			for(int i=0; i < N; i++){
				if(q == dic[i].substr(0, q_len)){
					cout << dic[i] << " ";
					count++;
				}
				if(count == 3) break;
			}
			if(!count) cout << q << " ";
			cout << endl;
			in >> q;
		}

		in >> N;
	}

	system("pause");
	return 0;
}