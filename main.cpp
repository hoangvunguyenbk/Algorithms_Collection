#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<std::vector<int>> matrix;

void Rotate(matrix &v) {

	matrix temp(v[0].size(), std::vector<int>(v.size()));

	for(int i=0; i<v.size(); i++) {
		for(int j =0; j<v[0].size(); j++) {
			temp[j][temp[0].size() - i - 1] = v[i][j];
		}
	}

	v = temp; 
}

void Print(const matrix& v) {
	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<v[0].size(); j++) {
			cout << v[i] [j];
		}
		cout << endl;
	}
}

int main() {

	matrix m = {{1,2,3,4}, {4,5,6,7}, {7,8,9,10}};

	Rotate(m);

	Print(m);

	return 0;
}