#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubbleSort(std::vector<int>& vec){
	for(int i=0; i<vec.size(); i++){
		for(int j=0; j<vec.size(); j++){
			if(vec[i]<vec[j]){
				std::swap(vec[i], vec[j]);
			}
		}
	}
}
void printVec(std::vector<int> vec){
	for(int i=0; i<vec.size(); i++){
		cout << vec[i] << '\t';
	}
	cout << endl;
}

int main(){
	std::vector<int> myVec({4,3,2,1,4,254,567,78,4534});
	bubbleSort(myVec);
	printVec(myVec);
	myVec.clear();
	return 0;
}
