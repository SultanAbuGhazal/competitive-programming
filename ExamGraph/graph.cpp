#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct course{
	string name;
	vector<string> students;
	course(string n) : name(n) {}
};

bool common(vector<string> a, vector<string> b){
	for (int i = 0; i < a.size(); i++)
		if(find(b.begin(), b.end(), a[i]) != b.end()) return true;
	return false;
}

bool comp(course a, course b){
	return a.name < b.name;
}

int main(){
	ifstream in("graph.in");
	ofstream out("graph.out");
	int N;
	in >> N;

	while (N != 0){
		vector<course> courses;
		vector<string> courses_list;
		for (int i = 0; i < N; i++){
			string s, c;
			in >> s >> c;
			vector<string>::iterator itr = find(courses_list.begin(), courses_list.end(), c);
			if (itr == courses_list.end()){ //course does not exist
				course temp(c);
				temp.students.push_back(s);
				courses_list.push_back(c);
				courses.push_back(temp);
			}
			else{ //course exists
				vector<course>::iterator it = courses.begin() + (itr - courses_list.begin());
				it->students.push_back(s);
			}
			
		}
		cout << "here" << endl;

		sort(courses.begin(), courses.end(), comp);

		bool **mat = new bool *[courses.size()];
		int len = courses.size();
		for (int i = 0; i < len; i++){
			mat[i] = new bool[len];
			for (int j = 0; j < len; j++){
				mat[i][j] = 0;
			}
		}

		for (int i = 0; i < len; i++){ //very slow here
			for (int j = 0; j < len; j++){
				if (common(courses[i].students, courses[j].students) && j != i){
					mat[i][j] = true;
				}
				cout << '\r' << i << " " << j;
			}

		}

		for (int i = 0; i < len; i++){
			for (int j = 0; j < len; j++){
				cout << mat[i][j] << " ";
				out << mat[i][j] << " ";
			}
			out << endl;
			cout << endl;
		}


		/*
		for (int i = 0; i < courses.size(); i++){
			cout << courses[i].name << ": ";
			for (int j = 0; j < courses[i].students.size(); j++){
				cout << courses[i].students[j] << " ";
			}
			cout << endl;
		}
		*/
		in >> N;
	}

	system("pause");
	return 0;
}