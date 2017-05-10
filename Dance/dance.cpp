#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

struct dancer{
	int x, y, energy;
	dancer(){}
	dancer(int a, int b, int c) : x(a), y(b), energy(c) {}
	bool operator==(dancer a){
		return (a.x==x) && (a.y==y) && (a.energy==energy);
	}
};
bool comp(dancer a, dancer b){
	return (a.x==b.x) && (a.y==b.y) && (a.energy==b.energy);
};
struct sensor{
	int x, y, radius;
	sensor(int a, int b, int c) : x(a), y(b), radius(c) {}
	bool inRange(dancer a){
		if( (pow(a.x - x, 2) + pow(a.y - y, 2)) <= pow(radius, 2) ) return true;
		return false;
	}
};

int main(){
	ifstream in("dance.in");
	int N;
	in >> N;

	for(int n=0; n < N; n++){//iterating test cases
		vector<dancer> dancers;
		vector<sensor> sensors;
		int D, S;
		double K;
		in >> D >> S >> K;
		for(int d=0; d < D; d++){//iterating dancers
			int x, y, e;
			in >> x >> y >> e;
			dancer temp(x, y, e);
			dancers.push_back(temp);
		}
		for(int s=0; s < S; s++){//iterating sensors
			int x, y, r;
			in >> x >> y >> r;
			sensor temp(x, y, r);
			sensors.push_back(temp);
		}
		// **all data filled in vectors**	
		
		vector<dancer> effective_dancers;
		vector<dancer> unique_effective_dancers;
		int s_count = sensors.size();
		int d_count = dancers.size();
		for(int s=0; s < s_count; s++){
			for(int d=0; d < d_count; d++){
				if(sensors[s].inRange(dancers[d])) effective_dancers.push_back(dancers[d]);
			}
		}

		double energy_sum = 0;
		for(int d=0; d < effective_dancers.size(); d++){
			if(find(unique_effective_dancers.begin(), unique_effective_dancers.end(), effective_dancers[d]) == unique_effective_dancers.end()){
				unique_effective_dancers.push_back(effective_dancers[d]);
				energy_sum += effective_dancers[d].energy;
			}
		}
		cout << setprecision(2) << fixed << n+1 << ". " << energy_sum*K << endl;
	}

	system("pause");
	return 0;
}