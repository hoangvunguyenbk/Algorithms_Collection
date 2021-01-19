#include <iostream>
#include <vector>

using namespace std;

void insertionSort(std::vector<int>& vec){
	for(int i=1; i<vec.size(); i++){
		int hole = i;
		int value = vec[i];
		while(hole>0 && vec[hole-1]>value){
			vec[hole]=vec[hole-1]; // insert vec[hole-1] at index hole
			hole--; //decrease hole value
		}
		vec[hole]=value; //insert value after fulfill
	}
}

void printVec(std::vector<int> vec){
	for(int i=0; i<vec.size(); i++){
		std::cout << vec[i] << '\t';
	}
	std::cout << endl;
}

int main(){
	std::vector<int> myVec({-1,150,190, -1, -1,170,120,200});
	insertionSort(myVec);
	printVec(myVec);
	myVec.clear();
	return 0;
}
