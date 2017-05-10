#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ifstream in("sorter.in");
	int n;
	in >> n;
	in.ignore(255, '\n');
	for(int t=0; t < n; t++){
		if(t) cout << endl;
		vector<string> vec;
		string c;
		getline(in, c);
		int l = c.length();
		for(int i=0; i < l; i++){
			if(i==0) vec.push_back(c);
			else vec.push_back(vec[vec.size()-1].substr(1) + vec[vec.size()-1][0]);
		}
		sort(vec.begin(), vec.end());
		vector<string>::iterator itr = find(vec.begin(), vec.end(), c);
		  if (itr != vec.end())
			  cout << itr - vec.begin();
	}
	//system("pause");
	return 0;
}

/*

//another code,
//this one uses non-contiguous structure
//std::list

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

string rot(string x){
	if(x.length() <= 1) return x;
	return x.substr(1) + x[0];
}

int main(){
	ifstream in("sorter.in");
	int n;
	in >> n;
	in.ignore(255, '\n');
	for(int t=0; t < n; t++){
		if(t) cout << endl;
		list<string> lst;
		string c;
		getline(in, c);
		int l = c.length();
		for(int i=0; i < l; i++){
			lst.push_back(c);
			cout<<i<<endl;
			c = rot(c);
		}
		lst.sort();
		list<string>::iterator itr = find(lst.begin(), lst.end(), c);
		list<string>::iterator i = lst.begin();
		int r = 0;
		while(i != itr){ i++; r++; }
		cout << r;
	}
	system("pause");
	return 0;
}

*/